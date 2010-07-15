/* Generated by GOB (v2.0.15)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>


#include "lm-dialog.h"
#include "lm-non-linear-range.h"

#ifndef __LM_PREFERENCES_DIALOG_H__
#define __LM_PREFERENCES_DIALOG_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



extern const LMNonLinearRangeBlock lm_preferences_dialog_tooltip_graph_span_blocks[];
extern const int lm_preferences_dialog_num_tooltip_graph_span_blocks;


/*
 * Type checking and casting macros
 */
#define LM_TYPE_PREFERENCES_DIALOG	(lm_preferences_dialog_get_type())
#define LM_PREFERENCES_DIALOG(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), lm_preferences_dialog_get_type(), LMPreferencesDialog)
#define LM_PREFERENCES_DIALOG_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), lm_preferences_dialog_get_type(), LMPreferencesDialog const)
#define LM_PREFERENCES_DIALOG_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), lm_preferences_dialog_get_type(), LMPreferencesDialogClass)
#define LM_IS_PREFERENCES_DIALOG(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), lm_preferences_dialog_get_type ())

#define LM_PREFERENCES_DIALOG_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), lm_preferences_dialog_get_type(), LMPreferencesDialogClass)

/* Private structure type */
typedef struct _LMPreferencesDialogPrivate LMPreferencesDialogPrivate;

/*
 * Main object structure
 */
#ifndef __TYPEDEF_LM_PREFERENCES_DIALOG__
#define __TYPEDEF_LM_PREFERENCES_DIALOG__
typedef struct _LMPreferencesDialog LMPreferencesDialog;
#endif
struct _LMPreferencesDialog {
	LMDialog __parent__;
	/*< private >*/
	LMPreferencesDialogPrivate *_priv;
};

/*
 * Class definition
 */
typedef struct _LMPreferencesDialogClass LMPreferencesDialogClass;
struct _LMPreferencesDialogClass {
	LMDialogClass __parent__;
};


/*
 * Public methods
 */
GType	lm_preferences_dialog_get_type	(void);

/*
 * Argument wrapping macros
 */
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define LM_PREFERENCES_DIALOG_PROP_APPLET(arg)    	"applet", __extension__ ({gpointer z = (arg); z;})
#define LM_PREFERENCES_DIALOG_GET_PROP_APPLET(arg)	"applet", __extension__ ({gpointer *z = (arg); z;})
#else /* __GNUC__ && !__STRICT_ANSI__ */
#define LM_PREFERENCES_DIALOG_PROP_APPLET(arg)    	"applet",(gpointer )(arg)
#define LM_PREFERENCES_DIALOG_GET_PROP_APPLET(arg)	"applet",(gpointer *)(arg)
#endif /* __GNUC__ && !__STRICT_ANSI__ */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif