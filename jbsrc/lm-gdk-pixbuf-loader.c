#include "jb.h"

gboolean
lm_gdk_pixbuf_loader_check (const char *sample_image, const char *mime_type)
{
  gboolean result;
  char *cppflags;

  if (! jb_check_packages("GdkPixbuf", "gdk-pixbuf", "gdk-pixbuf-2.0"))
    return FALSE;

  jb_message_checking("if GTK+ can load %s images", mime_type);

  cppflags = g_strdup_printf("-DLM_GDK_PIXBUF_LOADER_FILE=\"\\\"%s\\\"\"", sample_image);
  result = jb_test_run("jbsrc/lm-gdk-pixbuf-loader-test.c",
		       jb_variable_get_string("gdk-pixbuf-cflags"),
		       cppflags,
		       jb_variable_get_string("gdk-pixbuf-ldflags"));
  g_free(cppflags);

  jb_message_result_bool(result);

  return result;
}
