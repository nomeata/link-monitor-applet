/* Generated by GOB (v2.0.15)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 15

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "lm-bar-graph.h"

#include "lm-bar-graph-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 33 "src/lm-bar-graph.gob"

#include "lm-util.h"
#include "lm-applet.h"
#include "lm-host-frontend.h"

#define BAR_THICKNESS			6

#define BAR_PADDING			2

#define LINE_WIDTH			1.0

#define ALIGN				0.5

#line 40 "lm-bar-graph.c"
/* self casting macros */
#define SELF(x) LM_BAR_GRAPH(x)
#define SELF_CONST(x) LM_BAR_GRAPH_CONST(x)
#define IS_SELF(x) LM_IS_BAR_GRAPH(x)
#define TYPE_SELF LM_TYPE_BAR_GRAPH
#define SELF_CLASS(x) LM_BAR_GRAPH_CLASS(x)

#define SELF_GET_CLASS(x) LM_BAR_GRAPH_GET_CLASS(x)

/* self typedefs */
typedef LMBarGraph Self;
typedef LMBarGraphClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
#line 0 "src/lm-bar-graph.gob"
static void lm_bar_graph_init (LMBarGraph * o);
#line 59 "lm-bar-graph.c"
#line 0 "src/lm-bar-graph.gob"
static void lm_bar_graph_class_init (LMBarGraphClass * c);
#line 62 "lm-bar-graph.c"
#line 60 "src/lm-bar-graph.gob"
static void lm_bar_graph_constructor (LMBarGraph * self);
#line 65 "lm-bar-graph.c"
#line 82 "src/lm-bar-graph.gob"
static void ___3_lm_bar_graph_size_request (GtkWidget * widget, GtkRequisition * requisition);
#line 68 "lm-bar-graph.c"
#line 113 "src/lm-bar-graph.gob"
static gboolean ___4_lm_bar_graph_expose_event (GtkWidget * widget, GdkEventExpose * event);
#line 71 "lm-bar-graph.c"
#line 210 "src/lm-bar-graph.gob"
static void lm_bar_graph_draw_bar (LMBarGraph * self, LMHostFrontend * host, cairo_t * cr, int bar_x, int bar_y, int graph_width, int graph_height);
#line 74 "lm-bar-graph.c"

enum {
	PROP_0,
	PROP_APPLET,
	PROP_ORIENTATION
};

/* pointer to the class of our parent */
static GtkWidgetClass *parent_class = NULL;

/* Short form macros */
#define self_set_orientation lm_bar_graph_set_orientation
#define self_draw_bar lm_bar_graph_draw_bar
#define self_new lm_bar_graph_new
GType
lm_bar_graph_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (LMBarGraphClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) lm_bar_graph_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (LMBarGraph),
			0 /* n_preallocs */,
			(GInstanceInitFunc) lm_bar_graph_init,
			NULL
		};

		type = g_type_register_static (GTK_TYPE_WIDGET, "LMBarGraph", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((LMBarGraph *)g_object_new(lm_bar_graph_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static LMBarGraph * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static LMBarGraph *
GET_NEW_VARG (const char *first, ...)
{
	LMBarGraph *ret;
	va_list ap;
	va_start (ap, first);
	ret = (LMBarGraph *)g_object_new_valist (lm_bar_graph_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static GObject *
___constructor (GType type, guint n_construct_properties, GObjectConstructParam *construct_properties)
{
#define __GOB_FUNCTION__ "LM:Bar:Graph::constructor"
	GObject *obj_self;
	LMBarGraph *self;
	obj_self = G_OBJECT_CLASS (parent_class)->constructor (type, n_construct_properties, construct_properties);
	self = LM_BAR_GRAPH (obj_self);
#line 60 "src/lm-bar-graph.gob"
	lm_bar_graph_constructor (self);
#line 142 "lm-bar-graph.c"
	return obj_self;
}
#undef __GOB_FUNCTION__


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "LM:Bar:Graph::finalize"
	LMBarGraph *self G_GNUC_UNUSED = LM_BAR_GRAPH (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
}
#undef __GOB_FUNCTION__

static void 
lm_bar_graph_init (LMBarGraph * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "LM:Bar:Graph::init"
	o->_priv = G_TYPE_INSTANCE_GET_PRIVATE(o,LM_TYPE_BAR_GRAPH,LMBarGraphPrivate);
}
#undef __GOB_FUNCTION__
static void 
lm_bar_graph_class_init (LMBarGraphClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "LM:Bar:Graph::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;
	GtkWidgetClass *gtk_widget_class = (GtkWidgetClass *)c;

	g_type_class_add_private(c,sizeof(LMBarGraphPrivate));

	parent_class = g_type_class_ref (GTK_TYPE_WIDGET);

#line 82 "src/lm-bar-graph.gob"
	gtk_widget_class->size_request = ___3_lm_bar_graph_size_request;
#line 113 "src/lm-bar-graph.gob"
	gtk_widget_class->expose_event = ___4_lm_bar_graph_expose_event;
#line 181 "lm-bar-graph.c"
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
	param_spec = g_param_spec_int
		("orientation" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 G_MININT /* minimum */,
		 G_MAXINT /* maximum */,
		 0 /* default_value */,
		 (GParamFlags)(G_PARAM_WRITABLE));
	g_object_class_install_property (g_object_class,
		PROP_ORIENTATION,
		param_spec);
    }
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "LM:Bar:Graph::set_property"
{
	LMBarGraph *self G_GNUC_UNUSED;

	self = LM_BAR_GRAPH (object);

	switch (property_id) {
	case PROP_APPLET:
		{
#line 50 "src/lm-bar-graph.gob"
self->_priv->applet = g_value_get_pointer (VAL);
#line 228 "lm-bar-graph.c"
		}
		break;
	case PROP_ORIENTATION:
		{
#line 55 "src/lm-bar-graph.gob"

      selfp->orientation = g_value_get_int(VAL);
      gtk_widget_queue_resize(GTK_WIDGET(self));
    
#line 238 "lm-bar-graph.c"
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
#define __GOB_FUNCTION__ "LM:Bar:Graph::get_property"
{
	LMBarGraph *self G_GNUC_UNUSED;

	self = LM_BAR_GRAPH (object);

	switch (property_id) {
	case PROP_APPLET:
		{
#line 50 "src/lm-bar-graph.gob"
g_value_set_pointer (VAL, self->_priv->applet);
#line 269 "lm-bar-graph.c"
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



#line 55 "src/lm-bar-graph.gob"
void 
lm_bar_graph_set_orientation (LMBarGraph * self, LMBarGraphOrientation val)
{
#line 290 "lm-bar-graph.c"
#define __GOB_FUNCTION__ "LM:Bar:Graph::set_orientation"
{
#line 53 "src/lm-bar-graph.gob"
		g_object_set (G_OBJECT (self), "orientation", val, NULL);
}}
#line 296 "lm-bar-graph.c"
#undef __GOB_FUNCTION__

#line 60 "src/lm-bar-graph.gob"
static void 
lm_bar_graph_constructor (LMBarGraph * self)
{
#line 303 "lm-bar-graph.c"
#define __GOB_FUNCTION__ "LM:Bar:Graph::constructor"
{
#line 61 "src/lm-bar-graph.gob"
	
    int i;

    GTK_WIDGET_SET_FLAGS(self, GTK_NO_WINDOW);

    lm_g_object_connect(self, selfp->applet,
			"swapped-signal::notify::scale", gtk_widget_queue_draw, self,
			NULL);

    LM_ARRAY_FOREACH(i, selfp->applet->hosts)
      {
	LMHostFrontend *host = g_ptr_array_index(selfp->applet->hosts, i);

	lm_g_object_connect(self, host,
			    "swapped-signal::notify::color", gtk_widget_queue_draw, self,
			    "swapped-signal::notify::alive", gtk_widget_queue_draw, self,
			    "swapped-signal::notify::roundtrip-time", gtk_widget_queue_draw, self,
			    NULL);
      }
  }}
#line 327 "lm-bar-graph.c"
#undef __GOB_FUNCTION__

#line 82 "src/lm-bar-graph.gob"
static void 
___3_lm_bar_graph_size_request (GtkWidget * widget G_GNUC_UNUSED, GtkRequisition * requisition)
#line 333 "lm-bar-graph.c"
#define PARENT_HANDLER(___widget,___requisition) \
	{ if(GTK_WIDGET_CLASS(parent_class)->size_request) \
		(* GTK_WIDGET_CLASS(parent_class)->size_request)(___widget,___requisition); }
{
#define __GOB_FUNCTION__ "LM:Bar:Graph::size_request"
{
#line 84 "src/lm-bar-graph.gob"
	
    Self *self = SELF(widget);
    int num_bars;
    int thickness;

    num_bars = selfp->applet->hosts->len;
    thickness = LM_BOX_BORDER_WIDTH * 2
      + BAR_PADDING * 2
      + num_bars * BAR_THICKNESS
      + (num_bars - 1) * BAR_PADDING;

    switch (selfp->orientation)
      {
      case LM_BAR_GRAPH_ORIENTATION_HORIZONTAL:
	requisition->width = 0;
	requisition->height = thickness;
	break;

      case LM_BAR_GRAPH_ORIENTATION_VERTICAL:
	requisition->width = thickness;
	requisition->height = 0;
	break;

      default:
	g_assert_not_reached();
	break;
      }
  }}
#line 369 "lm-bar-graph.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 113 "src/lm-bar-graph.gob"
static gboolean 
___4_lm_bar_graph_expose_event (GtkWidget * widget G_GNUC_UNUSED, GdkEventExpose * event)
#line 376 "lm-bar-graph.c"
#define PARENT_HANDLER(___widget,___event) \
	((GTK_WIDGET_CLASS(parent_class)->expose_event)? \
		(* GTK_WIDGET_CLASS(parent_class)->expose_event)(___widget,___event): \
		((gboolean )0))
{
#define __GOB_FUNCTION__ "LM:Bar:Graph::expose_event"
{
#line 115 "src/lm-bar-graph.gob"
	
    Self *self = SELF(widget);
    GdkRectangle entire_rect;
    GdkRectangle contents_rect;
    int bar_x;
    int bar_y;
    int graph_width;
    int graph_height;
    cairo_t *cr;
    int i;

    if (! GTK_WIDGET_DRAWABLE(widget))
      return FALSE;

    switch (selfp->orientation)
      {
      case LM_BAR_GRAPH_ORIENTATION_HORIZONTAL:
	entire_rect.x = widget->allocation.x;
	lm_widget_get_origin(widget, ALIGN, ALIGN, NULL, &entire_rect.y);
	entire_rect.width = widget->allocation.width;
	entire_rect.height = widget->requisition.height;
	break;

      case LM_BAR_GRAPH_ORIENTATION_VERTICAL:
	lm_widget_get_origin(widget, ALIGN, ALIGN, &entire_rect.x, NULL);
	entire_rect.y = widget->allocation.y;
	entire_rect.width = widget->requisition.width;
	entire_rect.height = widget->allocation.height;
	break;

      default:
	g_assert_not_reached();
	break;
      }

    contents_rect.x = entire_rect.x + LM_BOX_BORDER_WIDTH;
    contents_rect.y = entire_rect.y + LM_BOX_BORDER_WIDTH;
    contents_rect.width = entire_rect.width - LM_BOX_BORDER_WIDTH * 2;
    contents_rect.height = entire_rect.height - LM_BOX_BORDER_WIDTH * 2;

    bar_x = contents_rect.x + BAR_PADDING;
    bar_y = contents_rect.y + BAR_PADDING;
    graph_width = contents_rect.width - BAR_PADDING * 2;
    graph_height = contents_rect.height - BAR_PADDING * 2;

    lm_paint_box(widget->window,
		 GTK_WIDGET_STATE(widget),
		 GTK_SHADOW_IN,
		 &event->area,
		 widget,
		 widget->style->base_gc[GTK_WIDGET_STATE(widget)],
		 entire_rect.x,
		 entire_rect.y,
		 entire_rect.width,
		 entire_rect.height);

    cr = gdk_cairo_create(widget->window);

    cairo_set_line_width(cr, LINE_WIDTH);
    cairo_set_line_cap(cr, CAIRO_LINE_CAP_BUTT);
    cairo_set_line_join(cr, CAIRO_LINE_JOIN_MITER);

    LM_ARRAY_FOREACH(i, selfp->applet->hosts)
      {
	LMHostFrontend *host = g_ptr_array_index(selfp->applet->hosts, i);

	self_draw_bar(self,
		      host,
		      cr,
		      bar_x,
		      bar_y,
		      graph_width,
		      graph_height);

	switch (selfp->orientation)
	  {
	  case LM_BAR_GRAPH_ORIENTATION_HORIZONTAL:
	    bar_y += BAR_THICKNESS + BAR_PADDING;
	    break;

	  case LM_BAR_GRAPH_ORIENTATION_VERTICAL:
	    bar_x += BAR_THICKNESS + BAR_PADDING;
	    break;

	  default:
	    g_assert_not_reached();
	    break;
	  }
      }

    cairo_destroy(cr);

    return FALSE;
  }}
#line 479 "lm-bar-graph.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 210 "src/lm-bar-graph.gob"
static void 
lm_bar_graph_draw_bar (LMBarGraph * self, LMHostFrontend * host, cairo_t * cr, int bar_x, int bar_y, int graph_width, int graph_height)
{
#line 487 "lm-bar-graph.c"
#define __GOB_FUNCTION__ "LM:Bar:Graph::draw_bar"
#line 210 "src/lm-bar-graph.gob"
	g_return_if_fail (self != NULL);
#line 210 "src/lm-bar-graph.gob"
	g_return_if_fail (LM_IS_BAR_GRAPH (self));
#line 210 "src/lm-bar-graph.gob"
	g_return_if_fail (host != NULL);
#line 210 "src/lm-bar-graph.gob"
	g_return_if_fail (LM_IS_HOST_FRONTEND (host));
#line 210 "src/lm-bar-graph.gob"
	g_return_if_fail (cr != NULL);
#line 499 "lm-bar-graph.c"
{
#line 218 "src/lm-bar-graph.gob"
	
    LMHost *base_host = LM_HOST(host);
    GdkRectangle bar_rect;
    LMCairoColor fill_color;
    LMCairoColor border_color;
    double fraction;

    if (base_host->alive)
      {
	fraction = ((double) base_host->roundtrip_time / 1000) / selfp->applet->scale;
	fraction = CLAMP(fraction, 0.0, 1.0);
      }
    else
      fraction = 1.0;

    switch (selfp->orientation)
      {
      case LM_BAR_GRAPH_ORIENTATION_HORIZONTAL:
	bar_rect.width = fraction * graph_width;
	bar_rect.height = BAR_THICKNESS;
	bar_rect.x = bar_x;
	bar_rect.y = bar_y;
	break;

      case LM_BAR_GRAPH_ORIENTATION_VERTICAL:
	bar_rect.width = BAR_THICKNESS;
	bar_rect.height = fraction * graph_height;
	bar_rect.x = bar_x;
	bar_rect.y = bar_y + graph_height - bar_rect.height;
	break;

      default:
	g_assert_not_reached();
	break;
      }

    /* setup a clip rectangle for the bar */
    cairo_save(cr);
    cairo_new_path(cr);
    cairo_rectangle(cr, bar_rect.x, bar_rect.y, bar_rect.width, bar_rect.height);
    cairo_clip(cr);
    cairo_translate(cr, bar_rect.x, bar_rect.y);

    lm_gdk_color_to_cairo_color(&host->color, &fill_color);
    lm_cairo_color_shade(&fill_color, &border_color, 0.6);

    /* draw the bar border */
    lm_cairo_set_source_color(cr, &border_color);
    cairo_rectangle(cr,
		    LINE_WIDTH,
		    LINE_WIDTH,
		    bar_rect.width - LINE_WIDTH * 2,
		    bar_rect.height - LINE_WIDTH * 2);
    cairo_stroke_preserve(cr);

    /* if the host is alive, fill the bar */
    if (base_host->alive)
      {
	lm_cairo_set_source_color(cr, &fill_color);
	cairo_fill(cr);
      }

    cairo_restore(cr);
  }}
#line 566 "lm-bar-graph.c"
#undef __GOB_FUNCTION__

#line 283 "src/lm-bar-graph.gob"
GtkWidget * 
lm_bar_graph_new (LMApplet * applet)
{
#line 573 "lm-bar-graph.c"
#define __GOB_FUNCTION__ "LM:Bar:Graph::new"
#line 283 "src/lm-bar-graph.gob"
	g_return_val_if_fail (applet != NULL, (GtkWidget * )0);
#line 283 "src/lm-bar-graph.gob"
	g_return_val_if_fail (LM_IS_APPLET (applet), (GtkWidget * )0);
#line 579 "lm-bar-graph.c"
{
#line 285 "src/lm-bar-graph.gob"
	
    return GTK_WIDGET(GET_NEW_VARG(LM_BAR_GRAPH_PROP_APPLET(applet), NULL));
  }}
#line 585 "lm-bar-graph.c"
#undef __GOB_FUNCTION__