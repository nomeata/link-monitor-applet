#include <gdk-pixbuf/gdk-pixbuf.h>

int main() {
  g_type_init();
  if (gdk_pixbuf_new_from_file(LM_GDK_PIXBUF_LOADER_FILE, NULL))
    exit(0);
  else
    exit(1);
}
