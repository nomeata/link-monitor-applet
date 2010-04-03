/*
 * Link Monitor Applet
 * Copyright (C) 2004-2008 Jean-Yves Lefort <jylefort@brutele.be>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#if WITH_IPV6
#include <netinet/ip6.h>
#include <netinet/icmp6.h>
#endif /* WITH_IPV6 */
#include <glib.h>
#include <glib/gi18n.h>
#include "lm-icmp.h"
#include "lm-util.h"

/* receive buffer lengths */
#define MAX_IP_PACKET_LEN	IP_MAXPACKET
#define MAX_ICMP6_PACKET_LEN	2352	/* from FreeBSD's ping6.c (packlen when F_VERBOSE is set) */

/* minimum packet lengths (type 1, code 1, checksum 2, type-specific 4)*/
#define ICMP_PACKET_LEN		8
#define ICMP6_PACKET_LEN	8

/* this ICMPv6 code is not defined by all platforms */
#ifndef ICMP6_DST_UNREACH_BEYONDSCOPE
#define ICMP6_DST_UNREACH_BEYONDSCOPE	2	/* RFC 3542 */
#endif

static uint16_t
compose_icmp_seq (uint8_t host_id, uint8_t seq)
{
  return ((uint16_t) host_id << 8) | seq;
}

static void
decompose_icmp_seq (uint16_t iseq, uint8_t *host_id, uint8_t *seq)
{
  g_return_if_fail(host_id != NULL);
  g_return_if_fail(seq != NULL);

  *host_id = iseq >> 8;
  *seq = iseq & 0xFF;
}

/*
 * Compute an ICMP checksum (based on in_cksum() from FreeBSD's ping.c).
 *
 * Copyright (c) 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Mike Muuss.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
static uint16_t
compute_icmp_checksum (const uint16_t *addr, int len)
{
  int nleft, sum;
  const uint16_t *w;
  union {
    uint16_t	us;
    uint8_t	uc[2];
  } last;
  uint16_t answer;

  g_return_val_if_fail(addr != NULL, 0);

  nleft = len;
  sum = 0;
  w = addr;

  /*
   * Our algorithm is simple, using a 32 bit accumulator (sum), we add
   * sequential 16 bit words to it, and at the end, fold back all the
   * carry bits from the top 16 bits into the lower 16 bits.
   */
  while (nleft > 1)
    {
      sum += *w++;
      nleft -= 2;
    }

  /* mop up an odd byte, if necessary */
  if (nleft == 1)
    {
      last.uc[0] = *(uint8_t *) w;
      last.uc[1] = 0;
      sum += last.us;
    }

  /* add back carry outs from top 16 bits to low 16 bits */
  sum = (sum >> 16) + (sum & 0xffff);	/* add hi 16 to low 16 */
  sum += (sum >> 16);			/* add carry */
  answer = ~sum;			/* truncate to 16 bits */

  return answer;
}

gboolean
lm_icmp_send_echo_request (const LMSocket *sock,
			   const struct addrinfo *addrinfo,
			   uint8_t host_id,
			   uint8_t seq,
			   GError **err)
{
  char buf[MAX(ICMP_PACKET_LEN, ICMP6_PACKET_LEN)];
  size_t packet_len;
  ssize_t sent_len;

  g_return_val_if_fail(sock != NULL, FALSE);
  g_return_val_if_fail(sock->init_error == FALSE, FALSE);
  g_return_val_if_fail(addrinfo != NULL, FALSE);

  if (addrinfo->ai_family == AF_INET)
    {
      struct icmp *icmp;

      packet_len = ICMP_PACKET_LEN;
      icmp = (struct icmp *) buf;
      icmp->icmp_type = ICMP_ECHO;
      icmp->icmp_code = 0;
      icmp->icmp_id = g_htons(lm_shell->icmp_ident);
      icmp->icmp_seq = g_htons(compose_icmp_seq(host_id, seq));
      icmp->icmp_cksum = 0;
      icmp->icmp_cksum = compute_icmp_checksum((uint16_t *) icmp, packet_len);
    }
#if WITH_IPV6
  else if (addrinfo->ai_family == AF_INET6)
    {
      struct icmp6_hdr *icmp6;

      packet_len = ICMP6_PACKET_LEN;
      icmp6 = (struct icmp6_hdr *) buf;
      icmp6->icmp6_type = ICMP6_ECHO_REQUEST;
      icmp6->icmp6_code = 0;
      icmp6->icmp6_id = g_htons(lm_shell->icmp_ident);
      icmp6->icmp6_seq = g_htons(compose_icmp_seq(host_id, seq));
      /* icmp_cksum is filled in by the kernel */
    }
#endif /* WITH_IPV6 */
  else
    g_assert_not_reached();

 again:
  sent_len = sendto(sock->desc, buf, packet_len, 0, addrinfo->ai_addr, addrinfo->ai_addrlen);
  if (sent_len < 0)
    {
      if (errno == EINTR)
	goto again;
      else
	{
	  g_set_error(err, 0, 0, "%s", g_strerror(errno));
	  return FALSE;
	}
    }
  else if (sent_len != packet_len)
    {
      g_set_error(err, 0, 0, _("could not send whole packet"));
      return FALSE;
    }

  return TRUE;
}

static struct icmp *
get_icmp_packet (gpointer buf, int buf_len, int *icmp_len)
{
  struct ip *ip_packet;
  int header_len;
  int _icmp_len;

  g_return_val_if_fail(buf != NULL, NULL);
  g_return_val_if_fail(buf_len >= 0, NULL);

  if (buf_len < sizeof(struct ip *))
    return NULL;

  ip_packet = (struct ip *) buf;

  /*
   * Check the protocol, in case this is an IP header embedded in an
   * ICMP error message (in which case the IP packet which caused the
   * message is not necessarily an ICMP message).
   */
  if (ip_packet->ip_p != IPPROTO_ICMP)
    return NULL;

  header_len = ip_packet->ip_hl * 4;
  _icmp_len = buf_len - header_len;

  if (_icmp_len < ICMP_PACKET_LEN)
    return NULL;

  /* success */

  if (icmp_len)
    *icmp_len = _icmp_len;

  return (struct icmp *) ((char *) buf + header_len);
}

static const char *
get_description4 (int icmp_type, int icmp_code)
{
  switch (icmp_type)
    {
    case ICMP_UNREACH:
      switch (icmp_code)
	{
	case ICMP_UNREACH_NET:			return _("destination network unreachable");
	case ICMP_UNREACH_HOST:			return _("destination host unreachable");
	case ICMP_UNREACH_PROTOCOL:		return _("destination protocol unreachable");
	case ICMP_UNREACH_PORT:			return _("destination port unreachable");
	case ICMP_UNREACH_NEEDFRAG:		return _("fragmentation needed and DF set");
	case ICMP_UNREACH_SRCFAIL:		return _("source route failed");
	case ICMP_UNREACH_FILTER_PROHIB:	return _("communication prohibited by filter");
	default:				return _("destination unreachable, unknown ICMP code");
	}
    case ICMP_TIMXCEED:
      switch (icmp_code)
	{
	case ICMP_TIMXCEED_INTRANS:		return _("time to live exceeded");
	case ICMP_TIMXCEED_REASS:		return _("fragment reassembly time exceeded");
	default:				return _("time exceeded, unknown ICMP code");
	}
    case ICMP_PARAMPROB:			return _("parameter problem");
    case ICMP_SOURCEQUENCH:			return _("source quench");
    case ICMP_REDIRECT:
      switch (icmp_code)
	{
	case ICMP_REDIRECT_NET:			return _("redirect network");
	case ICMP_REDIRECT_HOST:		return _("redirect host");
	case ICMP_REDIRECT_TOSNET:		return _("redirect type of service and network");
	case ICMP_REDIRECT_TOSHOST:		return _("redirect type of service and host");
	default:				return _("redirect, unknown ICMP code");
	}
    default:
      g_assert_not_reached();
      return NULL;
    }
}

#if WITH_IPV6
static struct icmp6_hdr *
get_icmp6_packet (gpointer buf, int buf_len)
{
  struct ip6_hdr *ip6_packet;

  g_return_val_if_fail(buf != NULL, NULL);
  g_return_val_if_fail(buf_len >= 0, NULL);

  if (buf_len < sizeof(struct ip6_hdr) + ICMP6_PACKET_LEN)
    return FALSE;

  ip6_packet = (struct ip6_hdr *) buf;

  /* keep it simple, assume the ICMPv6 header is the first one */
  if (ip6_packet->ip6_nxt != IPPROTO_ICMPV6)
    return FALSE;

  return (struct icmp6_hdr *) &ip6_packet[1];
}

static const char *
get_description6 (int icmp6_type, int icmp6_code)
{
  switch (icmp6_type)
    {
    case ICMP6_DST_UNREACH:
      switch (icmp6_code)
	{
	case ICMP6_DST_UNREACH_NOROUTE:		return _("no route to destination");
	case ICMP6_DST_UNREACH_ADMIN:		return _("destination administratively unreachable");
	case ICMP6_DST_UNREACH_BEYONDSCOPE:	return _("destination unreachable beyond scope");
	case ICMP6_DST_UNREACH_ADDR:		return _("destination host unreachable");
	case ICMP6_DST_UNREACH_NOPORT:		return _("destination port unreachable");
	default:				return _("destination unreachable, unknown ICMPv6 code");
	}
    case ICMP6_PACKET_TOO_BIG:			return _("packet too big");
    case ICMP6_TIME_EXCEEDED:
      switch (icmp6_code)
	{
	case ICMP6_TIME_EXCEED_TRANSIT:		return _("time to live exceeded");
	case ICMP6_TIME_EXCEED_REASSEMBLY:	return _("fragment reassembly time exceeded");
	default:				return _("time exceeded, unknown ICMPv6 code");
	}
    case ICMP6_PARAM_PROB:
      switch (icmp6_code)
	{
	case ICMP6_PARAMPROB_HEADER:		return _("parameter problem: erroneous header");
	case ICMP6_PARAMPROB_NEXTHEADER:	return _("parameter problem: unknown next header");
	case ICMP6_PARAMPROB_OPTION:		return _("parameter problem: unrecognized option");
	default:				return _("parameter problem, unknown ICMPv6 code");
	}
    default:
      g_assert_not_reached();
      return NULL;
    }
}
#endif /* WITH_IPV6 */

static void
set_reply (LMICMPReply *reply, const char *error, uint16_t iseq)
{
  reply->received_time = lm_get_ticks();
  reply->error = error;
  decompose_icmp_seq(g_ntohs(iseq), &reply->host_id, &reply->seq);
}

/* returns TRUE if reply was filled */
gboolean
lm_icmp_reply_get (const LMSocket *sock, LMICMPReply *reply)
{
  char buf[MAX(MAX_IP_PACKET_LEN, MAX_ICMP6_PACKET_LEN)];
  ssize_t nbytes;

  g_return_val_if_fail(sock != NULL, FALSE);
  g_return_val_if_fail(sock->init_error == FALSE, FALSE);
  g_return_val_if_fail(reply != NULL, FALSE);

 again:
  nbytes = recvfrom(sock->desc, buf, sizeof(buf), 0, NULL, NULL);
  if (nbytes < 0)
    {
      if (errno == EINTR)
	goto again;
      else
	return FALSE;
    }

  if (sock->domain == AF_INET)
    {
      struct icmp *icmp;
      int icmp_len;

      icmp = get_icmp_packet(buf, nbytes, &icmp_len);
      if (! icmp)
	return FALSE;

      if (compute_icmp_checksum((uint16_t *) icmp, icmp_len))
	return FALSE;		/* wrong ICMP checksum */

      switch (icmp->icmp_type)
	{
	case ICMP_ECHOREPLY:
	  if (g_ntohs(icmp->icmp_id) == lm_shell->icmp_ident)
	    {
	      set_reply(reply, NULL, icmp->icmp_seq);
	      return TRUE;
	    }
	  break;

	case ICMP_UNREACH:
	case ICMP_TIMXCEED:
	case ICMP_PARAMPROB:
	case ICMP_SOURCEQUENCH:
	case ICMP_REDIRECT:
	  {
	    gpointer orig_ip_buf;
	    int orig_ip_buf_len;
	    struct icmp *orig_icmp;

	    orig_ip_buf = (char *) icmp + ICMP_PACKET_LEN;
	    orig_ip_buf_len = icmp_len - ICMP_PACKET_LEN;

	    orig_icmp = get_icmp_packet(orig_ip_buf, orig_ip_buf_len, NULL);
	    if (orig_icmp
		&& orig_icmp->icmp_type == ICMP_ECHO
		&& g_ntohs(orig_icmp->icmp_id) == lm_shell->icmp_ident)
	      {
		/*
		 * Note that we really mean to use the type and code
		 * of the error ICMP packet, not of the original
		 * packet (there is no typo).
		 */
		set_reply(reply, get_description4(icmp->icmp_type, icmp->icmp_code), orig_icmp->icmp_seq);
		return TRUE;
	      }
	  }
	  break;
	}
    }
#if WITH_IPV6
  else if (sock->domain == AF_INET6)
    {
      struct icmp6_hdr *icmp6;

      if (nbytes < ICMP6_PACKET_LEN)
	return FALSE;

      icmp6 = (struct icmp6_hdr *) buf;

      switch (icmp6->icmp6_type)
	{
	case ICMP6_ECHO_REPLY:
	  if (g_ntohs(icmp6->icmp6_id) == lm_shell->icmp_ident)
	    {
	      set_reply(reply, NULL, icmp6->icmp6_seq);
	      return TRUE;
	    }
	  break;

	case ICMP6_DST_UNREACH:
	case ICMP6_PACKET_TOO_BIG:
	case ICMP6_TIME_EXCEEDED:
	case ICMP6_PARAM_PROB:
	  {
	    gpointer orig_ip6_buf;
	    int orig_ip6_buf_len;
	    struct icmp6_hdr *orig_icmp6;

	    orig_ip6_buf = (char *) icmp6 + ICMP6_PACKET_LEN;
	    orig_ip6_buf_len = nbytes - ICMP6_PACKET_LEN;

	    orig_icmp6 = get_icmp6_packet(orig_ip6_buf, orig_ip6_buf_len);
	    if (orig_icmp6
		&& orig_icmp6->icmp6_type == ICMP6_ECHO_REQUEST
		&& g_ntohs(orig_icmp6->icmp6_id) == lm_shell->icmp_ident)
	      {
		/*
		 * Note that we really mean to use the type and code
		 * of the error ICMP packet, not of the original
		 * packet (there is no typo).
		 */
		set_reply(reply, get_description6(icmp6->icmp6_type, icmp6->icmp6_code), orig_icmp6->icmp6_seq);
		return TRUE;
	      }
	  }
	  break;
	}
    }
#endif /* WITH_IPV6 */
  else
    g_assert_not_reached();

  return FALSE;
}
