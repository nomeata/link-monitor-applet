/*
 * Link Monitor Applet
 * Copyright (C) 2004-2008 Jean-Yves Lefort <jylefort@brutele.be>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _LM_UTIL_H
#define _LM_UTIL_H

#include <stdarg.h>
#include <time.h>
#include <gtk/gtk.h>

#define LM_LIST_FOREACH(var, head) \
  for ((var) = (head); (var); (var) = (var)->next)

void lm_g_slist_free_deep (GSList *list);
void lm_g_slist_free_deep_custom (GSList *list,
				  GFunc element_free_func,
				  gpointer user_data);

void lm_g_object_slist_free (GSList *list);

#define LM_ARRAY_FOREACH(var, array) \
  for ((var) = 0; (var) < (array)->len; (var)++)
#define LM_ARRAY_REVERSE_FOREACH(var, array) \
  for ((var) = (array)->len - 1; (var) >= 0; (var)--)

int lm_g_ptr_array_find (GPtrArray *array, gconstpointer data);

void lm_g_object_array_free (GPtrArray *array);

void lm_container_create_interface (GtkContainer *container,
				    const char *filename,
				    const char *child_name,
				    const char *callback_prefix,
				    ...);

GdkPixbuf *lm_pixbuf_new (const char *filename);

void lm_thread_create (GThreadFunc func, gpointer data);

void lm_show_help (const char *link_id);

GtkWidget *lm_menu_shell_append (GtkMenuShell *shell,
				 const char *stock_id,
				 const char *mnemonic);

void lm_show_error_dialog (GtkWindow *parent,
			   const char *primary,
			   const char *format,
			   ...) G_GNUC_PRINTF(3, 4);
void lm_show_fatal_error_dialog (GtkWindow *parent,
				 const char *format,
				 ...) G_GNUC_PRINTF(2, 3) G_GNUC_NORETURN;

void lm_source_clear (unsigned int *tag);

gpointer lm_g_object_connect (gpointer object,
			      gpointer instance,
			      const char *signal_spec,
			      ...);

typedef void (*LMCallbackFunc) (gpointer data);

typedef struct
{
  unsigned int		idle_id;
  LMCallbackFunc	func;
  gpointer		data;
} LMCallback;

void lm_callback_init (LMCallback *callback, LMCallbackFunc func, gpointer data);
void lm_callback_queue (LMCallback *callback);
void lm_callback_clear (LMCallback *callback);

void lm_add_weak_pointer (gpointer object_location);
void lm_remove_weak_pointer (gpointer object_location);

char *lm_strftime (const char *format, const struct tm *timeptr);

/*
 * A time span expressed in microseconds. It is signed to ease
 * calculations.
 *
 * We don't use struct timeval / GTimeVal because:
 *
 *	- it keeps seconds and microseconds in separate fields, which
 *	  make calculations cumbersome
 *	- by using two longs rather than two ints, it wastes 8 bytes
 *	  on 64-bit platforms
 */
typedef gint64 LMTimeSpan;

LMTimeSpan lm_get_ticks (void);

GtkWindow *lm_widget_get_parent_window (GtkWidget *widget);
void lm_widget_remove_from_container (GtkWidget *widget);
void lm_widget_get_origin (GtkWidget *widget,
			   double xalign,
			   double yalign,
			   int *x,
			   int *y);

void lm_window_present_from_event (GtkWindow *window);

void lm_g_value_get_mandatory_color (const GValue *value, GdkColor *color);

GtkTreeRowReference *lm_tree_row_reference_new_from_path_string (GtkTreeModel *model,
								 const char *path);
gboolean lm_tree_row_reference_get_iter (GtkTreeRowReference *reference,
					 GtkTreeIter *iter);
int lm_tree_row_reference_compare (GtkTreeRowReference *a,
				   GtkTreeRowReference *b);

typedef struct
{
  double red;
  double green;
  double blue;
} LMCairoColor;

void lm_gdk_color_to_cairo_color (const GdkColor *in, LMCairoColor *out);

void lm_cairo_set_source_color (cairo_t *cr, const LMCairoColor *color);

void lm_cairo_color_shade (const LMCairoColor *in, LMCairoColor *out, float k);

/*
 * The size of the border painted by gtk_paint_shadow(), used by the
 * custom widgets to calculate the size of their contents.
 *
 * It is assumed that the theme engine actually draws a one pixel
 * border, which should be the case for most (all?) themes. The custom
 * widgets must not cause a catastrophe if the border is actually
 * thicker (eg. they can draw on the inner part of the border since
 * that's unavoidable, but they should not crash).
 */
#define LM_BOX_BORDER_WIDTH 1

void lm_paint_box (GdkWindow *window,
		   GtkStateType state_type,
		   GtkShadowType shadow_type,
		   GdkRectangle *area,
		   GtkWidget *widget,
		   GdkGC *gc,
		   int x,
		   int y,
		   int width,
		   int height);

void lm_paint_pixbuf (GdkWindow *window,
		      GdkPixbuf *pixbuf,
		      GdkRectangle *area,
		      int x,
		      int y);

#endif /* _LM_UTIL_H */
