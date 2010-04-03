/* Generated by GOB (v2.0.15)   (do not edit directly) */

#ifndef __LM_TOOLTIPS_PRIVATE_H__
#define __LM_TOOLTIPS_PRIVATE_H__

#include "lm-tooltips.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#line 32 "src/lm-tooltips.gob"

typedef struct
{
  LMTooltips	*self;
  GtkWidget	*widget;
  GtkWidget	*tip_widget;
} TooltipsData;

#line 23 "lm-tooltips-private.h"
struct _LMTooltipsPrivate {
#line 76 "src/lm-tooltips.gob"
	GtkWidget * window;
#line 77 "src/lm-tooltips.gob"
	TooltipsData * active_data;
#line 78 "src/lm-tooltips.gob"
	GSList * data_list;
#line 80 "src/lm-tooltips.gob"
	gboolean use_sticky_delay;
#line 81 "src/lm-tooltips.gob"
	GTimeVal last_popdown;
#line 82 "src/lm-tooltips.gob"
	unsigned int timeout_id;
#line 84 "src/lm-tooltips.gob"
	int border_width;
#line 39 "lm-tooltips-private.h"
};

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
