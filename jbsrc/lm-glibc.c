#include "jb.h"

gboolean
lm_glibc_check (void)
{
  gboolean result;

  jb_message_checking("for the GNU C library");
  result = jb_test_compile("jbsrc/lm-glibc-test.c", NULL, NULL);
  jb_message_result_bool(result);

  return result;
}
