#include "jb.h"

gboolean
lm_geoip_check (void)
{
  if (jb_check_functions("GeoIP_new", "GeoIP"))
    {
      jb_variable_set_string("geoip-cflags", "");
      jb_variable_set_string("geoip-cppflags", "");
      jb_variable_set_string("geoip-ldflags", "-lGeoIP");

      return TRUE;
    }
  else
    return FALSE;
}
