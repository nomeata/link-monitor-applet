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

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <glib/gi18n.h>
#include <gnome.h>
#include "lm-applet.h"
#include "lm-shell.h"
#include "lm-util.h"

static LMSocket *
create_socket (int domain, int protocol)
{
  LMSocket *sock;

  sock = g_new0(LMSocket, 1);

  sock->domain = domain;
  sock->desc = socket(domain, SOCK_RAW, protocol);
  if (sock->desc < 0)
    sock->init_error = g_strdup(g_strerror(errno));

  return sock;
}

static GSList *
create_sockets (void)
{
  GSList *sockets = NULL;

  sockets = g_slist_append(sockets, create_socket(AF_INET, IPPROTO_ICMP));
#if WITH_IPV6
  sockets = g_slist_append(sockets, create_socket(AF_INET6, IPPROTO_ICMPV6));
#endif

  return sockets;
}

int
main (int argc, char **argv)
{
  GSList *sockets;
  GdkPixbuf *icon;

  /* create sockets as root */
  sockets = create_sockets();

  /* we don't need root privileges anymore */
  setuid(getuid());

  g_log_set_fatal_mask(NULL, G_LOG_LEVEL_CRITICAL);

#ifdef ENABLE_NLS
  bindtextdomain(GETTEXT_PACKAGE, GNOMELOCALEDIR);
  bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
  textdomain(GETTEXT_PACKAGE);
#endif

  /* translators: header capitalization */
  g_set_application_name(_("Link Monitor Applet"));

  g_thread_init(NULL);
  if (! g_thread_supported())
    /*
     * We can't use lm_error_dialog() because gtk_init() has not been
     * called yet.
     */
    g_critical("multi-threading is not available");
  gdk_threads_init();

  gnome_program_init(PACKAGE,
		     VERSION,
		     LIBGNOMEUI_MODULE,
		     argc,
		     argv,
		     /* translators: header capitalization */
		     GNOME_PARAM_HUMAN_READABLE_NAME, _("Link Monitor Applet"),
		     GNOME_CLIENT_PARAM_SM_CONNECT, FALSE,
		     GNOME_PROGRAM_STANDARD_PROPERTIES,
		     NULL);

  icon = lm_pixbuf_new(GNOMEPIXMAPSDIR G_DIR_SEPARATOR_S "link-monitor-applet.png");
  gtk_window_set_default_icon(icon);
  g_object_unref(icon);

  lm_shell_new(sockets);

  return lm_applet_factory_main();
}
