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
#include "jb.h"

#jb_include "lm-gdk-pixbuf-loader"
#jb_include "lm-geoip"
#jb_include "lm-glibc"

#define LM_WARNING_CFLAGS \
  "-Wall "				\
  "-Wformat-y2k "			\
  "-Wformat-security "			\
  "-Wno-unused-parameter "		\
  "-Wdeclaration-after-statement "	\
  "-Wendif-labels "			\
  "-Wpointer-arith "			\
  "-Wcast-align	"			\
  "-Waggregate-return "			\
  "-Wmissing-noreturn "			\
  "-Wmissing-format-attribute "		\
  "-Wpacked "				\
  "-Wredundant-decls "			\
  "-Wnested-externs "			\
  "-Winline "				\
  "-Wno-pointer-sign "			\
  "-Wshadow "

static const JBFeature *jb_features[] = {
  &jb_pkg_config_feature,
  &jb_gettext_feature,
  &jb_intltool_feature,
  &jb_gconf_feature,
  &jb_gnome_help_feature,
  &jb_gob2_feature
};

void
jb_package_init (void)
{
  JBVariableGroup *lm_features_group;

  /* by default, use the GNOME prefix */
  jb_set_prefix_from_program("gnome-open");

  /*
   * At the time of this writing, gob2 2.0.16 is not yet
   * released. What is required is gob2 2.0.15 + my patches (see the
   * gob mailing list), which should eventually become gob2 2.0.16.
   */
  jb_variable_set_string("gob2-minversion", "2.0.16");

  lm_features_group = jb_variable_add_group("Link Monitor Applet features");

  jb_variable_add_bool("ipv6",
		       "enable IPv6 support",
		       lm_features_group,
		       JB_VARIABLE_C_DEFINE,
		       TRUE);
  jb_variable_add_bool("geoip",
		       "enable GeoIP support",
		       lm_features_group,
		       JB_VARIABLE_C_DEFINE,
		       TRUE);

  jb_variable_add_bool("compile-warnings", NULL, NULL, 0, FALSE);
  jb_variable_add_bool("debug", NULL, NULL, 0, TRUE);
  jb_variable_add_bool("suid-root", NULL, NULL, 0, TRUE);
}

static void
report_invalid_prefix (void)
{
  const char *gnome_prefix;

  jb_check_gnome_prefix();

  gnome_prefix = jb_variable_get_string("gnome-prefix");
  if (*gnome_prefix == '\0')
    jb_warning_expand("$human-package must be installed in the same prefix as GNOME, but the GNOME prefix could not be found. $human-package might be inoperable.", NULL);
  else
    {
      char *prefix;

      prefix = jb_variable_expand("$prefix", NULL);
      if (strcmp(prefix, gnome_prefix))
	jb_warning_expand("the $human-package prefix ($prefix) is different from the GNOME prefix ($gnome-prefix). $human-package will be inoperable. Unless you know what you are doing, please run \"./jb configure prefix=$gnome-prefix\".", NULL);
      g_free(prefix);
    }
}

void
jb_package_configure (void)
{
  if (lm_glibc_check())
    {
      /*
       * We need -std=c99 for lround(), ...
       * We need _BSD_SOURCE (which requires -lbsd-compat) for struct icmp, ...
       * We need _POSIX_C_SOURCE for struct addrinfo, clock_gettime(), ...
       */
      jb_variable_set_string("glibc-cflags", "-std=c99 -D_BSD_SOURCE -D_POSIX_C_SOURCE=199309L");
      jb_variable_set_string("glibc-cppflags", "");
      // jb_variable_set_string("glibc-ldflags", "-lbsd-compat");
      jb_variable_set_string("glibc-ldflags", "");
    }
  else
    {
      jb_variable_set_string("glibc-cflags", "");
      jb_variable_set_string("glibc-cppflags", "");
      jb_variable_set_string("glibc-ldflags", "");
    }

  if (jb_check_functions("clock_gettime", "rt"))
    jb_variable_set_string("clock-gettime-ldflags", "-lrt");
  else if (jb_check_functions("clock_gettime", NULL))
    jb_variable_set_string("clock-gettime-ldflags", "");
  else
    jb_error("clock_gettime() found neither in librt nor in libc");

  jb_check_reentrant_dns_resolver();

  jb_require_packages("GNOME", "gnome", "gthread-2.0 gtk+-3.0 libpanelapplet-4.0 gmodule-2.0");

  if (jb_variable_get_bool("geoip"))
    {
      if (lm_geoip_check())
	{
	  if (! lm_gdk_pixbuf_loader_check("art/flags/fr.svg", "image/svg+xml"))
	    jb_warning("GTK+ cannot load image/svg+xml images, country flags will not be displayed");
	}
      else
	{
	  jb_warning("disabling option \"geoip\" since GeoIP was not found");
	  jb_variable_set_bool("geoip", FALSE);
	}
    }

  report_invalid_prefix();
}

void
jb_package_add_resources (void)
{
  JBGroup *group;
  JBObject *object;

  if (jb_variable_get_bool("compile-warnings"))
    jb_compile_options_add_cflags(&jb_compile_options, LM_WARNING_CFLAGS " -Werror");

  if (! jb_variable_get_bool("debug"))
    jb_compile_options_add_cflags(&jb_compile_options, "-DG_DISABLE_ASSERT -DG_DISABLE_CHECKS -DG_DISABLE_CAST_CHECKS");

  jb_compile_options_add_gob2flags(&jb_compile_options, "--exit-on-warn");

  /*** art *******************************************************************/

  group = jb_group_new("art");

  jb_group_add_data_file(group, "link-monitor-applet.png", "$datadir/pixmaps");

  if (jb_variable_get_bool("geoip"))
    jb_group_add_data_files_pattern(group, "flags/*.svg", "$pkgdatadir/flags");

  jb_group_add(group);

  /*** data ******************************************************************/

  group = jb_group_new("data");

  jb_group_add_resource(group, JB_GROUP_RESOURCE(jb_template_new("LinkMonitorApplet.panel-applet.in.in")));
  jb_group_add_panel_applet(group, "LinkMonitorApplet.panel-applet.in");
  jb_group_add_resource(group, JB_GROUP_RESOURCE(jb_template_new("LinkMonitorApplet.service.in.in")));
  jb_group_add_dbus_service(group, "LinkMonitorApplet.service.in");

  jb_group_add_gconf_schemas(group, "link-monitor-applet.schemas.in");

  jb_group_add(group);

  /*** help ******************************************************************/

  group = jb_group_new("help");

  jb_group_add_resource(group, JB_GROUP_RESOURCE(jb_gnome_help_new("C", "documentation-license.xml software-license.xml")));

  jb_group_add(group);

  /*** jbsrc *****************************************************************/

  group = jb_group_new("jbsrc");

  jb_group_add_dist_files(group,
			  "lm-gdk-pixbuf-loader-test.c",
			  "lm-glibc-test.c",
			  NULL);

  jb_group_add(group);

  /*** po ********************************************************************/

  group = jb_group_new("po");

  jb_group_add_translations(group, "bg fr it");

  jb_group_add(group);

  /*** src *******************************************************************/

  group = jb_group_new("src");

  object = JB_OBJECT(jb_program_new("link-monitor-applet"));

  jb_install_options_set_installdir(&object->install_options, "$libexecdir");

  if (jb_variable_get_bool("suid-root"))
    {
      jb_install_options_set_owner(&object->install_options, "root");
      jb_install_options_set_extra_mode(&object->install_options, S_ISUID);
    }

  jb_compile_options_add_string_defines(&object->compile_options,
					"PACKAGE", "$package", 
					"VERSION", "$version",
					"GETTEXT_PACKAGE", "$package",
					"PREFIX", "$prefix",
					"SYSCONFDIR", "$sysconfdir",
					"DATADIR", "$datadir",
					"PKGDATADIR", "$pkgdatadir",
					"LIBDIR", "$libdir",
					"GNOMELOCALEDIR", "$datadir/locale",
					"GNOMEPIXMAPSDIR", "$datadir/pixmaps",
					NULL);

  /*
   * We need --export-dynamic because because libglade needs to
   * resolve symbols from our own binary in order to autoconnect
   * signal handlers.
   */
  jb_compile_options_add_ldflags(&object->compile_options, "-Wl,--export-dynamic");
    
  jb_compile_options_add_ldflags(&object->compile_options, "-lm");

  jb_compile_options_add_package(&object->compile_options, "glibc");
  jb_compile_options_add_ldflags(&object->compile_options, "$clock-gettime-ldflags");
  jb_compile_options_add_package(&object->compile_options, "gettext");
  jb_compile_options_add_package(&object->compile_options, "gnome");

  if (jb_variable_get_bool("geoip"))
    jb_compile_options_add_package(&object->compile_options, "geoip");

  jb_object_add_sources(object,
			"LM:About:Dialog",
			"LM:Applet",
			"LM:Bar:Graph",
			"LM:Cell:Renderer:Color",
			"LM:Data:Set",
			"LM:Dialog",
			"LM:Framed:Image",
			"LM:Host",
			"LM:Host:Frontend",
			"LM:Host:View",
			"LM:Line:Graph",
			"LM:Line:Graph:Icon",
			"LM:Preferences:Dialog",
			"LM:Shell",
			"LM:Tooltips",
			"lm-color-generator",
			"lm-decls.h",
			"lm-icmp",
			"lm-main.c",
			"lm-non-linear-range",
			"lm-util",
			NULL);

  jb_group_add_resource(group, JB_GROUP_RESOURCE(object));

  jb_group_add(group);

  /*** ui ********************************************************************/

  group = jb_group_new("ui");

  jb_group_add_data_files(group,
			  "preferences-dialog.ui", "$pkgdatadir",
			  "lm-style.css", "$pkgdatadir",
			  "GNOME_LinkMonitorApplet.xml", "$datadir/gnome-2.0/ui",
			  NULL);

  jb_group_add(group);
}

JB_MAIN("link-monitor-applet", "3.0", "Link Monitor Applet")
