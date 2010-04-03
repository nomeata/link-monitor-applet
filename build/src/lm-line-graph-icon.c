/* Generated by GOB (v2.0.15)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 15

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "lm-line-graph-icon.h"

#include "lm-line-graph-icon-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 25 "src/lm-line-graph-icon.gob"

#define WIDTH		36
#define HEIGHT		24

#define XALIGN		0.5
#define YALIGN		0.5

#define LINE_WIDTH	3.0

typedef struct
{
  double x;
  double y;
} Point;

static const Point points[] = {
  { 0.1, 0.5 },
  { 0.2, 0.7 },
  { 0.4, 0.2 },
  { 0.5, 0.7 },
  { 0.7, 0.3 },
  { 0.9, 0.6 }
};

#line 51 "lm-line-graph-icon.c"
/* self casting macros */
#define SELF(x) LM_LINE_GRAPH_ICON(x)
#define SELF_CONST(x) LM_LINE_GRAPH_ICON_CONST(x)
#define IS_SELF(x) LM_IS_LINE_GRAPH_ICON(x)
#define TYPE_SELF LM_TYPE_LINE_GRAPH_ICON
#define SELF_CLASS(x) LM_LINE_GRAPH_ICON_CLASS(x)

#define SELF_GET_CLASS(x) LM_LINE_GRAPH_ICON_GET_CLASS(x)

/* self typedefs */
typedef LMLineGraphIcon Self;
typedef LMLineGraphIconClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
#line 0 "src/lm-line-graph-icon.gob"
static void lm_line_graph_icon_init (LMLineGraphIcon * o);
#line 70 "lm-line-graph-icon.c"
#line 0 "src/lm-line-graph-icon.gob"
static void lm_line_graph_icon_class_init (LMLineGraphIconClass * c);
#line 73 "lm-line-graph-icon.c"
#line 55 "src/lm-line-graph-icon.gob"
static void lm_line_graph_icon_constructor (LMLineGraphIcon * self);
#line 76 "lm-line-graph-icon.c"
#line 64 "src/lm-line-graph-icon.gob"
static void ___2_lm_line_graph_icon_size_request (GtkWidget * widget, GtkRequisition * requisition);
#line 79 "lm-line-graph-icon.c"
#line 76 "src/lm-line-graph-icon.gob"
static void lm_line_graph_icon_get_absolute_point (LMLineGraphIcon * self, const Point * in, Point * out);
#line 82 "lm-line-graph-icon.c"
#line 91 "src/lm-line-graph-icon.gob"
static gboolean ___4_lm_line_graph_icon_expose_event (GtkWidget * widget, GdkEventExpose * event);
#line 85 "lm-line-graph-icon.c"

enum {
	PROP_0,
	PROP_HOST
};

/* pointer to the class of our parent */
static GtkWidgetClass *parent_class = NULL;

/* Short form macros */
#define self_get_absolute_point lm_line_graph_icon_get_absolute_point
#define self_new lm_line_graph_icon_new
GType
lm_line_graph_icon_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (LMLineGraphIconClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) lm_line_graph_icon_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (LMLineGraphIcon),
			0 /* n_preallocs */,
			(GInstanceInitFunc) lm_line_graph_icon_init,
			NULL
		};

		type = g_type_register_static (GTK_TYPE_WIDGET, "LMLineGraphIcon", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((LMLineGraphIcon *)g_object_new(lm_line_graph_icon_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static LMLineGraphIcon * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static LMLineGraphIcon *
GET_NEW_VARG (const char *first, ...)
{
	LMLineGraphIcon *ret;
	va_list ap;
	va_start (ap, first);
	ret = (LMLineGraphIcon *)g_object_new_valist (lm_line_graph_icon_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static GObject *
___constructor (GType type, guint n_construct_properties, GObjectConstructParam *construct_properties)
{
#define __GOB_FUNCTION__ "LM:Line:Graph:Icon::constructor"
	GObject *obj_self;
	LMLineGraphIcon *self;
	obj_self = G_OBJECT_CLASS (parent_class)->constructor (type, n_construct_properties, construct_properties);
	self = LM_LINE_GRAPH_ICON (obj_self);
#line 55 "src/lm-line-graph-icon.gob"
	lm_line_graph_icon_constructor (self);
#line 151 "lm-line-graph-icon.c"
	return obj_self;
}
#undef __GOB_FUNCTION__


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "LM:Line:Graph:Icon::finalize"
	LMLineGraphIcon *self G_GNUC_UNUSED = LM_LINE_GRAPH_ICON (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
}
#undef __GOB_FUNCTION__

static void 
lm_line_graph_icon_init (LMLineGraphIcon * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "LM:Line:Graph:Icon::init"
	o->_priv = G_TYPE_INSTANCE_GET_PRIVATE(o,LM_TYPE_LINE_GRAPH_ICON,LMLineGraphIconPrivate);
}
#undef __GOB_FUNCTION__
static void 
lm_line_graph_icon_class_init (LMLineGraphIconClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "LM:Line:Graph:Icon::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;
	GtkWidgetClass *gtk_widget_class = (GtkWidgetClass *)c;

	g_type_class_add_private(c,sizeof(LMLineGraphIconPrivate));

	parent_class = g_type_class_ref (GTK_TYPE_WIDGET);

#line 64 "src/lm-line-graph-icon.gob"
	gtk_widget_class->size_request = ___2_lm_line_graph_icon_size_request;
#line 91 "src/lm-line-graph-icon.gob"
	gtk_widget_class->expose_event = ___4_lm_line_graph_icon_expose_event;
#line 190 "lm-line-graph-icon.c"
	g_object_class->constructor = ___constructor;
	g_object_class->finalize = ___finalize;
	g_object_class->get_property = ___object_get_property;
	g_object_class->set_property = ___object_set_property;
    {
	GParamSpec   *param_spec;

	param_spec = g_param_spec_pointer
		("host" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (g_object_class,
		PROP_HOST,
		param_spec);
    }
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "LM:Line:Graph:Icon::set_property"
{
	LMLineGraphIcon *self G_GNUC_UNUSED;

	self = LM_LINE_GRAPH_ICON (object);

	switch (property_id) {
	case PROP_HOST:
		{
#line 53 "src/lm-line-graph-icon.gob"
self->_priv->host = g_value_get_pointer (VAL);
#line 226 "lm-line-graph-icon.c"
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
#define __GOB_FUNCTION__ "LM:Line:Graph:Icon::get_property"
{
	LMLineGraphIcon *self G_GNUC_UNUSED;

	self = LM_LINE_GRAPH_ICON (object);

	switch (property_id) {
	case PROP_HOST:
		{
#line 53 "src/lm-line-graph-icon.gob"
g_value_set_pointer (VAL, self->_priv->host);
#line 257 "lm-line-graph-icon.c"
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



#line 55 "src/lm-line-graph-icon.gob"
static void 
lm_line_graph_icon_constructor (LMLineGraphIcon * self)
{
#line 278 "lm-line-graph-icon.c"
#define __GOB_FUNCTION__ "LM:Line:Graph:Icon::constructor"
{
#line 56 "src/lm-line-graph-icon.gob"
	
    GTK_WIDGET_SET_FLAGS(self, GTK_NO_WINDOW);

    lm_g_object_connect(self, selfp->host,
			"swapped-signal::notify::color", gtk_widget_queue_draw, self,
			NULL);
  }}
#line 289 "lm-line-graph-icon.c"
#undef __GOB_FUNCTION__

#line 64 "src/lm-line-graph-icon.gob"
static void 
___2_lm_line_graph_icon_size_request (GtkWidget * widget G_GNUC_UNUSED, GtkRequisition * requisition)
#line 295 "lm-line-graph-icon.c"
#define PARENT_HANDLER(___widget,___requisition) \
	{ if(GTK_WIDGET_CLASS(parent_class)->size_request) \
		(* GTK_WIDGET_CLASS(parent_class)->size_request)(___widget,___requisition); }
{
#define __GOB_FUNCTION__ "LM:Line:Graph:Icon::size_request"
{
#line 66 "src/lm-line-graph-icon.gob"
	
    requisition->width = WIDTH;
    requisition->height = HEIGHT;
  }}
#line 307 "lm-line-graph-icon.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 76 "src/lm-line-graph-icon.gob"
static void 
lm_line_graph_icon_get_absolute_point (LMLineGraphIcon * self, const Point * in, Point * out)
{
#line 315 "lm-line-graph-icon.c"
#define __GOB_FUNCTION__ "LM:Line:Graph:Icon::get_absolute_point"
#line 76 "src/lm-line-graph-icon.gob"
	g_return_if_fail (self != NULL);
#line 76 "src/lm-line-graph-icon.gob"
	g_return_if_fail (LM_IS_LINE_GRAPH_ICON (self));
#line 76 "src/lm-line-graph-icon.gob"
	g_return_if_fail (in != NULL);
#line 76 "src/lm-line-graph-icon.gob"
	g_return_if_fail (out != NULL);
#line 325 "lm-line-graph-icon.c"
{
#line 80 "src/lm-line-graph-icon.gob"
	
    GtkWidget *widget = GTK_WIDGET(self);

    out->x = widget->allocation.x
      + ((widget->allocation.width - widget->requisition.width) * XALIGN)
      + (in->x * widget->requisition.width);
    out->y = widget->allocation.y
      + ((widget->allocation.height - widget->requisition.height) * YALIGN)
      + (in->y * widget->requisition.height);
  }}
#line 338 "lm-line-graph-icon.c"
#undef __GOB_FUNCTION__

#line 91 "src/lm-line-graph-icon.gob"
static gboolean 
___4_lm_line_graph_icon_expose_event (GtkWidget * widget G_GNUC_UNUSED, GdkEventExpose * event)
#line 344 "lm-line-graph-icon.c"
#define PARENT_HANDLER(___widget,___event) \
	((GTK_WIDGET_CLASS(parent_class)->expose_event)? \
		(* GTK_WIDGET_CLASS(parent_class)->expose_event)(___widget,___event): \
		((gboolean )0))
{
#define __GOB_FUNCTION__ "LM:Line:Graph:Icon::expose_event"
{
#line 93 "src/lm-line-graph-icon.gob"
	
    Self *self = SELF(widget);
    cairo_t *cr;
    Point p;
    int i;

    if (! GTK_WIDGET_DRAWABLE(widget))
      return FALSE;

    cr = gdk_cairo_create(widget->window);

    gdk_cairo_set_source_color(cr, &selfp->host->color);

    cairo_set_line_width(cr, LINE_WIDTH);
    cairo_set_line_cap(cr, CAIRO_LINE_CAP_BUTT);
    cairo_set_line_join(cr, CAIRO_LINE_JOIN_MITER);

    self_get_absolute_point(self, &points[0], &p);
    cairo_move_to(cr, p.x, p.y);

    for (i = 1; i < G_N_ELEMENTS(points); i++)
      {
	self_get_absolute_point(self, &points[i], &p);
	cairo_line_to(cr, p.x, p.y);
      }

    cairo_stroke(cr);

    cairo_destroy(cr);

    return FALSE;
  }}
#line 385 "lm-line-graph-icon.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 126 "src/lm-line-graph-icon.gob"
GtkWidget * 
lm_line_graph_icon_new (LMHostFrontend * host)
{
#line 393 "lm-line-graph-icon.c"
#define __GOB_FUNCTION__ "LM:Line:Graph:Icon::new"
#line 126 "src/lm-line-graph-icon.gob"
	g_return_val_if_fail (host != NULL, (GtkWidget * )0);
#line 126 "src/lm-line-graph-icon.gob"
	g_return_val_if_fail (LM_IS_HOST_FRONTEND (host), (GtkWidget * )0);
#line 399 "lm-line-graph-icon.c"
{
#line 128 "src/lm-line-graph-icon.gob"
	
    return GTK_WIDGET(GET_NEW_VARG(LM_LINE_GRAPH_ICON_PROP_HOST(host), NULL));
  }}
#line 405 "lm-line-graph-icon.c"
#undef __GOB_FUNCTION__
