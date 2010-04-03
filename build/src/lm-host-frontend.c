/* Generated by GOB (v2.0.15)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 15

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "lm-host-frontend.h"

#include "lm-host-frontend-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 39 "src/lm-host-frontend.gob"

#include <glib/gi18n.h>
#if WITH_GEOIP
#include <GeoIP.h>
#endif
#include "lm-util.h"
#include "lm-framed-image.h"

/* when changing, keep the 3:2 aspect ratio */
#define FLAG_WIDTH	36
#define FLAG_HEIGHT	24

#line 39 "lm-host-frontend.c"
/* self casting macros */
#define SELF(x) LM_HOST_FRONTEND(x)
#define SELF_CONST(x) LM_HOST_FRONTEND_CONST(x)
#define IS_SELF(x) LM_IS_HOST_FRONTEND(x)
#define TYPE_SELF LM_TYPE_HOST_FRONTEND
#define SELF_CLASS(x) LM_HOST_FRONTEND_CLASS(x)

#define SELF_GET_CLASS(x) LM_HOST_FRONTEND_GET_CLASS(x)

/* self typedefs */
typedef LMHostFrontend Self;
typedef LMHostFrontendClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
#line 0 "src/lm-host-frontend.gob"
static void lm_host_frontend_init (LMHostFrontend * o);
#line 58 "lm-host-frontend.c"
#line 0 "src/lm-host-frontend.gob"
static void lm_host_frontend_class_init (LMHostFrontendClass * c);
#line 61 "lm-host-frontend.c"
#line 82 "src/lm-host-frontend.gob"
static void lm_host_frontend_constructor (LMHostFrontend * self);
#line 64 "lm-host-frontend.c"
#line 114 "src/lm-host-frontend.gob"
static void lm_host_frontend_dispose (LMHostFrontend * self);
#line 67 "lm-host-frontend.c"
#line 123 "src/lm-host-frontend.gob"
static void lm_host_frontend_update_tooltip_location (LMHostFrontend * self);
#line 70 "lm-host-frontend.c"
#line 188 "src/lm-host-frontend.gob"
static char * lm_host_frontend_get_last_reply_string (LMHostFrontend * self, int * next_update);
#line 73 "lm-host-frontend.c"
#line 222 "src/lm-host-frontend.gob"
static void lm_host_frontend_update_tooltip_status (LMHostFrontend * self);
#line 76 "lm-host-frontend.c"
#line 303 "src/lm-host-frontend.gob"
static gboolean lm_host_frontend_update_last_reply_cb (gpointer data);
#line 79 "lm-host-frontend.c"
#line 317 "src/lm-host-frontend.gob"
static void lm_host_frontend_update_data_set (LMHostFrontend * self);
#line 82 "lm-host-frontend.c"
#line 396 "src/lm-host-frontend.gob"
static guint16 lm_host_frontend_parse_color_channel (const char * str);
#line 85 "lm-host-frontend.c"

enum {
	PROP_0,
	PROP_COLOR,
	PROP_COUNTRY_NAME
};

/* pointer to the class of our parent */
static LMHostClass *parent_class = NULL;

/* Short form macros */
#define self_get_color lm_host_frontend_get_color
#define self_set_color lm_host_frontend_set_color
#define self_get_country_name lm_host_frontend_get_country_name
#define self_set_country_name lm_host_frontend_set_country_name
#define self_update_tooltip_location lm_host_frontend_update_tooltip_location
#define self_get_last_reply_string lm_host_frontend_get_last_reply_string
#define self_update_tooltip_status lm_host_frontend_update_tooltip_status
#define self_update_last_reply_cb lm_host_frontend_update_last_reply_cb
#define self_update_data_set lm_host_frontend_update_data_set
#define self_new lm_host_frontend_new
#define self_new_from_configuration lm_host_frontend_new_from_configuration
#define self_get_configuration lm_host_frontend_get_configuration
#define self_configuration_free lm_host_frontend_configuration_free
#define self_build_gconf_entry lm_host_frontend_build_gconf_entry
#define self_parse_color_channel lm_host_frontend_parse_color_channel
#define self_parse_gconf_entry lm_host_frontend_parse_gconf_entry
GType
lm_host_frontend_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (LMHostFrontendClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) lm_host_frontend_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (LMHostFrontend),
			0 /* n_preallocs */,
			(GInstanceInitFunc) lm_host_frontend_init,
			NULL
		};

		type = g_type_register_static (LM_TYPE_HOST, "LMHostFrontend", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((LMHostFrontend *)g_object_new(lm_host_frontend_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static LMHostFrontend * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static LMHostFrontend *
GET_NEW_VARG (const char *first, ...)
{
	LMHostFrontend *ret;
	va_list ap;
	va_start (ap, first);
	ret = (LMHostFrontend *)g_object_new_valist (lm_host_frontend_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static GObject *
___constructor (GType type, guint n_construct_properties, GObjectConstructParam *construct_properties)
{
#define __GOB_FUNCTION__ "LM:Host:Frontend::constructor"
	GObject *obj_self;
	LMHostFrontend *self;
	obj_self = G_OBJECT_CLASS (parent_class)->constructor (type, n_construct_properties, construct_properties);
	self = LM_HOST_FRONTEND (obj_self);
#line 82 "src/lm-host-frontend.gob"
	lm_host_frontend_constructor (self);
#line 166 "lm-host-frontend.c"
	return obj_self;
}
#undef __GOB_FUNCTION__


static void
___dispose (GObject *obj_self)
{
#define __GOB_FUNCTION__ "LM:Host:Frontend::dispose"
	LMHostFrontend *self G_GNUC_UNUSED = LM_HOST_FRONTEND (obj_self);
#line 114 "src/lm-host-frontend.gob"
	lm_host_frontend_dispose (self);
#line 179 "lm-host-frontend.c"
	if (G_OBJECT_CLASS (parent_class)->dispose) \
		(* G_OBJECT_CLASS (parent_class)->dispose) (obj_self);
#line 71 "src/lm-host-frontend.gob"
	if(self->data_set) { g_object_unref ((gpointer) self->data_set); self->data_set = NULL; }
#line 184 "lm-host-frontend.c"
#line 73 "src/lm-host-frontend.gob"
	if(self->tooltip_flag) { g_object_unref ((gpointer) self->tooltip_flag); self->tooltip_flag = NULL; }
#line 187 "lm-host-frontend.c"
#line 74 "src/lm-host-frontend.gob"
	if(self->tooltip_status) { g_object_unref ((gpointer) self->tooltip_status); self->tooltip_status = NULL; }
#line 190 "lm-host-frontend.c"
}
#undef __GOB_FUNCTION__


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "LM:Host:Frontend::finalize"
	LMHostFrontend *self G_GNUC_UNUSED = LM_HOST_FRONTEND (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#line 68 "src/lm-host-frontend.gob"
	if(self->_priv->country_name) { g_free ((gpointer) self->_priv->country_name); self->_priv->country_name = NULL; }
#line 205 "lm-host-frontend.c"
}
#undef __GOB_FUNCTION__

static void 
lm_host_frontend_init (LMHostFrontend * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "LM:Host:Frontend::init"
	o->_priv = G_TYPE_INSTANCE_GET_PRIVATE(o,LM_TYPE_HOST_FRONTEND,LMHostFrontendPrivate);
}
#undef __GOB_FUNCTION__
static void 
lm_host_frontend_class_init (LMHostFrontendClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "LM:Host:Frontend::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	g_type_class_add_private(c,sizeof(LMHostFrontendPrivate));

	parent_class = g_type_class_ref (LM_TYPE_HOST);

	g_object_class->constructor = ___constructor;
	g_object_class->dispose = ___dispose;
	g_object_class->finalize = ___finalize;
	g_object_class->get_property = ___object_get_property;
	g_object_class->set_property = ___object_set_property;
    {
	GParamSpec   *param_spec;

	param_spec = g_param_spec_boxed
		("color" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 GDK_TYPE_COLOR /* boxed_type */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT));
	g_object_class_install_property (g_object_class,
		PROP_COLOR,
		param_spec);
	param_spec = g_param_spec_string
		("country_name" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 NULL /* default_value */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (g_object_class,
		PROP_COUNTRY_NAME,
		param_spec);
    }
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "LM:Host:Frontend::set_property"
{
	LMHostFrontend *self G_GNUC_UNUSED;

	self = LM_HOST_FRONTEND (object);

	switch (property_id) {
	case PROP_COLOR:
		{
#line 60 "src/lm-host-frontend.gob"

      lm_g_value_get_mandatory_color(VAL, &self->color);
    
#line 274 "lm-host-frontend.c"
		}
		break;
	case PROP_COUNTRY_NAME:
		{
#line 69 "src/lm-host-frontend.gob"
{ char *old = self->_priv->country_name; self->_priv->country_name = g_value_dup_string (VAL); g_free (old); }
#line 281 "lm-host-frontend.c"
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
#define __GOB_FUNCTION__ "LM:Host:Frontend::get_property"
{
	LMHostFrontend *self G_GNUC_UNUSED;

	self = LM_HOST_FRONTEND (object);

	switch (property_id) {
	case PROP_COLOR:
		{
#line 64 "src/lm-host-frontend.gob"

      g_value_set_boxed(VAL, &self->color);
    
#line 314 "lm-host-frontend.c"
		}
		break;
	case PROP_COUNTRY_NAME:
		{
#line 69 "src/lm-host-frontend.gob"
g_value_set_string (VAL, self->_priv->country_name);
#line 321 "lm-host-frontend.c"
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



#line 64 "src/lm-host-frontend.gob"
const GdkColor * 
lm_host_frontend_get_color (LMHostFrontend * self)
{
#line 342 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::get_color"
{
#line 55 "src/lm-host-frontend.gob"
		const GdkColor* val; g_object_get (G_OBJECT (self), "color", &val, NULL); return val;
}}
#line 348 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 60 "src/lm-host-frontend.gob"
void 
lm_host_frontend_set_color (LMHostFrontend * self, const GdkColor * val)
{
#line 355 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::set_color"
{
#line 55 "src/lm-host-frontend.gob"
		g_object_set (G_OBJECT (self), "color", val, NULL);
}}
#line 361 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 69 "src/lm-host-frontend.gob"
gchar * 
lm_host_frontend_get_country_name (LMHostFrontend * self)
{
#line 368 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::get_country_name"
{
#line 69 "src/lm-host-frontend.gob"
		gchar* val; g_object_get (G_OBJECT (self), "country_name", &val, NULL); return val;
}}
#line 374 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 69 "src/lm-host-frontend.gob"
void 
lm_host_frontend_set_country_name (LMHostFrontend * self, gchar * val)
{
#line 381 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::set_country_name"
{
#line 69 "src/lm-host-frontend.gob"
		g_object_set (G_OBJECT (self), "country_name", val, NULL);
}}
#line 387 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 82 "src/lm-host-frontend.gob"
static void 
lm_host_frontend_constructor (LMHostFrontend * self)
{
#line 394 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::constructor"
{
#line 83 "src/lm-host-frontend.gob"
	
    self->data_set = lm_data_set_new(LM_HOST(self)->applet);

    self->tooltip_flag = lm_framed_image_new();

    self->tooltip_status = gtk_label_new(NULL);
    gtk_misc_set_alignment(GTK_MISC(self->tooltip_status), 0.0, 0.5);

    g_object_ref_sink(self->tooltip_flag);
    g_object_ref_sink(self->tooltip_status);

    lm_callback_init(&selfp->data_set_callback, (LMCallbackFunc) self_update_data_set, self);
    lm_callback_init(&selfp->tooltip_location_callback, (LMCallbackFunc) self_update_tooltip_location, self);
    lm_callback_init(&selfp->tooltip_status_callback, (LMCallbackFunc) self_update_tooltip_status, self);

    g_object_connect(self,
		     "swapped-signal::notify::ip", lm_callback_queue, &selfp->tooltip_location_callback,
		     "swapped-signal::notify::ip", lm_callback_queue, &selfp->tooltip_status_callback,
		     "swapped-signal::notify::country-name", lm_callback_queue, &selfp->tooltip_status_callback,
		     "swapped-signal::notify::resolving", lm_callback_queue, &selfp->tooltip_status_callback,
		     "swapped-signal::notify::error", lm_callback_queue, &selfp->tooltip_status_callback,
		     "swapped-signal::notify::alive", lm_callback_queue, &selfp->data_set_callback,
		     "swapped-signal::notify::alive", lm_callback_queue, &selfp->tooltip_status_callback,
		     "swapped-signal::notify::roundtrip-time", lm_callback_queue, &selfp->data_set_callback,
		     "swapped-signal::notify::roundtrip-time", lm_callback_queue, &selfp->tooltip_status_callback,
		     NULL);

    self_update_tooltip_location(self);
    self_update_tooltip_status(self);
  }}
#line 428 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 114 "src/lm-host-frontend.gob"
static void 
lm_host_frontend_dispose (LMHostFrontend * self)
{
#line 435 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::dispose"
{
#line 115 "src/lm-host-frontend.gob"
	
    lm_source_clear(&selfp->update_last_reply_timeout_id);

    lm_callback_clear(&selfp->data_set_callback);
    lm_callback_clear(&selfp->tooltip_location_callback);
    lm_callback_clear(&selfp->tooltip_status_callback);
  }}
#line 446 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 123 "src/lm-host-frontend.gob"
static void 
lm_host_frontend_update_tooltip_location (LMHostFrontend * self)
{
#line 453 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::update_tooltip_location"
#line 123 "src/lm-host-frontend.gob"
	g_return_if_fail (self != NULL);
#line 123 "src/lm-host-frontend.gob"
	g_return_if_fail (LM_IS_HOST_FRONTEND (self));
#line 459 "lm-host-frontend.c"
{
#line 125 "src/lm-host-frontend.gob"
	
#if WITH_GEOIP
    LMHost *host = LM_HOST(self);
    GdkPixbuf *flag = NULL;
    char *country_name = NULL;

    if (host->ip)
      {
	GeoIP *geoip;

	geoip = GeoIP_new(0);
	if (geoip)
	  {
	    const char *country_code;

	    country_code = GeoIP_country_code_by_addr(geoip, host->ip);
	    if (country_code)
	      {
		char *base;
		char *filename;
		char *pathname;

		base = g_ascii_strdown(country_code, -1);
		filename = g_strconcat(base, ".svg", NULL);
		g_free(base);

		pathname = g_build_filename(PKGDATADIR, "flags", filename, NULL);
		g_free(filename);

		if (g_file_test(pathname, G_FILE_TEST_EXISTS))
		  {
		    GError *err = NULL;
		    GdkPixbuf *raw;

		    raw = gdk_pixbuf_new_from_file(pathname, &err);
		    if (raw)
		      {
			flag = gdk_pixbuf_scale_simple(raw, FLAG_WIDTH, FLAG_HEIGHT, GDK_INTERP_BILINEAR);
			g_object_unref(raw);
		      }
		    else
		      {
			g_warning("unable to load %s: %s", pathname, err->message);
			g_error_free(err);
		      }
		  }
		g_free(pathname);
	      }

	    country_name = g_strdup(GeoIP_country_name_by_addr(geoip, host->ip));
	    GeoIP_delete(geoip);
	  }
      }

    lm_framed_image_set_pixbuf(LM_FRAMED_IMAGE(self->tooltip_flag), flag);
    if (flag)
      g_object_unref(flag);

    self_set_country_name(self, country_name);
    g_free(country_name);
#endif
  }}
#line 524 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 188 "src/lm-host-frontend.gob"
static char * 
lm_host_frontend_get_last_reply_string (LMHostFrontend * self, int * next_update)
{
#line 531 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::get_last_reply_string"
#line 188 "src/lm-host-frontend.gob"
	g_return_val_if_fail (self != NULL, (char * )0);
#line 188 "src/lm-host-frontend.gob"
	g_return_val_if_fail (LM_IS_HOST_FRONTEND (self), (char * )0);
#line 188 "src/lm-host-frontend.gob"
	g_return_val_if_fail (next_update != NULL, (char * )0);
#line 539 "lm-host-frontend.c"
{
#line 190 "src/lm-host-frontend.gob"
	
    LMHost *host = LM_HOST(self);
    char *str = NULL;

    if (host->last_received_ticks)
      {
	LMTimeSpan diff;
	int secs;

	diff = lm_get_ticks() - host->last_received_ticks;
	secs = (int) (diff / G_USEC_PER_SEC);

	if (secs >= 10)
	  {
	    if (secs < 60)
	      str = g_strdup_printf(_("last reply: %i” ago"), secs);
	    else if (secs < 60 * 60)
	      str = g_strdup_printf(_("last reply: %.2i:%.2i” ago"), secs / 60, secs % 60);
	    else
	      str = g_strdup_printf(_("last reply: %.2i:%.2i:%.2i” ago"), secs / (60 * 60), (secs % (60 * 60)) / 60, secs % 60);
	  }

	/* run again when the seconds of difference will change */

	*next_update = (1000000 - (diff % 1000000)) / 1000 + 1;
      }
    else
      *next_update = -1;

    return str;
  }}
#line 573 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 222 "src/lm-host-frontend.gob"
static void 
lm_host_frontend_update_tooltip_status (LMHostFrontend * self)
{
#line 580 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::update_tooltip_status"
#line 222 "src/lm-host-frontend.gob"
	g_return_if_fail (self != NULL);
#line 222 "src/lm-host-frontend.gob"
	g_return_if_fail (LM_IS_HOST_FRONTEND (self));
#line 586 "lm-host-frontend.c"
{
#line 224 "src/lm-host-frontend.gob"
	
    LMHost *host = LM_HOST(self);
    GString *markup;
    char *escaped_name;

    markup = g_string_new(NULL);

    escaped_name = g_markup_escape_text(host->name, -1);
    g_string_append_printf(markup, "<span weight=\"bold\">%s</span>", escaped_name);
    g_free(escaped_name);

    if (host->resolving)
      g_string_append_printf(markup, " (%s)", _("resolving hostname"));
    else
      {
	char *escaped_country_name = NULL;

	if (selfp->country_name)
	  escaped_country_name = g_markup_escape_text(selfp->country_name, -1);

	if (host->ip && strcmp(host->ip, host->name))
	  {
	    if (escaped_country_name)
	      g_string_append_printf(markup, " (%s, %s)", escaped_country_name, host->ip);
	    else
	      g_string_append_printf(markup, " (%s)", host->ip);
	  }
	else if (escaped_country_name)
	  g_string_append_printf(markup, " (%s)", escaped_country_name);

	g_free(escaped_country_name);
      }

    if (host->alive)
      {
	lm_source_clear(&selfp->update_last_reply_timeout_id);

	g_string_append_c(markup, '\n');
	g_string_append_printf(markup, _("%i ms"), (int) (host->roundtrip_time / 1000));
      }
    else
      {
	const char *error;
	char *escaped_error = NULL;
	char *last_reply;
	int next_update;

	error = lm_host_get_error(host);
	if (error)
	  escaped_error = g_markup_escape_text(error, -1);

	last_reply = self_get_last_reply_string(self, &next_update);
	if (last_reply)
	  {
	    if (escaped_error)
	      g_string_append_printf(markup, "\n%s (%s)", escaped_error, last_reply);
	    else
	      g_string_append_printf(markup, "\n%s", last_reply);

	    g_free(last_reply);
	  }
	else
	  {
	    if (escaped_error)
	      g_string_append_printf(markup, "\n%s", escaped_error);
	  }

	g_free(escaped_error);

	if (next_update == -1)
	  g_assert(selfp->update_last_reply_timeout_id == 0);
	else
	  selfp->update_last_reply_timeout_id = gdk_threads_add_timeout(next_update, self_update_last_reply_cb, self);
      }

    gtk_label_set_markup(GTK_LABEL(self->tooltip_status), markup->str);
    g_string_free(markup, TRUE);
  }}
#line 667 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 303 "src/lm-host-frontend.gob"
static gboolean 
lm_host_frontend_update_last_reply_cb (gpointer data)
{
#line 674 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::update_last_reply_cb"
{
#line 305 "src/lm-host-frontend.gob"
	
    Self *self = data;

    lm_callback_queue(&selfp->tooltip_status_callback);

    /*
     * The timeout was reinstalled in
     * update_tooltip_status(), remove this one.
     */
    return FALSE;
  }}
#line 689 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 317 "src/lm-host-frontend.gob"
static void 
lm_host_frontend_update_data_set (LMHostFrontend * self)
{
#line 696 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::update_data_set"
#line 317 "src/lm-host-frontend.gob"
	g_return_if_fail (self != NULL);
#line 317 "src/lm-host-frontend.gob"
	g_return_if_fail (LM_IS_HOST_FRONTEND (self));
#line 702 "lm-host-frontend.c"
{
#line 319 "src/lm-host-frontend.gob"
	
    LMHost *host = LM_HOST(self);

    if (host->alive)
      lm_data_set_add_live_data_point(self->data_set, host->roundtrip_time);
    else
      lm_data_set_add_dead_data_point(self->data_set);
  }}
#line 713 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 328 "src/lm-host-frontend.gob"
LMHostFrontend * 
lm_host_frontend_new (LMApplet * applet, const char * name, const GdkColor * color)
{
#line 720 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::new"
#line 328 "src/lm-host-frontend.gob"
	g_return_val_if_fail (applet != NULL, (LMHostFrontend * )0);
#line 328 "src/lm-host-frontend.gob"
	g_return_val_if_fail (LM_IS_APPLET (applet), (LMHostFrontend * )0);
#line 328 "src/lm-host-frontend.gob"
	g_return_val_if_fail (name != NULL, (LMHostFrontend * )0);
#line 728 "lm-host-frontend.c"
{
#line 332 "src/lm-host-frontend.gob"
	
    GdkColor auto_color;

    if (! color)
      {
	lm_applet_get_host_color(applet, name, &auto_color);
	color = &auto_color;
      }

    return GET_NEW_VARG(LM_HOST_PROP_APPLET(applet),
			LM_HOST_PROP_NAME((char *) name),
			LM_HOST_FRONTEND_PROP_COLOR(color),
			NULL);
  }}
#line 745 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 347 "src/lm-host-frontend.gob"
LMHostFrontend * 
lm_host_frontend_new_from_configuration (LMApplet * applet, LMHostFrontendConfiguration * config)
{
#line 752 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::new_from_configuration"
#line 347 "src/lm-host-frontend.gob"
	g_return_val_if_fail (applet != NULL, (LMHostFrontend * )0);
#line 347 "src/lm-host-frontend.gob"
	g_return_val_if_fail (LM_IS_APPLET (applet), (LMHostFrontend * )0);
#line 347 "src/lm-host-frontend.gob"
	g_return_val_if_fail (config != NULL, (LMHostFrontend * )0);
#line 760 "lm-host-frontend.c"
{
#line 350 "src/lm-host-frontend.gob"
	
    return self_new(applet, config->name, &config->color);
  }}
#line 766 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 354 "src/lm-host-frontend.gob"
LMHostFrontendConfiguration * 
lm_host_frontend_get_configuration (LMHostFrontend * self)
{
#line 773 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::get_configuration"
#line 354 "src/lm-host-frontend.gob"
	g_return_val_if_fail (self != NULL, (LMHostFrontendConfiguration * )0);
#line 354 "src/lm-host-frontend.gob"
	g_return_val_if_fail (LM_IS_HOST_FRONTEND (self), (LMHostFrontendConfiguration * )0);
#line 779 "lm-host-frontend.c"
{
#line 356 "src/lm-host-frontend.gob"
	
    LMHostFrontendConfiguration *config;

    config = g_new0(LMHostFrontendConfiguration, 1);
    config->name = g_strdup(LM_HOST(self)->name);
    config->color = self->color;

    return config;
  }}
#line 791 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 366 "src/lm-host-frontend.gob"
void 
lm_host_frontend_configuration_free (LMHostFrontendConfiguration * config)
{
#line 798 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::configuration_free"
#line 366 "src/lm-host-frontend.gob"
	g_return_if_fail (config != NULL);
#line 802 "lm-host-frontend.c"
{
#line 368 "src/lm-host-frontend.gob"
	
    g_free(config->name);
    g_free(config);
  }}
#line 809 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 373 "src/lm-host-frontend.gob"
char * 
lm_host_frontend_build_gconf_entry (LMHostFrontend * self)
{
#line 816 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::build_gconf_entry"
#line 373 "src/lm-host-frontend.gob"
	g_return_val_if_fail (self != NULL, (char * )0);
#line 373 "src/lm-host-frontend.gob"
	g_return_val_if_fail (LM_IS_HOST_FRONTEND (self), (char * )0);
#line 822 "lm-host-frontend.c"
{
#line 375 "src/lm-host-frontend.gob"
	
    LMHost *host = LM_HOST(self);
    GString *str;
    int i;

    str = g_string_new(NULL);

    for (i = 0; host->name[i]; i++)
      if (host->name[i] == '|' || host->name[i] == '\\')
	g_string_append_printf(str, "\\%c", host->name[i]);
      else
	g_string_append_c(str, host->name[i]);

    g_string_append_printf(str, "|#%02X%02X%02X",
			   self->color.red / 256,
			   self->color.green / 256,
			   self->color.blue / 256);

    return g_string_free(str, FALSE);
  }}
#line 845 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 396 "src/lm-host-frontend.gob"
static guint16 
lm_host_frontend_parse_color_channel (const char * str)
{
#line 852 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::parse_color_channel"
{
#line 398 "src/lm-host-frontend.gob"
	
    return (g_ascii_xdigit_value(str[0]) * 16 + g_ascii_xdigit_value(str[1])) * 256;
  }}
#line 859 "lm-host-frontend.c"
#undef __GOB_FUNCTION__

#line 402 "src/lm-host-frontend.gob"
LMHostFrontend * 
lm_host_frontend_parse_gconf_entry (LMApplet * applet, const char * entry)
{
#line 866 "lm-host-frontend.c"
#define __GOB_FUNCTION__ "LM:Host:Frontend::parse_gconf_entry"
#line 402 "src/lm-host-frontend.gob"
	g_return_val_if_fail (applet != NULL, (LMHostFrontend * )0);
#line 402 "src/lm-host-frontend.gob"
	g_return_val_if_fail (LM_IS_APPLET (applet), (LMHostFrontend * )0);
#line 402 "src/lm-host-frontend.gob"
	g_return_val_if_fail (entry != NULL, (LMHostFrontend * )0);
#line 874 "lm-host-frontend.c"
{
#line 405 "src/lm-host-frontend.gob"
	
    GString *name;
    const char *color_str = NULL;
    Self *self = NULL;
    int i;

    name = g_string_new(NULL);

    for (i = 0; entry[i]; i++)
      if (entry[i] == '\\')
	{
	  i++;
	  if (entry[i] == '|' || entry[i] == '\\')
	    g_string_append_c(name, entry[i]);
	  else
	    goto end;
	}
      else if (entry[i] == '|')
	{
	  color_str = &entry[i + 1];
	  break;
	}
      else
	g_string_append_c(name, entry[i]);

    if (color_str)
      {
	GdkColor color;

	if (color_str[0] != '#')
	  goto end;

	for (i = 1; i < 7; i++)
	  if (! g_ascii_isxdigit(color_str[i]))
	    goto end;

	if (color_str[7] != 0)
	  goto end;

	color.pixel = 0;
	color.red = self_parse_color_channel(&color_str[1]);
	color.green = self_parse_color_channel(&color_str[3]);
	color.blue = self_parse_color_channel(&color_str[5]);

	self = self_new(applet, name->str, &color);
      }
    else
      self = self_new(applet, name->str, NULL);

  end:
    g_string_free(name, TRUE);
    return self;
  }}
#line 930 "lm-host-frontend.c"
#undef __GOB_FUNCTION__
