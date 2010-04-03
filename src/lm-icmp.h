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

#ifndef _LM_ICMP_H
#define _LM_ICMP_H

#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <glib.h>
#include "lm-shell.h"
#include "lm-util.h"

typedef struct
{
  const char	*error;		/* NULL if it's an echo reply */
  uint8_t	host_id;
  uint8_t	seq;
  LMTimeSpan	received_time;
} LMICMPReply;

gboolean lm_icmp_send_echo_request (const LMSocket *sock,
				    const struct addrinfo *addrinfo,
				    uint8_t host_id,
				    uint8_t seq,
				    GError **err);

gboolean lm_icmp_reply_get (const LMSocket *sock, LMICMPReply *reply);


#endif /* _LM_ICMP_H */
