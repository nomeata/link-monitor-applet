/* Generated by GOB (v2.0.15)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 15

#define selfp (self->_priv)

#include "lm-data-set.h"

#include "lm-data-set-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 44 "src/lm-data-set.gob"

#include <string.h>
#include "lm-line-graph.h"
#include "lm-applet.h"
#include "lm-preferences-dialog.h"

#line 31 "lm-data-set.c"
/* self casting macros */
#define SELF(x) LM_DATA_SET(x)
#define SELF_CONST(x) LM_DATA_SET_CONST(x)
#define IS_SELF(x) LM_IS_DATA_SET(x)
#define TYPE_SELF LM_TYPE_DATA_SET
#define SELF_CLASS(x) LM_DATA_SET_CLASS(x)

#define SELF_GET_CLASS(x) LM_DATA_SET_GET_CLASS(x)

/* self typedefs */
typedef LMDataSet Self;
typedef LMDataSetClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
#line 0 "src/lm-data-set.gob"
static void lm_data_set_init (LMDataSet * o);
#line 50 "lm-data-set.c"
#line 0 "src/lm-data-set.gob"
static void lm_data_set_class_init (LMDataSetClass * c);
#line 53 "lm-data-set.c"
#line 67 "src/lm-data-set.gob"
static void lm_data_set_constructor (LMDataSet * self);
#line 56 "lm-data-set.c"
#line 77 "src/lm-data-set.gob"
static void lm_data_set_get_average (GArray * data, int start, int len, LMDataPoint * result);
#line 59 "lm-data-set.c"
#line 157 "src/lm-data-set.gob"
static void lm_data_set_average_points (GArray * data, int start, int len);
#line 62 "lm-data-set.c"
#line 172 "src/lm-data-set.gob"
static LMTimeSpan lm_data_set_get_min_interval_real (const LMNonLinearRangeBlock * block, LMTimeSpan age);
#line 65 "lm-data-set.c"
#line 193 "src/lm-data-set.gob"
static LMTimeSpan lm_data_set_get_min_interval (LMTimeSpan age);
#line 68 "lm-data-set.c"
#line 214 "src/lm-data-set.gob"
static void lm_data_set_consolidate_master_data (LMDataSet * self, LMTimeSpan now);
#line 71 "lm-data-set.c"
#line 315 "src/lm-data-set.gob"
static void lm_data_set_consolidate_display_data (LMDataSet * self, LMTimeSpan now);
#line 74 "lm-data-set.c"
#line 417 "src/lm-data-set.gob"
static void lm_data_set_add_data_point (LMDataSet * self, float roundtrip_time);
#line 77 "lm-data-set.c"

enum {
	PROP_0,
	PROP_APPLET
};

/* pointer to the class of our parent */
static GObjectClass *parent_class = NULL;

/* Short form macros */
#define self_get_average lm_data_set_get_average
#define self_average_points lm_data_set_average_points
#define self_get_min_interval_real lm_data_set_get_min_interval_real
#define self_get_min_interval lm_data_set_get_min_interval
#define self_consolidate_master_data lm_data_set_consolidate_master_data
#define self_consolidate_display_data lm_data_set_consolidate_display_data
#define self_add_data_point lm_data_set_add_data_point
#define self_add_live_data_point lm_data_set_add_live_data_point
#define self_add_dead_data_point lm_data_set_add_dead_data_point
#define self_get_display_data lm_data_set_get_display_data
#define self_clear_display_data lm_data_set_clear_display_data
#define self_new lm_data_set_new
GType
lm_data_set_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (LMDataSetClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) lm_data_set_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (LMDataSet),
			0 /* n_preallocs */,
			(GInstanceInitFunc) lm_data_set_init,
			NULL
		};

		type = g_type_register_static (G_TYPE_OBJECT, "LMDataSet", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((LMDataSet *)g_object_new(lm_data_set_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static LMDataSet * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static LMDataSet *
GET_NEW_VARG (const char *first, ...)
{
	LMDataSet *ret;
	va_list ap;
	va_start (ap, first);
	ret = (LMDataSet *)g_object_new_valist (lm_data_set_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static GObject *
___constructor (GType type, guint n_construct_properties, GObjectConstructParam *construct_properties)
{
#define __GOB_FUNCTION__ "LM:Data:Set::constructor"
	GObject *obj_self;
	LMDataSet *self;
	obj_self = G_OBJECT_CLASS (parent_class)->constructor (type, n_construct_properties, construct_properties);
	self = LM_DATA_SET (obj_self);
#line 67 "src/lm-data-set.gob"
	lm_data_set_constructor (self);
#line 153 "lm-data-set.c"
	return obj_self;
}
#undef __GOB_FUNCTION__


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "LM:Data:Set::finalize"
	LMDataSet *self G_GNUC_UNUSED = LM_DATA_SET (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#define master_data (self->_priv->master_data)
#define VAR master_data
	{
#line 56 "src/lm-data-set.gob"
	 g_array_free(VAR, TRUE); }
#line 172 "lm-data-set.c"
	memset(&master_data, 0, sizeof(master_data));
#undef VAR
#undef master_data
#define display_data (self->_priv->display_data)
#define VAR display_data
	{
#line 60 "src/lm-data-set.gob"
	
      if (VAR)
	g_array_free(VAR, TRUE);
    }
#line 184 "lm-data-set.c"
	memset(&display_data, 0, sizeof(display_data));
#undef VAR
#undef display_data
}
#undef __GOB_FUNCTION__

static void 
lm_data_set_init (LMDataSet * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "LM:Data:Set::init"
	o->_priv = G_TYPE_INSTANCE_GET_PRIVATE(o,LM_TYPE_DATA_SET,LMDataSetPrivate);
}
#undef __GOB_FUNCTION__
static void 
lm_data_set_class_init (LMDataSetClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "LM:Data:Set::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	g_type_class_add_private(c,sizeof(LMDataSetPrivate));

	parent_class = g_type_class_ref (G_TYPE_OBJECT);

	g_object_class->constructor = ___constructor;
	g_object_class->finalize = ___finalize;
	g_object_class->get_property = ___object_get_property;
	g_object_class->set_property = ___object_set_property;
    {
	GParamSpec   *param_spec;

	param_spec = g_param_spec_pointer
		("applet" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (g_object_class,
		PROP_APPLET,
		param_spec);
    }
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "LM:Data:Set::set_property"
{
	LMDataSet *self G_GNUC_UNUSED;

	self = LM_DATA_SET (object);

	switch (property_id) {
	case PROP_APPLET:
		{
#line 54 "src/lm-data-set.gob"
self->_priv->applet = g_value_get_pointer (VAL);
#line 243 "lm-data-set.c"
		}
		break;
	default:
/* Apparently in g++ this is needed, glib is b0rk */
#ifndef __PRETTY_FUNCTION__
#  undef G_STRLOC
#  define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
#endif
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
#undef __GOB_FUNCTION__

static void
___object_get_property (GObject *object,
	guint property_id,
	GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "LM:Data:Set::get_property"
{
	LMDataSet *self G_GNUC_UNUSED;

	self = LM_DATA_SET (object);

	switch (property_id) {
	case PROP_APPLET:
		{
#line 54 "src/lm-data-set.gob"
g_value_set_pointer (VAL, self->_priv->applet);
#line 274 "lm-data-set.c"
		}
		break;
	default:
/* Apparently in g++ this is needed, glib is b0rk */
#ifndef __PRETTY_FUNCTION__
#  undef G_STRLOC
#  define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
#endif
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
#undef __GOB_FUNCTION__



#line 67 "src/lm-data-set.gob"
static void 
lm_data_set_constructor (LMDataSet * self)
{
#line 295 "lm-data-set.c"
#define __GOB_FUNCTION__ "LM:Data:Set::constructor"
{
#line 68 "src/lm-data-set.gob"
	
    selfp->master_data = g_array_new(FALSE, FALSE, sizeof(LMDataPoint));
    /* display_data is created when needed */

    lm_g_object_connect(self, selfp->applet,
			"swapped-signal::notify::tooltip-graph-span", self_clear_display_data, self,
			NULL);
  }}
#line 307 "lm-data-set.c"
#undef __GOB_FUNCTION__

#line 77 "src/lm-data-set.gob"
static void 
lm_data_set_get_average (GArray * data, int start, int len, LMDataPoint * result)
{
#line 314 "lm-data-set.c"
#define __GOB_FUNCTION__ "LM:Data:Set::get_average"
#line 77 "src/lm-data-set.gob"
	g_return_if_fail (data != NULL);
#line 77 "src/lm-data-set.gob"
	g_return_if_fail (result != NULL);
#line 320 "lm-data-set.c"
{
#line 82 "src/lm-data-set.gob"
	
    int end;
    int i;
    LMTimeSpan liveness = 0;
    LMTimeSpan deadness = 0;

    g_return_if_fail(start >= 0);
    g_return_if_fail(len > 0);
    g_return_if_fail(start <= data->len - len); /* reordered to avoid overflow */

    end = start + len;

    /* compute the liveness and deadness span of the group */

    for (i = start + 1; i < end; i++)
      {
	const LMDataPoint *dp = &g_array_index(data, LMDataPoint, i);
	const LMDataPoint *prev = &g_array_index(data, LMDataPoint, i - 1);
	LMTimeSpan interval;

	interval = dp->timestamp - prev->timestamp;
	if (prev->roundtrip_time < 0)
	  deadness += interval;
	else
	  liveness += interval;
      }

    result->timestamp = 0;

    if (deadness > liveness)
      {
	/* deadness wins, the result is a dead data point */

	for (i = start; i < end; i++)
	  {
	    const LMDataPoint *dp = &g_array_index(data, LMDataPoint, i);

	    result->timestamp += dp->timestamp;
	  }

	result->roundtrip_time = -1;
      }
    else
      {
	float max_rtt = 0;
	double avg_rtt = 0;

	/* liveness wins, the result is the average round-trip time */

	for (i = start; i < end; i++)
	  {
	    const LMDataPoint *dp = &g_array_index(data, LMDataPoint, i);

	    if (dp->roundtrip_time > max_rtt)
	      max_rtt = dp->roundtrip_time;
	  }

	for (i = start; i < end; i++)
	  {
	    const LMDataPoint *dp = &g_array_index(data, LMDataPoint, i);

	    result->timestamp += dp->timestamp;

	    if (dp->roundtrip_time < 0)
	      avg_rtt += max_rtt;
	    else
	      avg_rtt += dp->roundtrip_time;
	  }

	result->roundtrip_time = avg_rtt / len;
      }

    result->timestamp /= len;
  }}
#line 397 "lm-data-set.c"
#undef __GOB_FUNCTION__

#line 157 "src/lm-data-set.gob"
static void 
lm_data_set_average_points (GArray * data, int start, int len)
{
#line 404 "lm-data-set.c"
#define __GOB_FUNCTION__ "LM:Data:Set::average_points"
#line 157 "src/lm-data-set.gob"
	g_return_if_fail (data != NULL);
#line 408 "lm-data-set.c"
{
#line 159 "src/lm-data-set.gob"
	
    LMDataPoint average;

    g_return_if_fail(start >= 0);
    g_return_if_fail(len > 0);
    g_return_if_fail(start <= data->len - len); /* reordered to avoid overflow */

    self_get_average(data, start, len, &average);

    g_array_remove_range(data, start, len);
    g_array_insert_val(data, start, average);
  }}
#line 423 "lm-data-set.c"
#undef __GOB_FUNCTION__

#line 172 "src/lm-data-set.gob"
static LMTimeSpan 
lm_data_set_get_min_interval_real (const LMNonLinearRangeBlock * block, LMTimeSpan age)
{
#line 430 "lm-data-set.c"
#define __GOB_FUNCTION__ "LM:Data:Set::get_min_interval_real"
#line 172 "src/lm-data-set.gob"
	g_return_val_if_fail (block != NULL, (LMTimeSpan )0);
#line 434 "lm-data-set.c"
{
#line 175 "src/lm-data-set.gob"
	
    LMTimeSpan step;
    LMTimeSpan segment;

    step = (LMTimeSpan) block->step * 1000;
    segment = (age / step) + 1;

    return segment * step / LM_LINE_GRAPH_AREA_WIDTH;
  }}
#line 446 "lm-data-set.c"
#undef __GOB_FUNCTION__

#line 193 "src/lm-data-set.gob"
static LMTimeSpan 
lm_data_set_get_min_interval (LMTimeSpan age)
{
#line 453 "lm-data-set.c"
#define __GOB_FUNCTION__ "LM:Data:Set::get_min_interval"
{
#line 195 "src/lm-data-set.gob"
	
    int i;

    for (i = 0; i < lm_preferences_dialog_num_tooltip_graph_span_blocks; i++)
      {
	const LMNonLinearRangeBlock *block = &lm_preferences_dialog_tooltip_graph_span_blocks[i];

	if (age < (LMTimeSpan) block->max * 1000)
	  return self_get_min_interval_real(block, age);
      }

    /*
     * Timestamp older than the maximum graph span: can happen since
     * we keep one such point in consolidate_master_data(). Use the
     * last block.
     */
    return self_get_min_interval_real(&lm_preferences_dialog_tooltip_graph_span_blocks[lm_preferences_dialog_num_tooltip_graph_span_blocks - 1], age);
  }}
#line 475 "lm-data-set.c"
#undef __GOB_FUNCTION__

#line 214 "src/lm-data-set.gob"
static void 
lm_data_set_consolidate_master_data (LMDataSet * self, LMTimeSpan now)
{
#line 482 "lm-data-set.c"
#define __GOB_FUNCTION__ "LM:Data:Set::consolidate_master_data"
#line 214 "src/lm-data-set.gob"
	g_return_if_fail (self != NULL);
#line 214 "src/lm-data-set.gob"
	g_return_if_fail (LM_IS_DATA_SET (self));
#line 488 "lm-data-set.c"
{
#line 216 "src/lm-data-set.gob"
	
    int i;
    LMTimeSpan max_span;
    LMTimeSpan min_timestamp;

    /*
     * The consolidation algorithm ensures that there will be just
     * enough data points to display at most one point per horizontal
     * pixel, regardless of the graph span.
     *
     * The theoretical [1] maximum number of data points can be
     * approximated [2] with the following expression:
     *
     *   nb    bh/bs
     *   E  (   E     (w / x) )
     *  b=1   x=bl/bs
     *
     * where:
     *
     *    w is LM_LINE_GRAPH_AREA_WIDTH
     *   nb is G_N_ELEMENTS(lm_preferences_dialog_tooltip_graph_span_blocks)
     *   bl is lm_preferences_dialog_tooltip_graph_span_blocks[b - 1].min
     *   bh is lm_preferences_dialog_tooltip_graph_span_blocks[b - 1].max
     *   bs is lm_preferences_dialog_tooltip_graph_span_blocks[b - 1].step
     *
     * Using the values that the variables involved in the above
     * expression have at the time of this writing, the maximum number
     * of data points is:
     *
     *       6            10           12           24
     *       E (w / x) +  E (w / x) +  E (w / x) +  E (w / x)
     *      x=1          x=2          x=3          x=2
     *
     *       7
     *   +   E (w / x) = 5092.6892
     *      x=2
     *
     * That is, about 5092 LMDataPoint structures (61104 bytes on most
     * platforms) for one week worth of data.
     *
     * [1] It is theoretical since it represents the number of data
     * points produced when the consolidation function is run only
     * once on a full, evenly distributed data set. In practice, since
     * the data set shifts constantly and is not evenly distributed,
     * the maximum number of points will be much lower than this.
     *
     * [2] It is an approximation since the algorithm works by
     * ensuring a minimum interval between two points, rather than a
     * maximum number of points for a given time period.
     */

    max_span = (LMTimeSpan) lm_preferences_dialog_tooltip_graph_span_blocks[lm_preferences_dialog_num_tooltip_graph_span_blocks - 1].max * 1000;
    min_timestamp = now - max_span;

    /*
     * Discard the points which are too old to be shown even with the
     * maximum graph span, except the last one (to have a line
     * entering the graph on the left).
     */
    for (i = 0; i < selfp->master_data->len; i++)
      {
	const LMDataPoint *dp = &g_array_index(selfp->master_data, LMDataPoint, i);

	if (dp->timestamp >= min_timestamp)
	  break;
      }
    if (i > 1)
      g_array_remove_range(selfp->master_data, 0, i - 1);

    for (i = 0; i < selfp->master_data->len; i++)
      {
	const LMDataPoint *dp = &g_array_index(selfp->master_data, LMDataPoint, i);
	LMTimeSpan min_interval;
	int group_end;
	int group_len;

	min_interval = self_get_min_interval(now - dp->timestamp);

	for (group_end = i + 1; group_end < selfp->master_data->len; group_end++)
	  {
	    const LMDataPoint *other_dp = other_dp = &g_array_index(selfp->master_data, LMDataPoint, group_end);
	    LMTimeSpan other_min_interval;

	    other_min_interval = self_get_min_interval(now - other_dp->timestamp);

	    /* end the group if the point is in a different data section */
	    if (other_min_interval != min_interval)
	      break;

	    if (other_dp->timestamp - dp->timestamp > min_interval)
	      break;
	  }

	group_len = group_end - i;
	if (group_len > 1)
	  self_average_points(selfp->master_data, i, group_len);
      }
  }}
#line 589 "lm-data-set.c"
#undef __GOB_FUNCTION__

#line 315 "src/lm-data-set.gob"
static void 
lm_data_set_consolidate_display_data (LMDataSet * self, LMTimeSpan now)
{
#line 596 "lm-data-set.c"
#define __GOB_FUNCTION__ "LM:Data:Set::consolidate_display_data"
#line 315 "src/lm-data-set.gob"
	g_return_if_fail (self != NULL);
#line 315 "src/lm-data-set.gob"
	g_return_if_fail (LM_IS_DATA_SET (self));
#line 602 "lm-data-set.c"
{
#line 317 "src/lm-data-set.gob"
	
    LMTimeSpan span;
    LMTimeSpan min_interval;
    LMTimeSpan min_timestamp;
    LMTimeSpan max_consolidation_timestamp;
    int i;

    g_return_if_fail(selfp->display_data != NULL);

    span = (LMTimeSpan) selfp->applet->tooltip_graph_span * 1000000;

    min_interval = span / LM_LINE_GRAPH_AREA_WIDTH;

    /*
     * Note that these timestamps can be negative, since on most
     * systems, lm_get_ticks() returns the number of ticks since boot.
     */
    min_timestamp = now - span;
    max_consolidation_timestamp = now - min_interval;

    /*
     * Discard the points which would end up at the left of the graph
     * except the last one (to have a line entering the graph on the
     * left).
     */
    for (i = 0; i < selfp->display_data->len; i++)
      {
	const LMDataPoint *dp = &g_array_index(selfp->display_data, LMDataPoint, i);

	if (dp->timestamp >= min_timestamp)
	  break;
      }
    if (i > 1)
      {
	int remove_len;

	remove_len = i - 1;

	g_array_remove_range(selfp->display_data, 0, remove_len);

	/* reflect the removal in the offset */
	selfp->display_data_consolidate_offset -= remove_len;
	if (selfp->display_data_consolidate_offset < 0)
	  selfp->display_data_consolidate_offset = 0;
      }

    for (i = selfp->display_data_consolidate_offset; i < selfp->display_data->len; i++)
      {
	const LMDataPoint *dp = &g_array_index(selfp->display_data, LMDataPoint, i);
	int group_end;
	int group_len;

	for (group_end = i + 1; group_end < selfp->display_data->len; group_end++)
	  {
	    const LMDataPoint *other_dp = &g_array_index(selfp->display_data, LMDataPoint, group_end);

	    /*
	     * We do not consolidate the data points more recent than
	     * min_interval. Otherwise, if data points arrived faster
	     * than min_interval, they would never have a chance to
	     * accumulate.
	     *
	     * For instance, with a 5 minutes graph span, the
	     * min_interval is 609756 usec. If the delay between echo
	     * requests is smaller than this (for instance 200 ms),
	     * the two most recent data points would always be
	     * averaged:
	     *
	     *	timestamp=0      |
	     *                   |-> averaged: timestamp=100000
	     *  timestamp=200000 |
	     *
	     *	timestamp=100000 |
	     *                   |-> averaged: timestamp=250000
	     *  timestamp=400000 |
	     *
	     *	timestamp=250000 |
	     *                   |-> averaged: timestamp=425000
	     *  timestamp=600000 |
	     *
	     *	timestamp=425000 |
	     *                   |-> averaged: timestamp=612500
	     *  timestamp=800000 |
	     */
	    if (other_dp->timestamp > max_consolidation_timestamp)
	      goto end;

	    if (other_dp->timestamp - dp->timestamp > min_interval)
	      break;
	  }

	group_len = group_end - i;
	if (group_len > 1)
	  self_average_points(selfp->display_data, i, group_len);
      }

  end:
    selfp->display_data_consolidate_offset = i;
  }}
#line 704 "lm-data-set.c"
#undef __GOB_FUNCTION__

#line 417 "src/lm-data-set.gob"
static void 
lm_data_set_add_data_point (LMDataSet * self, float roundtrip_time)
{
#line 711 "lm-data-set.c"
#define __GOB_FUNCTION__ "LM:Data:Set::add_data_point"
#line 417 "src/lm-data-set.gob"
	g_return_if_fail (self != NULL);
#line 417 "src/lm-data-set.gob"
	g_return_if_fail (LM_IS_DATA_SET (self));
#line 717 "lm-data-set.c"
{
#line 419 "src/lm-data-set.gob"
	
    LMTimeSpan now;
    LMDataPoint data_point;

    now = lm_get_ticks();

    data_point.timestamp = now;
    data_point.roundtrip_time = roundtrip_time;

    g_array_append_val(selfp->master_data, data_point);
    self_consolidate_master_data(self, now);

    if (selfp->display_data)
      {
	g_array_append_val(selfp->display_data, data_point);
	self_consolidate_display_data(self, now);
      }
  }}
#line 738 "lm-data-set.c"
#undef __GOB_FUNCTION__

#line 438 "src/lm-data-set.gob"
void 
lm_data_set_add_live_data_point (LMDataSet * self, LMTimeSpan roundtrip_time)
{
#line 745 "lm-data-set.c"
#define __GOB_FUNCTION__ "LM:Data:Set::add_live_data_point"
#line 438 "src/lm-data-set.gob"
	g_return_if_fail (self != NULL);
#line 438 "src/lm-data-set.gob"
	g_return_if_fail (LM_IS_DATA_SET (self));
#line 751 "lm-data-set.c"
{
#line 440 "src/lm-data-set.gob"
	
    self_add_data_point(self, roundtrip_time);
  }}
#line 757 "lm-data-set.c"
#undef __GOB_FUNCTION__

#line 444 "src/lm-data-set.gob"
void 
lm_data_set_add_dead_data_point (LMDataSet * self)
{
#line 764 "lm-data-set.c"
#define __GOB_FUNCTION__ "LM:Data:Set::add_dead_data_point"
#line 444 "src/lm-data-set.gob"
	g_return_if_fail (self != NULL);
#line 444 "src/lm-data-set.gob"
	g_return_if_fail (LM_IS_DATA_SET (self));
#line 770 "lm-data-set.c"
{
#line 446 "src/lm-data-set.gob"
	
    self_add_data_point(self, -1);
  }}
#line 776 "lm-data-set.c"
#undef __GOB_FUNCTION__

#line 450 "src/lm-data-set.gob"
GArray * 
lm_data_set_get_display_data (LMDataSet * self, LMTimeSpan now)
{
#line 783 "lm-data-set.c"
#define __GOB_FUNCTION__ "LM:Data:Set::get_display_data"
#line 450 "src/lm-data-set.gob"
	g_return_val_if_fail (self != NULL, (GArray * )0);
#line 450 "src/lm-data-set.gob"
	g_return_val_if_fail (LM_IS_DATA_SET (self), (GArray * )0);
#line 789 "lm-data-set.c"
{
#line 452 "src/lm-data-set.gob"
	
    if (! selfp->display_data)
      {
	g_assert(selfp->display_data_consolidate_offset == 0);

	/* initialize the display data from the master data */
	selfp->display_data = g_array_sized_new(FALSE, FALSE, sizeof(LMDataPoint), selfp->master_data->len);
	g_array_set_size(selfp->display_data, selfp->master_data->len);
	memcpy(selfp->display_data->data, selfp->master_data->data, sizeof(LMDataPoint) * selfp->master_data->len);

	self_consolidate_display_data(self, now);
      }

    return selfp->display_data;
  }}
#line 807 "lm-data-set.c"
#undef __GOB_FUNCTION__

#line 468 "src/lm-data-set.gob"
void 
lm_data_set_clear_display_data (LMDataSet * self)
{
#line 814 "lm-data-set.c"
#define __GOB_FUNCTION__ "LM:Data:Set::clear_display_data"
#line 468 "src/lm-data-set.gob"
	g_return_if_fail (self != NULL);
#line 468 "src/lm-data-set.gob"
	g_return_if_fail (LM_IS_DATA_SET (self));
#line 820 "lm-data-set.c"
{
#line 470 "src/lm-data-set.gob"
	
    if (selfp->display_data)
      {
	g_array_free(selfp->display_data, TRUE);
	selfp->display_data = NULL;
	selfp->display_data_consolidate_offset = 0;
      }
  }}
#line 831 "lm-data-set.c"
#undef __GOB_FUNCTION__

#line 479 "src/lm-data-set.gob"
LMDataSet * 
lm_data_set_new (LMApplet * applet)
{
#line 838 "lm-data-set.c"
#define __GOB_FUNCTION__ "LM:Data:Set::new"
#line 479 "src/lm-data-set.gob"
	g_return_val_if_fail (applet != NULL, (LMDataSet * )0);
#line 479 "src/lm-data-set.gob"
	g_return_val_if_fail (LM_IS_APPLET (applet), (LMDataSet * )0);
#line 844 "lm-data-set.c"
{
#line 481 "src/lm-data-set.gob"
	
    return GET_NEW_VARG(LM_HOST_PROP_APPLET(applet), NULL);
  }}
#line 850 "lm-data-set.c"
#undef __GOB_FUNCTION__