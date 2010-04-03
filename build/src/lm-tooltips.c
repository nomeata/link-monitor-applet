/* Generated by GOB (v2.0.15)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 15

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "lm-tooltips.h"

#include "lm-tooltips-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 41 "src/lm-tooltips.gob"

#include "lm-util.h"

#define TOOLTIPS_DATA			"lm-tooltips-data"
#define TOOLTIPS_INFO			"lm-tooltips-info"
#define TOOLTIPS_KEYBOARD_MODE		"gtk-tooltips-keyboard-mode" /* compatible with GtkTooltips */

#define DELAY 500			/* Default delay in ms */
#define STICKY_DELAY 0			/* Delay before popping up next tip
					 * if we're sticky
					 */
#define STICKY_REVERT_DELAY 1000	/* Delay before sticky tooltips revert
					 * to normal
					 */

/* The private flags that are used in the private_flags member of GtkWidget.
 */
typedef enum
{
  PRIVATE_GTK_LEAVE_PENDING	= 1 <<  4
} GtkPrivateFlags;

/* Macros for extracting a widgets private_flags from GtkWidget.
 */
#define GTK_PRIVATE_FLAGS(wid)            (GTK_WIDGET (wid)->private_flags)

/* Macros for setting and clearing private widget flags.
 * we use a preprocessor string concatenation here for a clear
 * flags/private_flags distinction at the cost of single flag operations.
 */
#define GTK_PRIVATE_SET_FLAG(wid,flag)    G_STMT_START{ (GTK_PRIVATE_FLAGS (wid) |= (PRIVATE_ ## flag)); }G_STMT_END

#line 59 "lm-tooltips.c"
/* self casting macros */
#define SELF(x) LM_TOOLTIPS(x)
#define SELF_CONST(x) LM_TOOLTIPS_CONST(x)
#define IS_SELF(x) LM_IS_TOOLTIPS(x)
#define TYPE_SELF LM_TYPE_TOOLTIPS
#define SELF_CLASS(x) LM_TOOLTIPS_CLASS(x)

#define SELF_GET_CLASS(x) LM_TOOLTIPS_GET_CLASS(x)

/* self typedefs */
typedef LMTooltips Self;
typedef LMTooltipsClass SelfClass;

/* here are local prototypes */
#line 0 "src/lm-tooltips.gob"
static void lm_tooltips_init (LMTooltips * o);
#line 76 "lm-tooltips.c"
#line 0 "src/lm-tooltips.gob"
static void lm_tooltips_class_init (LMTooltipsClass * c);
#line 79 "lm-tooltips.c"
#line 86 "src/lm-tooltips.gob"
static void lm_tooltips_finalize (LMTooltips * self);
#line 82 "lm-tooltips.c"
#line 102 "src/lm-tooltips.gob"
static void lm_tooltips_destroy_data (TooltipsData * data);
#line 85 "lm-tooltips.c"
#line 117 "src/lm-tooltips.gob"
static void lm_tooltips_display_closed_h (GdkDisplay * display, gboolean is_error, gpointer user_data);
#line 88 "lm-tooltips.c"
#line 126 "src/lm-tooltips.gob"
static void lm_tooltips_disconnect_display_closed (LMTooltips * self);
#line 91 "lm-tooltips.c"
#line 134 "src/lm-tooltips.gob"
static void lm_tooltips_unset_window (LMTooltips * self);
#line 94 "lm-tooltips.c"
#line 144 "src/lm-tooltips.gob"
static void lm_tooltips_update_screen (LMTooltips * self, gboolean new_window);
#line 97 "lm-tooltips.c"
#line 171 "src/lm-tooltips.gob"
static void lm_tooltips_force_window (LMTooltips * self);
#line 100 "lm-tooltips.c"
#line 192 "src/lm-tooltips.gob"
static TooltipsData * lm_tooltips_get_data (GtkWidget * widget);
#line 103 "lm-tooltips.c"
#line 198 "src/lm-tooltips.gob"
static void lm_tooltips_set_tip_widget_real (LMTooltips * self, GtkWidget * widget, GtkWidget * tip_widget, int border_width);
#line 106 "lm-tooltips.c"
#line 287 "src/lm-tooltips.gob"
static gboolean lm_tooltips_paint_window (LMTooltips * self);
#line 109 "lm-tooltips.c"
#line 308 "src/lm-tooltips.gob"
static void lm_tooltips_draw_tips (LMTooltips * self);
#line 112 "lm-tooltips.c"
#line 405 "src/lm-tooltips.gob"
static gboolean lm_tooltips_timeout_cb (gpointer data);
#line 115 "lm-tooltips.c"
#line 417 "src/lm-tooltips.gob"
static void lm_tooltips_set_active_widget (LMTooltips * self, GtkWidget * widget);
#line 118 "lm-tooltips.c"
#line 450 "src/lm-tooltips.gob"
static void lm_tooltips_show_tip (GtkWidget * widget);
#line 121 "lm-tooltips.c"
#line 466 "src/lm-tooltips.gob"
static void lm_tooltips_hide_tip (GtkWidget * widget);
#line 124 "lm-tooltips.c"
#line 479 "src/lm-tooltips.gob"
static gboolean lm_tooltips_recently_shown (LMTooltips * self);
#line 127 "lm-tooltips.c"
#line 491 "src/lm-tooltips.gob"
static gboolean lm_tooltips_get_keyboard_mode (GtkWidget * widget);
#line 130 "lm-tooltips.c"
#line 502 "src/lm-tooltips.gob"
static void lm_tooltips_start_keyboard_mode (GtkWidget * widget);
#line 133 "lm-tooltips.c"
#line 518 "src/lm-tooltips.gob"
static void lm_tooltips_stop_keyboard_mode (GtkWidget * widget);
#line 136 "lm-tooltips.c"
#line 534 "src/lm-tooltips.gob"
static void lm_tooltips_start_delay (LMTooltips * self, GtkWidget * widget);
#line 139 "lm-tooltips.c"
#line 549 "src/lm-tooltips.gob"
static void lm_tooltips_event_after_h (GtkWidget * widget, GdkEvent * event, gpointer user_data);
#line 142 "lm-tooltips.c"
#line 634 "src/lm-tooltips.gob"
static void lm_tooltips_widget_unmap (GtkWidget * widget, gpointer user_data);
#line 145 "lm-tooltips.c"
#line 645 "src/lm-tooltips.gob"
static void lm_tooltips_widget_remove (GtkWidget * widget, gpointer user_data);
#line 148 "lm-tooltips.c"

/* pointer to the class of our parent */
static GObjectClass *parent_class = NULL;

/* Short form macros */
#define self_destroy_data lm_tooltips_destroy_data
#define self_display_closed_h lm_tooltips_display_closed_h
#define self_disconnect_display_closed lm_tooltips_disconnect_display_closed
#define self_unset_window lm_tooltips_unset_window
#define self_update_screen lm_tooltips_update_screen
#define self_force_window lm_tooltips_force_window
#define self_get_data lm_tooltips_get_data
#define self_set_tip_widget_real lm_tooltips_set_tip_widget_real
#define self_set_tip lm_tooltips_set_tip
#define self_set_tip_widget lm_tooltips_set_tip_widget
#define self_paint_window lm_tooltips_paint_window
#define self_draw_tips lm_tooltips_draw_tips
#define self_timeout_cb lm_tooltips_timeout_cb
#define self_set_active_widget lm_tooltips_set_active_widget
#define self_show_tip lm_tooltips_show_tip
#define self_hide_tip lm_tooltips_hide_tip
#define self_recently_shown lm_tooltips_recently_shown
#define self_get_keyboard_mode lm_tooltips_get_keyboard_mode
#define self_start_keyboard_mode lm_tooltips_start_keyboard_mode
#define self_stop_keyboard_mode lm_tooltips_stop_keyboard_mode
#define self_start_delay lm_tooltips_start_delay
#define self_event_after_h lm_tooltips_event_after_h
#define self_widget_unmap lm_tooltips_widget_unmap
#define self_widget_remove lm_tooltips_widget_remove
#define self_toggle_keyboard_mode lm_tooltips_toggle_keyboard_mode
#define self_new lm_tooltips_new
GType
lm_tooltips_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (LMTooltipsClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) lm_tooltips_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (LMTooltips),
			0 /* n_preallocs */,
			(GInstanceInitFunc) lm_tooltips_init,
			NULL
		};

		type = g_type_register_static (G_TYPE_OBJECT, "LMTooltips", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((LMTooltips *)g_object_new(lm_tooltips_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static LMTooltips * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static LMTooltips *
GET_NEW_VARG (const char *first, ...)
{
	LMTooltips *ret;
	va_list ap;
	va_start (ap, first);
	ret = (LMTooltips *)g_object_new_valist (lm_tooltips_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "LM:Tooltips::finalize"
	LMTooltips *self G_GNUC_UNUSED = LM_TOOLTIPS (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
#line 86 "src/lm-tooltips.gob"
	lm_tooltips_finalize (self);
#line 231 "lm-tooltips.c"
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
}
#undef __GOB_FUNCTION__

static void 
lm_tooltips_init (LMTooltips * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "LM:Tooltips::init"
	o->_priv = G_TYPE_INSTANCE_GET_PRIVATE(o,LM_TYPE_TOOLTIPS,LMTooltipsPrivate);
#line 41 "src/lm-tooltips.gob"
	o->_priv->border_width = 4;
#line 244 "lm-tooltips.c"
}
#undef __GOB_FUNCTION__
static void 
lm_tooltips_class_init (LMTooltipsClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "LM:Tooltips::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	g_type_class_add_private(c,sizeof(LMTooltipsPrivate));

	parent_class = g_type_class_ref (G_TYPE_OBJECT);

	g_object_class->finalize = ___finalize;
}
#undef __GOB_FUNCTION__



#line 86 "src/lm-tooltips.gob"
static void 
lm_tooltips_finalize (LMTooltips * self)
{
#line 267 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::finalize"
{
#line 87 "src/lm-tooltips.gob"
	
    GSList *l;

    if (selfp->timeout_id)
      g_source_remove(selfp->timeout_id);

    LM_LIST_FOREACH(l, selfp->data_list)
      {
	TooltipsData *data = l->data;
	self_widget_remove(data->widget, data);
      }

    self_unset_window(self);
  }}
#line 285 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 102 "src/lm-tooltips.gob"
static void 
lm_tooltips_destroy_data (TooltipsData * data)
{
#line 292 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::destroy_data"
{
#line 104 "src/lm-tooltips.gob"
	
    g_object_disconnect(data->widget,
			"any-signal", self_event_after_h, data,
			"any-signal", self_widget_unmap, data,
			"any-signal", self_widget_remove, data,
			NULL);

    g_object_set_data(G_OBJECT(data->widget), TOOLTIPS_DATA, NULL);
    g_object_unref(data->widget);
    g_object_unref(data->tip_widget);
    g_free(data);
  }}
#line 308 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 117 "src/lm-tooltips.gob"
static void 
lm_tooltips_display_closed_h (GdkDisplay * display, gboolean is_error, gpointer user_data)
{
#line 315 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::display_closed_h"
{
#line 121 "src/lm-tooltips.gob"
	
    Self *self = SELF(user_data);
    self_unset_window(self);
  }}
#line 323 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 126 "src/lm-tooltips.gob"
static void 
lm_tooltips_disconnect_display_closed (LMTooltips * self)
{
#line 330 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::disconnect_display_closed"
#line 126 "src/lm-tooltips.gob"
	g_return_if_fail (self != NULL);
#line 126 "src/lm-tooltips.gob"
	g_return_if_fail (LM_IS_TOOLTIPS (self));
#line 336 "lm-tooltips.c"
{
#line 128 "src/lm-tooltips.gob"
	
    g_signal_handlers_disconnect_by_func(gtk_widget_get_display(selfp->window),
					 self_display_closed_h,
					 self);
  }}
#line 344 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 134 "src/lm-tooltips.gob"
static void 
lm_tooltips_unset_window (LMTooltips * self)
{
#line 351 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::unset_window"
#line 134 "src/lm-tooltips.gob"
	g_return_if_fail (self != NULL);
#line 134 "src/lm-tooltips.gob"
	g_return_if_fail (LM_IS_TOOLTIPS (self));
#line 357 "lm-tooltips.c"
{
#line 136 "src/lm-tooltips.gob"
	
    if (selfp->window)
      {
	self_disconnect_display_closed(self);
	gtk_widget_destroy(selfp->window);
      }
  }}
#line 367 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 144 "src/lm-tooltips.gob"
static void 
lm_tooltips_update_screen (LMTooltips * self, gboolean new_window)
{
#line 374 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::update_screen"
#line 144 "src/lm-tooltips.gob"
	g_return_if_fail (self != NULL);
#line 144 "src/lm-tooltips.gob"
	g_return_if_fail (LM_IS_TOOLTIPS (self));
#line 380 "lm-tooltips.c"
{
#line 146 "src/lm-tooltips.gob"
	
    gboolean screen_changed = FALSE;

    if (selfp->active_data && selfp->active_data->widget)
      {
	GdkScreen *screen = gtk_widget_get_screen(selfp->active_data->widget);

	screen_changed = (screen != gtk_widget_get_screen(selfp->window));

	if (screen_changed)
	  {
	    if (! new_window)
	      self_disconnect_display_closed(self);

	    gtk_window_set_screen(GTK_WINDOW(selfp->window), screen);
	  }
      }

    if (screen_changed || new_window)
      g_signal_connect(gtk_widget_get_display(selfp->window),
		       "closed",
		       G_CALLBACK(self_display_closed_h),
		       self);
  }}
#line 407 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 171 "src/lm-tooltips.gob"
static void 
lm_tooltips_force_window (LMTooltips * self)
{
#line 414 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::force_window"
#line 171 "src/lm-tooltips.gob"
	g_return_if_fail (self != NULL);
#line 171 "src/lm-tooltips.gob"
	g_return_if_fail (LM_IS_TOOLTIPS (self));
#line 420 "lm-tooltips.c"
{
#line 173 "src/lm-tooltips.gob"
	
    if (! selfp->window)
      {
	selfp->window = gtk_window_new(GTK_WINDOW_POPUP);
	self_update_screen(self, TRUE);
	gtk_widget_set_app_paintable(selfp->window, TRUE);
	gtk_window_set_resizable(GTK_WINDOW(selfp->window), FALSE);
	gtk_widget_set_name(selfp->window, "gtk-tooltips");
	gtk_container_set_border_width(GTK_CONTAINER(selfp->window), selfp->border_width);

	g_signal_connect_swapped(selfp->window,
				 "expose-event",
				 G_CALLBACK(self_paint_window),
				 self);

	lm_add_weak_pointer(&selfp->window);
      }
  }}
#line 441 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 192 "src/lm-tooltips.gob"
static TooltipsData * 
lm_tooltips_get_data (GtkWidget * widget)
{
#line 448 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::get_data"
#line 192 "src/lm-tooltips.gob"
	g_return_val_if_fail (widget != NULL, (TooltipsData * )0);
#line 192 "src/lm-tooltips.gob"
	g_return_val_if_fail (GTK_IS_WIDGET (widget), (TooltipsData * )0);
#line 454 "lm-tooltips.c"
{
#line 194 "src/lm-tooltips.gob"
	
    return g_object_get_data(G_OBJECT(widget), TOOLTIPS_DATA);
  }}
#line 460 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 198 "src/lm-tooltips.gob"
static void 
lm_tooltips_set_tip_widget_real (LMTooltips * self, GtkWidget * widget, GtkWidget * tip_widget, int border_width)
{
#line 467 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::set_tip_widget_real"
#line 198 "src/lm-tooltips.gob"
	g_return_if_fail (self != NULL);
#line 198 "src/lm-tooltips.gob"
	g_return_if_fail (LM_IS_TOOLTIPS (self));
#line 198 "src/lm-tooltips.gob"
	g_return_if_fail (widget != NULL);
#line 198 "src/lm-tooltips.gob"
	g_return_if_fail (GTK_IS_WIDGET (widget));
#line 477 "lm-tooltips.c"
{
#line 203 "src/lm-tooltips.gob"
	
    TooltipsData *data;

    data = self_get_data(widget);

    if (! tip_widget)
      {
	if (data)
	  self_widget_remove(data->widget, data);
	return;
      }

    if (selfp->active_data
	&& selfp->active_data->widget == widget
	&& GTK_WIDGET_DRAWABLE(selfp->active_data->widget))
      {
	if (data->tip_widget)
	  g_object_unref(data->tip_widget);

	data->tip_widget = tip_widget;

	if (data->tip_widget)
	  g_object_ref_sink(data->tip_widget);

	self_draw_tips(self);
      }
    else
      {
	g_object_ref(widget);

	if (data)
	  self_widget_remove(data->widget, data);

	data = g_new0(TooltipsData, 1);
	data->self = self;
	data->widget = widget;
	data->tip_widget = tip_widget;

	if (data->tip_widget)
	  g_object_ref_sink(data->tip_widget);

	selfp->data_list = g_slist_append(selfp->data_list, data);
	g_signal_connect_after(widget, "event-after", G_CALLBACK(self_event_after_h), data);

	g_object_set_data(G_OBJECT(widget), TOOLTIPS_DATA, data);

	g_object_connect(widget,
			 "signal::unmap", self_widget_unmap, data,
			 "signal::unrealize", self_widget_unmap, data,
			 "signal::destroy", self_widget_remove, data,
			 NULL);
      }

    selfp->border_width = border_width;
    if (selfp->window)
      gtk_container_set_border_width(GTK_CONTAINER(selfp->window), border_width);
  }}
#line 537 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 261 "src/lm-tooltips.gob"
void 
lm_tooltips_set_tip (LMTooltips * self, GtkWidget * widget, const char * tip_text)
{
#line 544 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::set_tip"
#line 261 "src/lm-tooltips.gob"
	g_return_if_fail (self != NULL);
#line 261 "src/lm-tooltips.gob"
	g_return_if_fail (LM_IS_TOOLTIPS (self));
#line 261 "src/lm-tooltips.gob"
	g_return_if_fail (widget != NULL);
#line 261 "src/lm-tooltips.gob"
	g_return_if_fail (GTK_IS_WIDGET (widget));
#line 554 "lm-tooltips.c"
{
#line 265 "src/lm-tooltips.gob"
	
    GtkWidget *label = NULL;

    if (tip_text)
      {
	label = gtk_label_new(tip_text);
	gtk_label_set_line_wrap(GTK_LABEL(label), TRUE);
	gtk_misc_set_alignment(GTK_MISC(label), 0.5, 0.5);
	gtk_widget_show(label);
      }

    self_set_tip_widget_real(self, widget, label, 4);
  }}
#line 570 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 279 "src/lm-tooltips.gob"
void 
lm_tooltips_set_tip_widget (LMTooltips * self, GtkWidget * widget, GtkWidget * tip_widget)
{
#line 577 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::set_tip_widget"
#line 279 "src/lm-tooltips.gob"
	g_return_if_fail (self != NULL);
#line 279 "src/lm-tooltips.gob"
	g_return_if_fail (LM_IS_TOOLTIPS (self));
#line 279 "src/lm-tooltips.gob"
	g_return_if_fail (widget != NULL);
#line 279 "src/lm-tooltips.gob"
	g_return_if_fail (GTK_IS_WIDGET (widget));
#line 587 "lm-tooltips.c"
{
#line 283 "src/lm-tooltips.gob"
	
    self_set_tip_widget_real(self, widget, tip_widget, 12);
  }}
#line 593 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 287 "src/lm-tooltips.gob"
static gboolean 
lm_tooltips_paint_window (LMTooltips * self)
{
#line 600 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::paint_window"
#line 287 "src/lm-tooltips.gob"
	g_return_val_if_fail (self != NULL, (gboolean )0);
#line 287 "src/lm-tooltips.gob"
	g_return_val_if_fail (LM_IS_TOOLTIPS (self), (gboolean )0);
#line 606 "lm-tooltips.c"
{
#line 289 "src/lm-tooltips.gob"
	
    GtkRequisition req;

    gtk_widget_size_request(selfp->window, &req);
    gtk_paint_flat_box(selfp->window->style,
		       selfp->window->window,
		       GTK_STATE_NORMAL,
		       GTK_SHADOW_OUT,
		       NULL,
		       selfp->window,
		       "tooltip",
		       0,
		       0,
		       req.width,
		       req.height);

    return FALSE;
  }}
#line 627 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 308 "src/lm-tooltips.gob"
static void 
lm_tooltips_draw_tips (LMTooltips * self)
{
#line 634 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::draw_tips"
#line 308 "src/lm-tooltips.gob"
	g_return_if_fail (self != NULL);
#line 308 "src/lm-tooltips.gob"
	g_return_if_fail (LM_IS_TOOLTIPS (self));
#line 640 "lm-tooltips.c"
{
#line 310 "src/lm-tooltips.gob"
	
    GtkRequisition requisition;
    GtkWidget *widget;
    gint x, y, w, h;
    TooltipsData *data;
    GtkWidget *child;
    gboolean keyboard_mode;
    GdkScreen *screen;
    GdkScreen *pointer_screen;
    gint monitor_num, px, py;
    GdkRectangle monitor;
    int screen_width;

    if (! selfp->window)
      self_force_window(self);
    else if (GTK_WIDGET_VISIBLE(selfp->window))
      g_get_current_time(&selfp->last_popdown);

    gtk_widget_ensure_style(selfp->window);

    widget = selfp->active_data->widget;
    g_object_set_data(G_OBJECT(selfp->window), TOOLTIPS_INFO, self);

    keyboard_mode = self_get_keyboard_mode(widget);

    self_update_screen(self, FALSE);

    screen = gtk_widget_get_screen(widget);

    data = selfp->active_data;

    child = GTK_BIN(selfp->window)->child;
    if (child)
      gtk_container_remove(GTK_CONTAINER(selfp->window), child);

    if (data->tip_widget)
      {
	gtk_container_add(GTK_CONTAINER(selfp->window), data->tip_widget);
	gtk_widget_show(data->tip_widget);
      }

    gtk_widget_size_request(selfp->window, &requisition);
    w = requisition.width;
    h = requisition.height;

    gdk_window_get_origin(widget->window, &x, &y);
    if (GTK_WIDGET_NO_WINDOW(widget))
      {
	x += widget->allocation.x;
	y += widget->allocation.y;
      }

    x += widget->allocation.width / 2;

    if (! keyboard_mode)
      gdk_window_get_pointer(gdk_screen_get_root_window(screen), &x, NULL, NULL);

    x -= (w / 2 + 4);

    gdk_display_get_pointer(gdk_screen_get_display(screen), &pointer_screen, &px, &py, NULL);
    if (pointer_screen != screen)
      {
	px = x;
	py = y;
      }
    monitor_num = gdk_screen_get_monitor_at_point(screen, px, py);
    gdk_screen_get_monitor_geometry(screen, monitor_num, &monitor);

    if ((x + w) > monitor.x + monitor.width)
      x -= (x + w) - (monitor.x + monitor.width);
    else if (x < monitor.x)
      x = monitor.x;

    if ((y + h + widget->allocation.height + 4) > monitor.y + monitor.height
	&& (y - 4) > monitor.y)
      y = y - h - 4;
    else
      y = y + widget->allocation.height + 4;

    /*
     * The following block is not part of GTK+ and has been added to
     * make sure that the tooltip will not go beyond the screen edges
     * (horizontally).
     */
    screen_width = gdk_screen_get_width(screen);
    if (x < 0 || x + w > screen_width)
      {
	x = 0;
	gtk_widget_set_size_request(selfp->window, MIN(w, screen_width), -1);
      }

    gtk_window_move(GTK_WINDOW(selfp->window), x, y);
    gtk_widget_show(selfp->window);
  }}
#line 737 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 405 "src/lm-tooltips.gob"
static gboolean 
lm_tooltips_timeout_cb (gpointer data)
{
#line 744 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::timeout_cb"
{
#line 407 "src/lm-tooltips.gob"
	
    Self *self = SELF(data);

    if (selfp->active_data != NULL && GTK_WIDGET_DRAWABLE(selfp->active_data->widget))
      self_draw_tips(self);

    selfp->timeout_id = 0;
    return FALSE;		/* remove timeout */
  }}
#line 757 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 417 "src/lm-tooltips.gob"
static void 
lm_tooltips_set_active_widget (LMTooltips * self, GtkWidget * widget)
{
#line 764 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::set_active_widget"
#line 417 "src/lm-tooltips.gob"
	g_return_if_fail (self != NULL);
#line 417 "src/lm-tooltips.gob"
	g_return_if_fail (LM_IS_TOOLTIPS (self));
#line 770 "lm-tooltips.c"
{
#line 419 "src/lm-tooltips.gob"
	
    if (selfp->window)
      {
	if (GTK_WIDGET_VISIBLE(selfp->window))
	  g_get_current_time(&selfp->last_popdown);
	gtk_widget_hide(selfp->window);
      }

    lm_source_clear(&selfp->timeout_id);

    selfp->active_data = NULL;

    if (widget)
      {
	GSList *l;

	LM_LIST_FOREACH(l, selfp->data_list)
	  {
	    TooltipsData *data = l->data;

	    if (data->widget == widget && GTK_WIDGET_DRAWABLE(widget))
	      {
		selfp->active_data = data;
		break;
	      }
	  }
      }
    else
      selfp->use_sticky_delay = FALSE;
  }}
#line 803 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 450 "src/lm-tooltips.gob"
static void 
lm_tooltips_show_tip (GtkWidget * widget)
{
#line 810 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::show_tip"
#line 450 "src/lm-tooltips.gob"
	g_return_if_fail (widget != NULL);
#line 450 "src/lm-tooltips.gob"
	g_return_if_fail (GTK_IS_WIDGET (widget));
#line 816 "lm-tooltips.c"
{
#line 452 "src/lm-tooltips.gob"
	
    TooltipsData *data;

    data = self_get_data(widget);

    if (data &&
	(! data->self->_priv->active_data ||
	 data->self->_priv->active_data->widget != widget))
      {
	self_set_active_widget(data->self, widget);
	self_draw_tips(data->self);
      }
  }}
#line 832 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 466 "src/lm-tooltips.gob"
static void 
lm_tooltips_hide_tip (GtkWidget * widget)
{
#line 839 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::hide_tip"
#line 466 "src/lm-tooltips.gob"
	g_return_if_fail (widget != NULL);
#line 466 "src/lm-tooltips.gob"
	g_return_if_fail (GTK_IS_WIDGET (widget));
#line 845 "lm-tooltips.c"
{
#line 468 "src/lm-tooltips.gob"
	
    TooltipsData *data;

    data = self_get_data(widget);

    if (data &&
	(data->self->_priv->active_data &&
	 data->self->_priv->active_data->widget == widget))
      self_set_active_widget(data->self, NULL);
  }}
#line 858 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 479 "src/lm-tooltips.gob"
static gboolean 
lm_tooltips_recently_shown (LMTooltips * self)
{
#line 865 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::recently_shown"
#line 479 "src/lm-tooltips.gob"
	g_return_val_if_fail (self != NULL, (gboolean )0);
#line 479 "src/lm-tooltips.gob"
	g_return_val_if_fail (LM_IS_TOOLTIPS (self), (gboolean )0);
#line 871 "lm-tooltips.c"
{
#line 481 "src/lm-tooltips.gob"
	
    GTimeVal now;
    glong msec;

    g_get_current_time (&now);
    msec = (now.tv_sec - selfp->last_popdown.tv_sec) * 1000 +
      (now.tv_usec - selfp->last_popdown.tv_usec) / 1000;
    return (msec < STICKY_REVERT_DELAY);
  }}
#line 883 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 491 "src/lm-tooltips.gob"
static gboolean 
lm_tooltips_get_keyboard_mode (GtkWidget * widget)
{
#line 890 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::get_keyboard_mode"
#line 491 "src/lm-tooltips.gob"
	g_return_val_if_fail (widget != NULL, (gboolean )0);
#line 491 "src/lm-tooltips.gob"
	g_return_val_if_fail (GTK_IS_WIDGET (widget), (gboolean )0);
#line 896 "lm-tooltips.c"
{
#line 493 "src/lm-tooltips.gob"
	
    GtkWidget *toplevel = gtk_widget_get_toplevel(widget);

    if (GTK_IS_WINDOW(toplevel))
      return GPOINTER_TO_INT(g_object_get_data(G_OBJECT(toplevel), TOOLTIPS_KEYBOARD_MODE));
    else
      return FALSE;
  }}
#line 907 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 502 "src/lm-tooltips.gob"
static void 
lm_tooltips_start_keyboard_mode (GtkWidget * widget)
{
#line 914 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::start_keyboard_mode"
#line 502 "src/lm-tooltips.gob"
	g_return_if_fail (widget != NULL);
#line 502 "src/lm-tooltips.gob"
	g_return_if_fail (GTK_IS_WIDGET (widget));
#line 920 "lm-tooltips.c"
{
#line 504 "src/lm-tooltips.gob"
	
    GtkWidget *toplevel = gtk_widget_get_toplevel(widget);

    if (GTK_IS_WINDOW(toplevel))
      {
	GtkWidget *focus = GTK_WINDOW(toplevel)->focus_widget;

	g_object_set_data(G_OBJECT(toplevel), TOOLTIPS_KEYBOARD_MODE, GINT_TO_POINTER(TRUE));

	if (focus)
	  self_show_tip(focus);
      }
  }}
#line 936 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 518 "src/lm-tooltips.gob"
static void 
lm_tooltips_stop_keyboard_mode (GtkWidget * widget)
{
#line 943 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::stop_keyboard_mode"
#line 518 "src/lm-tooltips.gob"
	g_return_if_fail (widget != NULL);
#line 518 "src/lm-tooltips.gob"
	g_return_if_fail (GTK_IS_WIDGET (widget));
#line 949 "lm-tooltips.c"
{
#line 520 "src/lm-tooltips.gob"
	
    GtkWidget *toplevel = gtk_widget_get_toplevel(widget);

    if (GTK_IS_WINDOW(toplevel))
      {
	GtkWidget *focus = GTK_WINDOW(toplevel)->focus_widget;

	if (focus)
	  self_hide_tip(focus);

	g_object_set_data(G_OBJECT(toplevel), TOOLTIPS_KEYBOARD_MODE, GINT_TO_POINTER(FALSE));
      }
  }}
#line 965 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 534 "src/lm-tooltips.gob"
static void 
lm_tooltips_start_delay (LMTooltips * self, GtkWidget * widget)
{
#line 972 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::start_delay"
#line 534 "src/lm-tooltips.gob"
	g_return_if_fail (self != NULL);
#line 534 "src/lm-tooltips.gob"
	g_return_if_fail (LM_IS_TOOLTIPS (self));
#line 978 "lm-tooltips.c"
{
#line 536 "src/lm-tooltips.gob"
	
    TooltipsData *old_data;

    old_data = selfp->active_data;
    if (! old_data || old_data->widget != widget)
      {
	self_set_active_widget(self, widget);
	selfp->timeout_id = gdk_threads_add_timeout((selfp->use_sticky_delay && self_recently_shown(self)) ? STICKY_DELAY : DELAY,
						    self_timeout_cb,
						    self);
      }
  }}
#line 993 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 549 "src/lm-tooltips.gob"
static void 
lm_tooltips_event_after_h (GtkWidget * widget, GdkEvent * event, gpointer user_data)
{
#line 1000 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::event_after_h"
{
#line 551 "src/lm-tooltips.gob"
	
    Self *self;
    TooltipsData *old_data;
    GtkWidget *event_widget;
    gboolean keyboard_mode = self_get_keyboard_mode(widget);

    if ((event->type == GDK_LEAVE_NOTIFY || event->type == GDK_ENTER_NOTIFY) &&
	event->crossing.detail == GDK_NOTIFY_INFERIOR)
      return;

    old_data = self_get_data(widget);
    self = old_data->self;

    if (keyboard_mode)
      {
	switch (event->type)
	  {
	  case GDK_FOCUS_CHANGE:
	    if (event->focus_change.in)
	      self_show_tip(widget);
	    else
	      self_hide_tip(widget);
	    break;

	  default:
	    break;
	  }
      }
    else
      {
	if (event->type != GDK_KEY_PRESS && event->type != GDK_KEY_RELEASE)
	  {
	    event_widget = gtk_get_event_widget(event);
	    if (event_widget != widget)
	      return;
	  }

	switch (event->type)
	  {
	  case GDK_EXPOSE:
	    /* do nothing */
	    break;

	  case GDK_ENTER_NOTIFY:
	    if (! (GTK_IS_MENU_ITEM(widget) && GTK_MENU_ITEM(widget)->submenu))
	      self_start_delay(self, widget);
	    break;

	  case GDK_LEAVE_NOTIFY:
	    self_set_active_widget(self, NULL);
	    selfp->use_sticky_delay = selfp->window && GTK_WIDGET_VISIBLE(selfp->window);
	    break;

	  case GDK_MOTION_NOTIFY:
	    /* Handle menu items specially ... pend popup for each motion
	     * on other widgets, we ignore motion.
	     */
	    if (GTK_IS_MENU_ITEM(widget) && ! GTK_MENU_ITEM(widget)->submenu)
	      {
		/* Completely evil hack to make sure we get the LEAVE_NOTIFY
		 */
		GTK_PRIVATE_SET_FLAG(widget, GTK_LEAVE_PENDING);
		self_set_active_widget(self, NULL);
		self_start_delay(self, widget);
		break;
	      }
	    break;		/* ignore */

	  case GDK_BUTTON_PRESS:
	  case GDK_BUTTON_RELEASE:
	  case GDK_KEY_PRESS:
	  case GDK_KEY_RELEASE:
	  case GDK_PROXIMITY_IN:
	  case GDK_SCROLL:
	    self_set_active_widget(self, NULL);
	    break;

	  default:
	    break;
	  }
      }
  }}
#line 1086 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 634 "src/lm-tooltips.gob"
static void 
lm_tooltips_widget_unmap (GtkWidget * widget, gpointer user_data)
{
#line 1093 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::widget_unmap"
#line 634 "src/lm-tooltips.gob"
	g_return_if_fail (widget != NULL);
#line 634 "src/lm-tooltips.gob"
	g_return_if_fail (GTK_IS_WIDGET (widget));
#line 1099 "lm-tooltips.c"
{
#line 636 "src/lm-tooltips.gob"
	
    TooltipsData *data = user_data;
    Self *self = data->self;

    if (selfp->active_data &&
	(selfp->active_data->widget == widget))
      self_set_active_widget(self, NULL);
  }}
#line 1110 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 645 "src/lm-tooltips.gob"
static void 
lm_tooltips_widget_remove (GtkWidget * widget, gpointer user_data)
{
#line 1117 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::widget_remove"
#line 645 "src/lm-tooltips.gob"
	g_return_if_fail (widget != NULL);
#line 645 "src/lm-tooltips.gob"
	g_return_if_fail (GTK_IS_WIDGET (widget));
#line 1123 "lm-tooltips.c"
{
#line 647 "src/lm-tooltips.gob"
	
    TooltipsData *data = user_data;
    Self *self = data->self;

    self_widget_unmap(widget, user_data);
    selfp->data_list = g_slist_remove(selfp->data_list, data);
    self_destroy_data(data);
  }}
#line 1134 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 656 "src/lm-tooltips.gob"
void 
lm_tooltips_toggle_keyboard_mode (GtkWidget * widget)
{
#line 1141 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::toggle_keyboard_mode"
#line 656 "src/lm-tooltips.gob"
	g_return_if_fail (widget != NULL);
#line 656 "src/lm-tooltips.gob"
	g_return_if_fail (GTK_IS_WIDGET (widget));
#line 1147 "lm-tooltips.c"
{
#line 658 "src/lm-tooltips.gob"
	
    if (self_get_keyboard_mode(widget))
      self_stop_keyboard_mode(widget);
    else
      self_start_keyboard_mode(widget);
  }}
#line 1156 "lm-tooltips.c"
#undef __GOB_FUNCTION__

#line 665 "src/lm-tooltips.gob"
LMTooltips * 
lm_tooltips_new (void)
{
#line 1163 "lm-tooltips.c"
#define __GOB_FUNCTION__ "LM:Tooltips::new"
{
#line 667 "src/lm-tooltips.gob"
	
    return GET_NEW;
  }}
#line 1170 "lm-tooltips.c"
#undef __GOB_FUNCTION__
