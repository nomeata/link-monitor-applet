/* Generated by GOB (v2.0.15)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 15

#define selfp (self->_priv)

#include "lm-host.h"

#include "lm-host-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 51 "src/lm-host.gob"

#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <glib/gi18n.h>
#include "lm-util.h"
#include "lm-applet.h"

#ifndef HAVE_REENTRANT_RESOLVER
G_LOCK_DEFINE_STATIC(resolver);
#endif

/* in milliseconds */
#define MIN_TIMEOUT		100
#define DEFAULT_TIMEOUT		1000

#line 43 "lm-host.c"
/* self casting macros */
#define SELF(x) LM_HOST(x)
#define SELF_CONST(x) LM_HOST_CONST(x)
#define IS_SELF(x) LM_IS_HOST(x)
#define TYPE_SELF LM_TYPE_HOST
#define SELF_CLASS(x) LM_HOST_CLASS(x)

#define SELF_GET_CLASS(x) LM_HOST_GET_CLASS(x)

/* self typedefs */
typedef LMHost Self;
typedef LMHostClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
#line 0 "src/lm-host.gob"
static void lm_host_init (LMHost * o);
#line 62 "lm-host.c"
#line 0 "src/lm-host.gob"
static void lm_host_class_init (LMHostClass * c);
#line 65 "lm-host.c"
#line 147 "src/lm-host.gob"
static void lm_host_set_error (LMHost * self, Error error, const char * format, ...) G_GNUC_PRINTF(3, 4);
#line 68 "lm-host.c"
#line 166 "src/lm-host.gob"
static void lm_host_clear_error (LMHost * self, Error error);
#line 71 "lm-host.c"
#line 180 "src/lm-host.gob"
static void lm_host_constructor (LMHost * self);
#line 74 "lm-host.c"
#line 191 "src/lm-host.gob"
static void lm_host_finalize (LMHost * self);
#line 77 "lm-host.c"
#line 203 "src/lm-host.gob"
static void lm_host_resolve (LMHost * self);
#line 80 "lm-host.c"
#line 214 "src/lm-host.gob"
static gpointer lm_host_resolve_thread_cb (gpointer data);
#line 83 "lm-host.c"
#line 327 "src/lm-host.gob"
static void lm_host_install_resolve_timeout (LMHost * self, int delay);
#line 86 "lm-host.c"
#line 334 "src/lm-host.gob"
static gboolean lm_host_resolve_timeout_cb (gpointer data);
#line 89 "lm-host.c"
#line 345 "src/lm-host.gob"
static void lm_host_send_echo_request (LMHost * self);
#line 92 "lm-host.c"
#line 388 "src/lm-host.gob"
static void lm_host_delay_changed_h (GObject * object, GParamSpec * pspec, gpointer user_data);
#line 95 "lm-host.c"
#line 401 "src/lm-host.gob"
static void lm_host_install_send_timeout (LMHost * self);
#line 98 "lm-host.c"
#line 412 "src/lm-host.gob"
static gboolean lm_host_send_timeout_cb (gpointer data);
#line 101 "lm-host.c"
#line 422 "src/lm-host.gob"
static gboolean lm_host_dead_timeout_cb (gpointer data);
#line 104 "lm-host.c"

enum {
	PROP_0,
	PROP_APPLET,
	PROP_NAME,
	PROP_RESOLVING,
	PROP_IP,
	PROP_ALIVE,
	PROP_ROUNDTRIP_TIME,
	PROP_ERROR
};

/* pointer to the class of our parent */
static GObjectClass *parent_class = NULL;

/* Short form macros */
#define self_get_resolving lm_host_get_resolving
#define self_set_resolving lm_host_set_resolving
#define self_get_alive lm_host_get_alive
#define self_set_alive lm_host_set_alive
#define self_get_roundtrip_time lm_host_get_roundtrip_time
#define self_set_roundtrip_time lm_host_set_roundtrip_time
#define self_get_error lm_host_get_error
#define self_set_error lm_host_set_error
#define self_clear_error lm_host_clear_error
#define self_resolve lm_host_resolve
#define self_resolve_thread_cb lm_host_resolve_thread_cb
#define self_install_resolve_timeout lm_host_install_resolve_timeout
#define self_resolve_timeout_cb lm_host_resolve_timeout_cb
#define self_send_echo_request lm_host_send_echo_request
#define self_delay_changed_h lm_host_delay_changed_h
#define self_install_send_timeout lm_host_install_send_timeout
#define self_send_timeout_cb lm_host_send_timeout_cb
#define self_dead_timeout_cb lm_host_dead_timeout_cb
#define self_reply_received lm_host_reply_received
GType
lm_host_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (LMHostClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) lm_host_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (LMHost),
			0 /* n_preallocs */,
			(GInstanceInitFunc) lm_host_init,
			NULL
		};

		type = g_type_register_static (G_TYPE_OBJECT, "LMHost", &info, (GTypeFlags)G_TYPE_FLAG_ABSTRACT);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((LMHost *)g_object_new(lm_host_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static LMHost * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static LMHost *
GET_NEW_VARG (const char *first, ...)
{
	LMHost *ret;
	va_list ap;
	va_start (ap, first);
	ret = (LMHost *)g_object_new_valist (lm_host_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static GObject *
___constructor (GType type, guint n_construct_properties, GObjectConstructParam *construct_properties)
{
#define __GOB_FUNCTION__ "LM:Host::constructor"
	GObject *obj_self;
	LMHost *self;
	obj_self = G_OBJECT_CLASS (parent_class)->constructor (type, n_construct_properties, construct_properties);
	self = LM_HOST (obj_self);
#line 180 "src/lm-host.gob"
	lm_host_constructor (self);
#line 193 "lm-host.c"
	return obj_self;
}
#undef __GOB_FUNCTION__


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "LM:Host::finalize"
	LMHost *self G_GNUC_UNUSED = LM_HOST (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
#line 191 "src/lm-host.gob"
	lm_host_finalize (self);
#line 207 "lm-host.c"
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#line 75 "src/lm-host.gob"
	if(self->name) { g_free ((gpointer) self->name); self->name = NULL; }
#line 212 "lm-host.c"
#line 78 "src/lm-host.gob"
	if(self->_priv->addrinfo) { freeaddrinfo ((gpointer) self->_priv->addrinfo); self->_priv->addrinfo = NULL; }
#line 215 "lm-host.c"
#line 84 "src/lm-host.gob"
	if(self->ip) { g_free ((gpointer) self->ip); self->ip = NULL; }
#line 218 "lm-host.c"
#define errors (self->_priv->errors)
#define VAR errors
	{
#line 127 "src/lm-host.gob"
	
      int i;

      for (i = 0; i < G_N_ELEMENTS(VAR); i++)
	g_free(VAR[i]);
    }
#line 229 "lm-host.c"
	memset(&errors, 0, sizeof(errors));
#undef VAR
#undef errors
}
#undef __GOB_FUNCTION__

static void 
lm_host_init (LMHost * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "LM:Host::init"
	o->_priv = G_TYPE_INSTANCE_GET_PRIVATE(o,LM_TYPE_HOST,LMHostPrivate);
}
#undef __GOB_FUNCTION__
static void 
lm_host_class_init (LMHostClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "LM:Host::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	g_type_class_add_private(c,sizeof(LMHostPrivate));

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
	param_spec = g_param_spec_string
		("name" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 NULL /* default_value */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (g_object_class,
		PROP_NAME,
		param_spec);
	param_spec = g_param_spec_boolean
		("resolving" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 FALSE /* default_value */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (g_object_class,
		PROP_RESOLVING,
		param_spec);
	param_spec = g_param_spec_string
		("ip" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 NULL /* default_value */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (g_object_class,
		PROP_IP,
		param_spec);
	param_spec = g_param_spec_boolean
		("alive" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 FALSE /* default_value */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (g_object_class,
		PROP_ALIVE,
		param_spec);
	param_spec = g_param_spec_int64
		("roundtrip_time" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 G_MININT64 /* minimum */,
		 G_MAXINT64 /* maximum */,
		 0 /* default_value */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (g_object_class,
		PROP_ROUNDTRIP_TIME,
		param_spec);
	param_spec = g_param_spec_string
		("error" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 NULL /* default_value */,
		 (GParamFlags)(G_PARAM_READABLE));
	g_object_class_install_property (g_object_class,
		PROP_ERROR,
		param_spec);
    }
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "LM:Host::set_property"
{
	LMHost *self G_GNUC_UNUSED;

	self = LM_HOST (object);

	switch (property_id) {
	case PROP_APPLET:
		{
#line 73 "src/lm-host.gob"
self->applet = g_value_get_pointer (VAL);
#line 344 "lm-host.c"
		}
		break;
	case PROP_NAME:
		{
#line 76 "src/lm-host.gob"
{ char *old = self->name; self->name = g_value_dup_string (VAL); g_free (old); }
#line 351 "lm-host.c"
		}
		break;
	case PROP_RESOLVING:
		{
#line 82 "src/lm-host.gob"
self->resolving = g_value_get_boolean (VAL);
#line 358 "lm-host.c"
		}
		break;
	case PROP_IP:
		{
#line 85 "src/lm-host.gob"
{ char *old = self->ip; self->ip = g_value_dup_string (VAL); g_free (old); }
#line 365 "lm-host.c"
		}
		break;
	case PROP_ALIVE:
		{
#line 93 "src/lm-host.gob"
self->alive = g_value_get_boolean (VAL);
#line 372 "lm-host.c"
		}
		break;
	case PROP_ROUNDTRIP_TIME:
		{
#line 104 "src/lm-host.gob"

      self->last_received_ticks = lm_get_ticks();
      lm_source_clear(&selfp->dead_timeout_id);

      self->roundtrip_time = g_value_get_int64(VAL);
      if (self->roundtrip_time > selfp->max_roundtrip_time)
	selfp->max_roundtrip_time = self->roundtrip_time;

      self_set_alive(self, TRUE);
    
#line 388 "lm-host.c"
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
#define __GOB_FUNCTION__ "LM:Host::get_property"
{
	LMHost *self G_GNUC_UNUSED;

	self = LM_HOST (object);

	switch (property_id) {
	case PROP_APPLET:
		{
#line 73 "src/lm-host.gob"
g_value_set_pointer (VAL, self->applet);
#line 419 "lm-host.c"
		}
		break;
	case PROP_NAME:
		{
#line 76 "src/lm-host.gob"
g_value_set_string (VAL, self->name);
#line 426 "lm-host.c"
		}
		break;
	case PROP_RESOLVING:
		{
#line 82 "src/lm-host.gob"
g_value_set_boolean (VAL, self->resolving);
#line 433 "lm-host.c"
		}
		break;
	case PROP_IP:
		{
#line 85 "src/lm-host.gob"
g_value_set_string (VAL, self->ip);
#line 440 "lm-host.c"
		}
		break;
	case PROP_ALIVE:
		{
#line 93 "src/lm-host.gob"
g_value_set_boolean (VAL, self->alive);
#line 447 "lm-host.c"
		}
		break;
	case PROP_ROUNDTRIP_TIME:
		{
#line 115 "src/lm-host.gob"

      g_value_set_int64(VAL, self->roundtrip_time);
    
#line 456 "lm-host.c"
		}
		break;
	case PROP_ERROR:
		{
#line 121 "src/lm-host.gob"

      g_value_set_string(VAL, self_get_error(self));
    
#line 465 "lm-host.c"
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



#line 82 "src/lm-host.gob"
gboolean 
lm_host_get_resolving (LMHost * self)
{
#line 486 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::get_resolving"
{
#line 82 "src/lm-host.gob"
		gboolean val; g_object_get (G_OBJECT (self), "resolving", &val, NULL); return val;
}}
#line 492 "lm-host.c"
#undef __GOB_FUNCTION__

#line 82 "src/lm-host.gob"
void 
lm_host_set_resolving (LMHost * self, gboolean val)
{
#line 499 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::set_resolving"
{
#line 82 "src/lm-host.gob"
		g_object_set (G_OBJECT (self), "resolving", val, NULL);
}}
#line 505 "lm-host.c"
#undef __GOB_FUNCTION__

#line 93 "src/lm-host.gob"
gboolean 
lm_host_get_alive (LMHost * self)
{
#line 512 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::get_alive"
{
#line 93 "src/lm-host.gob"
		gboolean val; g_object_get (G_OBJECT (self), "alive", &val, NULL); return val;
}}
#line 518 "lm-host.c"
#undef __GOB_FUNCTION__

#line 93 "src/lm-host.gob"
void 
lm_host_set_alive (LMHost * self, gboolean val)
{
#line 525 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::set_alive"
{
#line 93 "src/lm-host.gob"
		g_object_set (G_OBJECT (self), "alive", val, NULL);
}}
#line 531 "lm-host.c"
#undef __GOB_FUNCTION__

#line 115 "src/lm-host.gob"
LMTimeSpan 
lm_host_get_roundtrip_time (LMHost * self)
{
#line 538 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::get_roundtrip_time"
{
#line 102 "src/lm-host.gob"
		LMTimeSpan val; g_object_get (G_OBJECT (self), "roundtrip_time", &val, NULL); return val;
}}
#line 544 "lm-host.c"
#undef __GOB_FUNCTION__

#line 104 "src/lm-host.gob"
void 
lm_host_set_roundtrip_time (LMHost * self, LMTimeSpan val)
{
#line 551 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::set_roundtrip_time"
{
#line 102 "src/lm-host.gob"
		g_object_set (G_OBJECT (self), "roundtrip_time", val, NULL);
}}
#line 557 "lm-host.c"
#undef __GOB_FUNCTION__

#line 134 "src/lm-host.gob"
const char * 
lm_host_get_error (LMHost * self)
{
#line 564 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::get_error"
#line 134 "src/lm-host.gob"
	g_return_val_if_fail (self != NULL, (const char * )0);
#line 134 "src/lm-host.gob"
	g_return_val_if_fail (LM_IS_HOST (self), (const char * )0);
#line 570 "lm-host.c"
{
#line 136 "src/lm-host.gob"
	
    int i;

    for (i = 0; i < G_N_ELEMENTS(selfp->errors); i++)
      if (selfp->errors[i])
	return selfp->errors[i];

    return NULL;
  }}
#line 582 "lm-host.c"
#undef __GOB_FUNCTION__

#line 147 "src/lm-host.gob"
static void 
lm_host_set_error (LMHost * self, Error error, const char * format, ...)
{
#line 589 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::set_error"
#line 147 "src/lm-host.gob"
	g_return_if_fail (self != NULL);
#line 147 "src/lm-host.gob"
	g_return_if_fail (LM_IS_HOST (self));
#line 147 "src/lm-host.gob"
	g_return_if_fail (format != NULL);
#line 597 "lm-host.c"
{
#line 149 "src/lm-host.gob"
	
    va_list args;
    char *msg;

    va_start(args, format);
    msg = g_strdup_vprintf(format, args);
    va_end(args);

    g_free(selfp->errors[error]);
    selfp->errors[error] = msg;

    lm_source_clear(&selfp->dead_timeout_id);
    self_set_alive(self, FALSE);

    g_object_notify(G_OBJECT(self), "error");
  }}
#line 616 "lm-host.c"
#undef __GOB_FUNCTION__

#line 166 "src/lm-host.gob"
static void 
lm_host_clear_error (LMHost * self, Error error)
{
#line 623 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::clear_error"
#line 166 "src/lm-host.gob"
	g_return_if_fail (self != NULL);
#line 166 "src/lm-host.gob"
	g_return_if_fail (LM_IS_HOST (self));
#line 629 "lm-host.c"
{
#line 168 "src/lm-host.gob"
	
    if (! selfp->errors[error])
      return;

    g_free(selfp->errors[error]);
    selfp->errors[error] = NULL;

    g_object_notify(G_OBJECT(self), "error");
  }}
#line 641 "lm-host.c"
#undef __GOB_FUNCTION__

#line 180 "src/lm-host.gob"
static void 
lm_host_constructor (LMHost * self)
{
#line 648 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::constructor"
{
#line 181 "src/lm-host.gob"
	
    selfp->host_id = lm_shell_allocate_host_id(lm_shell, self);

    lm_g_object_connect(self, self->applet,
			"signal::notify::delay", self_delay_changed_h, self,
			NULL);

    self_resolve(self);
  }}
#line 661 "lm-host.c"
#undef __GOB_FUNCTION__

#line 191 "src/lm-host.gob"
static void 
lm_host_finalize (LMHost * self)
{
#line 668 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::finalize"
{
#line 192 "src/lm-host.gob"
	
    if (selfp->resolve_timeout_id)
      g_source_remove(selfp->resolve_timeout_id);
    if (selfp->send_timeout_id)
      g_source_remove(selfp->send_timeout_id);
    if (selfp->dead_timeout_id)
      g_source_remove(selfp->dead_timeout_id);

    lm_shell_deallocate_host_id(lm_shell, selfp->host_id);
  }}
#line 682 "lm-host.c"
#undef __GOB_FUNCTION__

#line 203 "src/lm-host.gob"
static void 
lm_host_resolve (LMHost * self)
{
#line 689 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::resolve"
#line 203 "src/lm-host.gob"
	g_return_if_fail (self != NULL);
#line 203 "src/lm-host.gob"
	g_return_if_fail (LM_IS_HOST (self));
#line 695 "lm-host.c"
{
#line 205 "src/lm-host.gob"
	
    g_return_if_fail(self->resolving == FALSE);

    self_set_resolving(self, TRUE);

    g_object_ref(self);
    lm_thread_create(self_resolve_thread_cb, self);
  }}
#line 706 "lm-host.c"
#undef __GOB_FUNCTION__

#line 214 "src/lm-host.gob"
static gpointer 
lm_host_resolve_thread_cb (gpointer data)
{
#line 713 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::resolve_thread_cb"
{
#line 216 "src/lm-host.gob"
	
    Self *self = data;
    struct addrinfo hints;
    struct addrinfo *addrinfo;
    char *ip = NULL;
    int status;

    memset(&hints, 0, sizeof(hints));
#if WITH_IPV6
    hints.ai_family = PF_UNSPEC;
#else
    hints.ai_family = PF_INET;
#endif /* WITH_IPV6 */
    hints.ai_socktype = SOCK_RAW;

#ifndef HAVE_REENTRANT_RESOLVER
    G_LOCK(resolver);
#endif
    status = getaddrinfo(self->name, NULL, &hints, &addrinfo);
#ifndef HAVE_REENTRANT_RESOLVER
    G_UNLOCK(resolver);
#endif

    if (status == 0)
      {
  	char buf[NI_MAXHOST];
	int name_status;

#ifndef HAVE_REENTRANT_RESOLVER
	G_LOCK(resolver);
#endif
	name_status = getnameinfo(addrinfo->ai_addr,
				  addrinfo->ai_addrlen,
				  buf,
				  sizeof(buf),
				  NULL,
				  0,
				  NI_NUMERICHOST);
#ifndef HAVE_REENTRANT_RESOLVER
	G_UNLOCK(resolver);
#endif

	if (name_status == 0)
	  ip = g_strdup(buf);
      }
    else
      addrinfo = NULL;

    GDK_THREADS_ENTER();

    self_set_resolving(self, FALSE);

    if (selfp->addrinfo)
      freeaddrinfo(selfp->addrinfo);
    selfp->addrinfo = addrinfo;

    g_free(self->ip);
    self->ip = g_strdup(ip);
    g_object_notify(G_OBJECT(self), "ip");

    if (selfp->addrinfo)
      {
	selfp->sock = lm_shell_get_socket(lm_shell, selfp->addrinfo->ai_family);
	if (selfp->sock)
	  {
	    if (! selfp->sock->init_error)
	      {
		/* complete success */
		self_clear_error(self, ERROR_RESOLVE);

		if (! selfp->send_timeout_id)
		  {
		    self_send_echo_request(self);	/* send first packet */
		    self_install_send_timeout(self);	/* install send loop */
		  }
	      }
	    else
	      self_set_error(self, ERROR_RESOLVE, _("socket could not be initialized: %s"), selfp->sock->init_error);
	  }
	else
	  self_set_error(self, ERROR_RESOLVE, _("unsupported address family"));

	/* DNS success (even if no socket), refresh in one hour */
	self_install_resolve_timeout(self, 3600 * 1000);
      }
    else
      {
	selfp->sock = NULL;
	self_set_error(self, ERROR_RESOLVE, _("unable to resolve hostname: %s"), gai_strerror(status));

	/* DNS failure, retry in 10 seconds */
	self_install_resolve_timeout(self, 10 * 1000);
      }

    /* if an error was installed above, remove the send timeout */
    if (selfp->errors[ERROR_RESOLVE])
      lm_source_clear(&selfp->send_timeout_id);

    g_object_unref(self);

    /*
     * A note on gdk_flush(): as advised in the GDK threads
     * documentation, we only call gdk_flush() from a thread other
     * than our main thread.
     */
    gdk_flush();
    GDK_THREADS_LEAVE();

    return NULL;
  }}
#line 827 "lm-host.c"
#undef __GOB_FUNCTION__

#line 327 "src/lm-host.gob"
static void 
lm_host_install_resolve_timeout (LMHost * self, int delay)
{
#line 834 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::install_resolve_timeout"
#line 327 "src/lm-host.gob"
	g_return_if_fail (self != NULL);
#line 327 "src/lm-host.gob"
	g_return_if_fail (LM_IS_HOST (self));
#line 840 "lm-host.c"
{
#line 329 "src/lm-host.gob"
	
    g_return_if_fail(selfp->resolve_timeout_id == 0);
    selfp->resolve_timeout_id = gdk_threads_add_timeout(delay, self_resolve_timeout_cb, self);
  }}
#line 847 "lm-host.c"
#undef __GOB_FUNCTION__

#line 334 "src/lm-host.gob"
static gboolean 
lm_host_resolve_timeout_cb (gpointer data)
{
#line 854 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::resolve_timeout_cb"
{
#line 336 "src/lm-host.gob"
	
    Self *self = data;

    self_resolve(self);

    selfp->resolve_timeout_id = 0;
    return FALSE;		/* remove source */
  }}
#line 866 "lm-host.c"
#undef __GOB_FUNCTION__

#line 345 "src/lm-host.gob"
static void 
lm_host_send_echo_request (LMHost * self)
{
#line 873 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::send_echo_request"
#line 345 "src/lm-host.gob"
	g_return_if_fail (self != NULL);
#line 345 "src/lm-host.gob"
	g_return_if_fail (LM_IS_HOST (self));
#line 879 "lm-host.c"
{
#line 347 "src/lm-host.gob"
	
    GError *err = NULL;

    g_return_if_fail(selfp->sock != NULL);
    g_return_if_fail(selfp->sock->init_error == NULL);
    g_return_if_fail(selfp->addrinfo != NULL);

    if (lm_icmp_send_echo_request(selfp->sock, selfp->addrinfo, selfp->host_id, selfp->sent_seq, &err))
      {
	RequestInfo *req;

	req = &selfp->requests[selfp->sent_seq];
	req->sent_time = lm_get_ticks();

	selfp->sent_seq++;

	self_clear_error(self, ERROR_SEND);

	if (! selfp->dead_timeout_id)
	  {
	    int timeout;

	    if (selfp->max_roundtrip_time > 0)
	      {
		timeout = (selfp->max_roundtrip_time / 1000) * 2;
		if (timeout < MIN_TIMEOUT)
		  timeout = MIN_TIMEOUT;
	      }
	    else
	      timeout = DEFAULT_TIMEOUT;

	    selfp->dead_timeout_id = gdk_threads_add_timeout(timeout, self_dead_timeout_cb, self);
	  }
      }
    else
      {
	self_set_error(self, ERROR_SEND, _("unable to send echo request: %s"), err->message);
	g_error_free(err);
      }
  }}
#line 922 "lm-host.c"
#undef __GOB_FUNCTION__

#line 388 "src/lm-host.gob"
static void 
lm_host_delay_changed_h (GObject * object, GParamSpec * pspec, gpointer user_data)
{
#line 929 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::delay_changed_h"
{
#line 390 "src/lm-host.gob"
	
    Self *self = user_data;

    if (selfp->send_timeout_id)
      {
	lm_source_clear(&selfp->send_timeout_id);
	self_install_send_timeout(self);
      }
    /* else we cannot send packets: do not install the send timeout */
  }}
#line 943 "lm-host.c"
#undef __GOB_FUNCTION__

#line 401 "src/lm-host.gob"
static void 
lm_host_install_send_timeout (LMHost * self)
{
#line 950 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::install_send_timeout"
#line 401 "src/lm-host.gob"
	g_return_if_fail (self != NULL);
#line 401 "src/lm-host.gob"
	g_return_if_fail (LM_IS_HOST (self));
#line 956 "lm-host.c"
{
#line 403 "src/lm-host.gob"
	
    g_return_if_fail(selfp->send_timeout_id == 0);
    g_return_if_fail(selfp->sock != NULL);
    g_return_if_fail(selfp->sock->init_error == NULL);
    g_return_if_fail(selfp->addrinfo != NULL);

    selfp->send_timeout_id = gdk_threads_add_timeout(self->applet->delay, self_send_timeout_cb, self);
  }}
#line 967 "lm-host.c"
#undef __GOB_FUNCTION__

#line 412 "src/lm-host.gob"
static gboolean 
lm_host_send_timeout_cb (gpointer data)
{
#line 974 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::send_timeout_cb"
{
#line 414 "src/lm-host.gob"
	
    Self *self = data;

    self_send_echo_request(self);

    return TRUE;		/* keep source */
  }}
#line 985 "lm-host.c"
#undef __GOB_FUNCTION__

#line 422 "src/lm-host.gob"
static gboolean 
lm_host_dead_timeout_cb (gpointer data)
{
#line 992 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::dead_timeout_cb"
{
#line 424 "src/lm-host.gob"
	
    Self *self = data;

    self_set_alive(self, FALSE);

    selfp->dead_timeout_id = 0;
    return FALSE;		/* remove source */
  }}
#line 1004 "lm-host.c"
#undef __GOB_FUNCTION__

#line 433 "src/lm-host.gob"
void 
lm_host_reply_received (LMHost * self, const LMICMPReply * reply)
{
#line 1011 "lm-host.c"
#define __GOB_FUNCTION__ "LM:Host::reply_received"
#line 433 "src/lm-host.gob"
	g_return_if_fail (self != NULL);
#line 433 "src/lm-host.gob"
	g_return_if_fail (LM_IS_HOST (self));
#line 433 "src/lm-host.gob"
	g_return_if_fail (reply != NULL);
#line 1019 "lm-host.c"
{
#line 435 "src/lm-host.gob"
	
    RequestInfo *req;

    /*
     * If there is no send timeout, an error (DNS or socket) has
     * occurred and we are unable to send packets: ignore this reply,
     * otherwise we would set alive back to TRUE.
     */
    if (! selfp->send_timeout_id)
      return;

    req = &selfp->requests[reply->seq];
    if (! req->sent_time)
      return; /* no matching request, ignore */

    if (reply->received_time < req->sent_time)
      /*
       * Negative roundtrip-time: this should not normally happen
       * since we use a monotonic clock source, but it is possible
       * that the OS improperly implements it, or that the monitored
       * host returns garbage, etc. Acknowledge the reply but
       * otherwise ignore it.
       */
      goto end;

    if (reply->error)
      self_set_error(self, ERROR_RECEIVE, "%s", reply->error);
    else
      {
	self_clear_error(self, ERROR_RECEIVE);
	self_set_roundtrip_time(self, reply->received_time - req->sent_time);
      }

  end:
    /* we have matched the request, clear it */
    req->sent_time = 0;
  }}
#line 1059 "lm-host.c"
#undef __GOB_FUNCTION__