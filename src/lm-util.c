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

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <math.h>
#include <errno.h>
#include <glib/gi18n.h>
#include "lm-util.h"

typedef struct
{
  GtkContainer	*container;
  const char	*callback_prefix;
} ContainerCreateInterfaceConnectInfo;

typedef struct
{
  gpointer	instance;
  unsigned long	id;
} SignalHandler;

typedef struct
{
  double hue;
  double lightness;
  double saturation;
} LMHLSColor;

void
lm_g_slist_free_deep (GSList *list)
{
  lm_g_slist_free_deep_custom(list, (GFunc) g_free, NULL);
}

void
lm_g_slist_free_deep_custom (GSList *list,
			     GFunc element_free_func,
			     gpointer user_data)
{
  g_slist_foreach(list, element_free_func, user_data);
  g_slist_free(list);
}

/**
 * lm_g_object_slist_free:
 * @list: a #GSList of #GObject instances
 *
 * Equivalent of eel_g_object_list_free() for a singly-linked list.
 **/
void
lm_g_object_slist_free (GSList *list)
{
  lm_g_slist_free_deep_custom(list, (GFunc) g_object_unref, NULL);
}

int
lm_g_ptr_array_find (GPtrArray *array, gconstpointer data)
{
  int i;

  g_return_val_if_fail(array != NULL, -1);

  LM_ARRAY_FOREACH(i, array)
    if (g_ptr_array_index(array, i) == data)
      return i;

  return -1;
}

void
lm_g_object_array_free (GPtrArray *array)
{
  g_return_if_fail(array != NULL);

  g_ptr_array_foreach(array, (GFunc) g_object_unref, NULL);
  g_ptr_array_free(array, TRUE);
}

static GtkBuilder *
lm_glade_xml_new (const char *filename)
{

  g_return_val_if_fail(filename != NULL, NULL);

  GError* error = NULL;
  GtkBuilder* builder = gtk_builder_new ();
  if (!gtk_builder_add_from_file (builder, filename, &error))
    {
      lm_show_fatal_error_dialog(NULL, "Unable to load interface \"%s\": %s",
	  filename, error->message);
      g_error_free (error);
    }

  return builder;
}

static GtkWidget *
lm_glade_xml_get_widget (GtkBuilder *builder, const char *widget_name)
{
  GtkWidget *widget;

  g_return_val_if_fail(GTK_IS_BUILDER(builder), NULL);
  g_return_val_if_fail(widget_name != NULL, NULL);

  widget = GTK_WIDGET(gtk_builder_get_object(builder, widget_name));
  if (! widget)
    lm_show_fatal_error_dialog(NULL, "Widget \"%s\" not found in interface definition.", widget_name);

  return widget;
}

static void
create_interface_connect_cb (GtkBuilder *builder,
			     GObject *object,
			     const char *signal_name,
			     const char *handler_name,
			     GObject *connect_object,
			     GConnectFlags flags,
			     gpointer user_data)
{
  static GModule *module = NULL;
  ContainerCreateInterfaceConnectInfo *info = user_data;
  char *cb_name;
  GCallback cb;

  if (! module)
    {
      module = g_module_open(NULL, 0);
      if (! module)
	lm_show_fatal_error_dialog(NULL, "Unable to open the program as a module (%s).", g_module_error());
    }

  cb_name = g_strconcat(info->callback_prefix, handler_name, NULL);
  if (! g_module_symbol(module, cb_name, (gpointer) &cb))
    lm_show_fatal_error_dialog(NULL, "Signal handler \"%s\" not found.", cb_name);
  g_free(cb_name);

  flags |= G_CONNECT_SWAPPED;
  g_signal_connect_data(object, signal_name, cb, info->container, NULL, flags);
}

void
lm_container_create_interface (GtkContainer *container,
			       const char *filename,
	                       const char *child_name,
			       const char *callback_prefix,
			       ...)
{
  GtkBuilder *builder;
  GtkWidget *child;
  ContainerCreateInterfaceConnectInfo info;
  va_list args;
  const char *widget_name;

  g_return_if_fail(GTK_IS_CONTAINER(container));
  g_return_if_fail(filename != NULL);
  g_return_if_fail(child_name != NULL);
  g_return_if_fail(callback_prefix != NULL);

  builder = lm_glade_xml_new(filename);
  child = lm_glade_xml_get_widget(builder, child_name);

  gtk_widget_unparent(child);

  if (GTK_IS_DIALOG(container)) {
    GtkWidget *box = gtk_dialog_get_content_area(GTK_DIALOG(container));
    gtk_box_pack_start(GTK_BOX(box), child, TRUE, TRUE, 0);
  } else {
    gtk_container_add(container, child);
  }

  info.container = container;
  info.callback_prefix = callback_prefix;
  gtk_builder_connect_signals_full (builder, create_interface_connect_cb, &info);


  va_start(args, callback_prefix);
  while ((widget_name = va_arg(args, const char *)))
    {
      GtkWidget **widget;

      widget = va_arg(args, GtkWidget **);
      g_return_if_fail(widget != NULL);

      *widget = lm_glade_xml_get_widget(builder, widget_name);
    }
  va_end(args);

  g_object_unref(builder);
}

GdkPixbuf *
lm_pixbuf_new (const char *filename)
{
  GdkPixbuf *pixbuf;
  GError *err = NULL;

  g_return_val_if_fail(filename != NULL, NULL);

  pixbuf = gdk_pixbuf_new_from_file(filename, &err);
  if (! pixbuf)
    {
      lm_show_fatal_error_dialog(NULL, "Unable to load image \"%s\" (%s).", filename, err->message);
      g_error_free(err);
    }

  return pixbuf;
}

void
lm_thread_create (GThreadFunc func, gpointer data)
{
  GError *err = NULL;

  g_return_if_fail(func != NULL);

  if (! g_thread_create(func, data, FALSE, &err))
    {
      lm_show_fatal_error_dialog(NULL, "Unable to create a thread: %s.", err->message);
      g_error_free(err);
    }
}

void
lm_show_help (const char *link_id)
{
  GError *err = NULL;
  if (! g_app_info_launch_default_for_uri ("ghelp:link-monitor-applet", NULL, &err))
    {
      lm_show_error_dialog(NULL, _("Unable to display help"), "%s", err->message);
      g_error_free(err);
    }
}

static GtkWidget *
menu_item_new (const char *stock_id, const char *mnemonic)
{
  GtkWidget *item;

  if (stock_id && mnemonic)
    {
      GtkWidget *image;

      item = gtk_image_menu_item_new_with_mnemonic(mnemonic);

      image = gtk_image_new_from_stock(stock_id, GTK_ICON_SIZE_MENU);
      gtk_image_menu_item_set_image(GTK_IMAGE_MENU_ITEM(item), image);
      gtk_widget_show(image);
    }
  else if (stock_id)
    item = gtk_image_menu_item_new_from_stock(stock_id, NULL);
  else if (mnemonic)
    item = gtk_menu_item_new_with_mnemonic(mnemonic);
  else
    item = gtk_separator_menu_item_new();

  return item;
}

/**
 * lm_menu_shell_append:
 * @shell: the #GtkMenuShell to append to
 * @stock_id: the stock ID of the item, or NULL
 * @mnemonic: the mnemonic of the item, or NULL
 *
 * Creates a new menu item, shows it and appends it to @shell.
 *
 * If both @stock_id and @mnemonic are provided, a #GtkImageMenuItem
 * will be created using the text of @mnemonic and the icon of
 * @stock_id.
 *
 * If only @stock_id is provided, a #GtkImageMenuitem will be created
 * using the text and icon of @stock_id.
 *
 * If only @mnemonic is provided, a #GtkMenuItem will be created using
 * the text of @mnemonic.
 *
 * If @stock_id and @mnemonic are both NULL, a #GtkSeparatorMenuItem
 * will be created.
 *
 * Return value: the new menu item
 **/
GtkWidget *
lm_menu_shell_append (GtkMenuShell *shell,
		      const char *stock_id,
		      const char *mnemonic)
{
  GtkWidget *item;

  g_return_val_if_fail(GTK_IS_MENU_SHELL(shell), NULL);

  item = menu_item_new(stock_id, mnemonic);
  gtk_menu_shell_append(shell, item);
  gtk_widget_show(item);

  return item;
}

static void
show_error_dialog_real (GtkWindow *parent,
			gboolean blocking,
			const char *primary,
			const char *secondary)
{
  GtkWidget *dialog;

  g_return_if_fail(primary != NULL);
  g_return_if_fail(secondary != NULL);

  dialog = gtk_message_dialog_new(parent,
				  GTK_DIALOG_DESTROY_WITH_PARENT,
				  GTK_MESSAGE_ERROR,
				  GTK_BUTTONS_NONE,
				  "%s",
				  primary);

  gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), "%s", secondary);
  gtk_window_set_title(GTK_WINDOW(dialog), ""); /* HIG */

  gtk_dialog_add_button(GTK_DIALOG(dialog), GTK_STOCK_OK, GTK_RESPONSE_OK);
  gtk_dialog_set_default_response(GTK_DIALOG(dialog), GTK_RESPONSE_OK);

  if (blocking)
    {
      gtk_dialog_run(GTK_DIALOG(dialog));
      gtk_widget_destroy(dialog);
    }
  else
    {
      g_signal_connect_swapped(dialog,
			       "response",
			       G_CALLBACK(gtk_widget_destroy),
			       dialog);
      gtk_widget_show(dialog);
    }
}

void
lm_show_error_dialog (GtkWindow *parent,
		      const char *primary,
		      const char *format,
		      ...)
{
  va_list args;
  char *secondary;

  g_return_if_fail(primary != NULL);
  g_return_if_fail(format != NULL);

  va_start(args, format);
  secondary = g_strdup_vprintf(format, args);
  va_end(args);

  show_error_dialog_real(parent, FALSE, primary, secondary);
  g_free(secondary);
}

void
lm_show_fatal_error_dialog (GtkWindow *parent, const char *format, ...)
{
  va_list args;
  char *secondary;

  g_assert(format != NULL);

  va_start(args, format);
  secondary = g_strdup_vprintf(format, args);
  va_end(args);

  show_error_dialog_real(parent, TRUE, _("A fatal error has occurred in the link monitor"), secondary);
  g_free(secondary);

  exit(1);
}

void
lm_source_clear (unsigned int *tag)
{
  g_return_if_fail(tag != NULL);

  if (*tag)
    {
      g_source_remove(*tag);
      *tag = 0;
    }
}

static void
object_connect_destroy_cb (SignalHandler *handler)
{
  if (handler->instance)
    {
      g_signal_handler_disconnect(handler->instance, handler->id);
      lm_remove_weak_pointer(&handler->instance);
    }
  g_free(handler);
}

/**
 * lm_g_object_connect:
 * @object: the object to associate the handlers with
 * @instance: the instance to connect to
 * @signal_spec: the spec for the first signal
 * @...: #GCallback for the first signal, followed by data for the
 *       first signal, followed optionally by more signal spec/callback/data
 *       triples, followed by NULL
 *
 * Connects to one or more signals of @instance, associating the
 * handlers with @object. The handlers will be disconnected whenever
 * @object is finalized.
 *
 * Note: this function is not thread-safe. If @object and @instance
 * are finalized concurrently, the behaviour is undefined.
 *
 * The signals specs must be in the same format than those passed to
 * g_object_connect(), except that object-signal,
 * swapped-object-signal, object-signal-after and
 * swapped-object-signal-after are not accepted.
 *
 * Note that this function is only useful because of
 * http://bugzilla.gnome.org/show_bug.cgi?id=118536, otherwise
 * g_signal_connect_object() and the object specs of
 * g_object_connect() could be used.
 *
 * Return value: @object
 **/
gpointer
lm_g_object_connect (gpointer object,
		     gpointer instance,
		     const char *signal_spec,
		     ...)
{
  va_list args;

  g_return_val_if_fail(G_IS_OBJECT(object), NULL);
  g_return_val_if_fail(G_IS_OBJECT(instance), NULL);

  va_start(args, signal_spec);
  while (signal_spec)
    {
      GCallback callback = va_arg(args, GCallback);
      gpointer data = va_arg(args, gpointer);
      SignalHandler *handler;

      handler = g_new(SignalHandler, 1);
      handler->instance = instance;

      if (g_str_has_prefix(signal_spec, "signal::"))
	handler->id = g_signal_connect(instance, signal_spec + 8, callback, data);
      else if (g_str_has_prefix(signal_spec, "swapped_signal::")
	       || g_str_has_prefix(signal_spec, "swapped-signal::"))
	handler->id = g_signal_connect_swapped(instance, signal_spec + 16, callback, data);
      else if (g_str_has_prefix(signal_spec, "signal_after::")
	       || g_str_has_prefix(signal_spec, "signal-after::"))
	handler->id = g_signal_connect_after(instance, signal_spec + 14, callback, data);
      else if (g_str_has_prefix(signal_spec, "swapped_signal_after::")
	       || g_str_has_prefix(signal_spec, "swapped-signal-after::"))
	handler->id = g_signal_connect_data(instance, signal_spec + 22, callback, data, NULL, G_CONNECT_AFTER | G_CONNECT_SWAPPED);
      else
	g_critical("invalid signal specification \"%s\"", signal_spec);

      lm_add_weak_pointer(&handler->instance);

      /*
       * If the object is a GtkObject, it is important to connect to
       * its destroy signal rather than adding a weak reference: the
       * weak reference callback might be run too late, for instance
       * in the following situation:
       *
       *   - add one host
       *   - while the preferences dialog is shown, remove the applet
       *   - lm_applet_destroy_h() destroys the host list: the host's
       *     last remaining reference is now held by the list store of
       *     LMHostView
       *   - lm_applet_destroy_h() destroys the preferences dialog
       *   - the preferences dialog destroys its children widgets, one
       *     of them being the LMHostView
       *   - the LMHostView destroys its list store, which causes the
       *     host it contains to be finalized
       *   - in its finalize() method, the host calls
       *     lm_shell_deallocate_host_id(), which triggers a
       *     notify::host-count signal
       *   - lm_preferences_dialog_update_sensitivity() (the
       *     notify::host-count signal handler) crashes because the
       *     preferences dialog was already partially destroyed
       */
      if (GTK_IS_WIDGET(object))
	g_signal_connect_swapped(object, "destroy", G_CALLBACK(object_connect_destroy_cb), handler);
      else
	g_object_weak_ref(object, (GWeakNotify) object_connect_destroy_cb, handler);

      signal_spec = va_arg(args, const char *);
    }
  va_end(args);

  return object;
}

void
lm_callback_init (LMCallback *callback, LMCallbackFunc func, gpointer data)
{
  g_return_if_fail(callback != NULL);
  g_return_if_fail(func != NULL);

  callback->idle_id = 0;
  callback->func = func;
  callback->data = data;
}

static gboolean
callback_dispatch_cb (gpointer data)
{
  LMCallback *callback = data;

  callback->func(callback->data);

  callback->idle_id = 0;
  return FALSE;			/* remove source */
}

void
lm_callback_queue (LMCallback *callback)
{
  g_return_if_fail(callback != NULL);
  g_return_if_fail(callback->func != NULL);

  if (! callback->idle_id)
    callback->idle_id = gdk_threads_add_idle(callback_dispatch_cb, callback);
}

void
lm_callback_clear (LMCallback *callback)
{
  g_return_if_fail(callback != NULL);

  lm_source_clear(&callback->idle_id);
}

void
lm_add_weak_pointer (gpointer object_location)
{
  gpointer *p;

  g_return_if_fail(object_location != NULL);

  p = (gpointer *) object_location;
  g_return_if_fail(G_IS_OBJECT(*p));

  g_object_add_weak_pointer(G_OBJECT(*p), p);
}

void
lm_remove_weak_pointer (gpointer object_location)
{
  gpointer *p;

  g_return_if_fail(object_location != NULL);

  p = (gpointer *) object_location;
  g_return_if_fail(G_IS_OBJECT(*p));

  g_object_remove_weak_pointer(G_OBJECT(*p), p);
  *p = NULL;
}

char *
lm_strftime (const char *format, const struct tm *timeptr)
{
  char *buf;
  size_t bufsize = 64;

  g_return_val_if_fail(format != NULL, NULL);
  g_return_val_if_fail(timeptr != NULL, NULL);

  buf = g_malloc(bufsize);
  while (strftime(buf, bufsize, format, timeptr) == 0)
    {
      bufsize *= 2;
      buf = g_realloc(buf, bufsize);
    }

  return buf;
}

/**
 * lm_get_ticks:
 *
 * Returns the amount of time that has elapsed since an unspecified
 * point P in the past. P does not change after system start-up.
 *
 * This function is useful for accurate time calculations, since the
 * returned value is independent of system time adjustments (daylight
 * savings, NTP, etc).
 *
 * Return value: a monotonically increasing time, expressed in microseconds
 **/
LMTimeSpan
lm_get_ticks (void)
{
  struct timespec tspec;

  if (clock_gettime(CLOCK_MONOTONIC, &tspec) < 0)
    lm_show_fatal_error_dialog(NULL, "Unable to obtain an accurate timestamp.");

  return ((LMTimeSpan) tspec.tv_sec * 1000000) + (tspec.tv_nsec / 1000);
}

GtkWindow *
lm_widget_get_parent_window (GtkWidget *widget)
{
  GtkWidget *toplevel;

  g_return_val_if_fail(GTK_IS_WIDGET(widget), NULL);

  toplevel = gtk_widget_get_toplevel(widget);

  return gtk_widget_is_toplevel(toplevel) ? GTK_WINDOW(toplevel) : NULL;
}

void
lm_widget_remove_from_container (GtkWidget *widget)
{
  GtkWidget *parent;

  g_return_if_fail(GTK_IS_WIDGET(widget));

  parent = gtk_widget_get_parent(widget);
  if (parent)
    gtk_container_remove(GTK_CONTAINER(parent), widget);
}

void
lm_widget_get_origin (GtkWidget *widget,
		      double xalign,
		      double yalign,
		      int *x,
		      int *y)
{
  g_return_if_fail(GTK_IS_WIDGET(widget));
  g_return_if_fail(xalign >= 0.0 && xalign <= 1.0);
  g_return_if_fail(yalign >= 0.0 && yalign <= 1.0);

  gint natural_width, natural_height, minimal_width, minimal_height;
  gtk_widget_get_preferred_width(widget, &natural_width, &natural_height);
  gtk_widget_get_preferred_height(widget, &natural_height, &natural_height);

  if (x)
    *x = floor((natural_width - gtk_widget_get_allocated_width(widget)) * xalign);
  if (y)
    *y = floor((natural_height  - gtk_widget_get_allocated_height(widget)) * yalign);
}

void
lm_window_present_from_event (GtkWindow *window)
{
  g_return_if_fail(GTK_IS_WINDOW(window));

  gtk_window_present_with_time(window, gtk_get_current_event_time());
}

void
lm_g_value_get_mandatory_color (const GValue *value, GdkRGBA *color)
{
  GdkRGBA *p;

  g_return_if_fail(G_VALUE_HOLDS(value, GDK_TYPE_RGBA));
  g_return_if_fail(color != NULL);

  p = g_value_get_boxed(value);
  g_return_if_fail(p != NULL);

  *color = *p;
}

GtkTreeRowReference *
lm_tree_row_reference_new_from_path_string (GtkTreeModel *model,
					    const char *path)
{
  GtkTreePath *path_obj;
  GtkTreeRowReference *ref;

  g_return_val_if_fail(GTK_IS_TREE_MODEL(model), NULL);
  g_return_val_if_fail(path != NULL, NULL);

  path_obj = gtk_tree_path_new_from_string(path);
  ref = gtk_tree_row_reference_new(model, path_obj);
  gtk_tree_path_free(path_obj);

  return ref;
}

gboolean
lm_tree_row_reference_get_iter (GtkTreeRowReference *reference,
				GtkTreeIter *iter)
{
  GtkTreeModel *model;
  GtkTreePath *path;
  gboolean status;

  g_return_val_if_fail(reference != NULL, FALSE);
  g_return_val_if_fail(iter != NULL, FALSE);

  model = gtk_tree_row_reference_get_model(reference);
  path = gtk_tree_row_reference_get_path(reference);

  status = gtk_tree_model_get_iter(model, iter, path);

  gtk_tree_path_free(path);

  return status;
}

int
lm_tree_row_reference_compare (GtkTreeRowReference *a, GtkTreeRowReference *b)
{
  GtkTreePath *path_a;
  GtkTreePath *path_b;
  int cmp;

  g_return_val_if_fail(a != NULL, 0);
  g_return_val_if_fail(b != NULL, 0);
  g_return_val_if_fail(gtk_tree_row_reference_get_model(a) == gtk_tree_row_reference_get_model(b), 0);

  path_a = gtk_tree_row_reference_get_path(a);
  path_b = gtk_tree_row_reference_get_path(b);

  cmp = gtk_tree_path_compare(path_a, path_b);

  gtk_tree_path_free(path_a);
  gtk_tree_path_free(path_b);

  return cmp;
}

void
lm_cairo_set_source_color (cairo_t *cr, const GdkColor *color)
{
  g_return_if_fail(cr != NULL);
  g_return_if_fail(color != NULL);

  cairo_set_source_rgb(cr, color->red/65535.0, color->green/65535.0, color->blue/65535.0);
}


void
lm_cairo_set_source_rgba (cairo_t *cr, const GdkRGBA *color)
{
  g_return_if_fail(cr != NULL);
  g_return_if_fail(color != NULL);

  cairo_set_source_rgb(cr, color->red, color->green, color->blue);
}

static void
lm_cairo_color_to_hls_color (const GdkRGBA *in, LMHLSColor *out)
{
  double min;
  double max;

  g_return_if_fail(in != NULL);
  g_return_if_fail(out != NULL);

  if (in->red > in->green)
    {
      min = MIN(in->green, in->blue);
      max = MAX(in->red, in->blue);
    }
  else
    {
      min = MIN(in->red, in->blue);
      max = MAX(in->green, in->blue);
    }

  out->hue = 0;
  out->lightness = (max + min) / 2;
  out->saturation = 0;

  if (min != max)
    {
      double delta;

      if (out->lightness <= 0.5)
	out->saturation = (max - min) / (max + min);
      else
	out->saturation = (max - min) / (2 - max - min);

      delta = max - min;
      if (in->red == max)
	out->hue = (in->green - in->blue) / delta;
      else if (in->green == max)
	out->hue = 2 + (in->blue - in->red) / delta;
      else if (in->blue == max)
	out->hue = 4 + (in->red - in->green) / delta;

      out->hue *= 60;
      if (out->hue < 0.0)
	out->hue += 360;
    }
}

static double
get_channel (double hue, double m1, double m2)
{
  while (hue > 360)
    hue -= 360;
  while (hue < 0)
    hue += 360;

  if (hue < 60)
    return m1 + (m2 - m1) * hue / 60;
  else if (hue < 180)
    return m2;
  else if (hue < 240)
    return m1 + (m2 - m1) * (240 - hue) / 60;
  else
    return m1;
}

static void
lm_hls_color_to_cairo_color (const LMHLSColor *in, GdkRGBA *out)
{
  g_return_if_fail(in != NULL);
  g_return_if_fail(out != NULL);

  if (in->saturation == 0)
    {
      out->red = in->lightness;
      out->green = in->lightness;
      out->blue = in->lightness;
    }
  else
    {
      double m1;
      double m2;

      if (in->lightness <= 0.5)
	m2 = in->lightness * (1 + in->saturation);
      else
	m2 = in->lightness + in->saturation - in->lightness * in->saturation;

      m1 = 2 * in->lightness - m2;

      out->red = get_channel(in->hue + 120, m1, m2);
      out->green = get_channel(in->hue, m1, m2);
      out->blue = get_channel(in->hue - 120, m1, m2);
    }
}

/* based on ul_shade() in Ubuntulooks */
void
lm_cairo_color_shade (const GdkRGBA *in, GdkRGBA *out, float k)
{
  LMHLSColor hls;

  g_return_if_fail(in != NULL);
  g_return_if_fail(out != NULL);

  lm_cairo_color_to_hls_color(in, &hls);

  hls.lightness *= k;
  hls.lightness = CLAMP(hls.lightness, 0.0, 1.0);

  hls.saturation *= k;
  hls.saturation = CLAMP(hls.saturation, 0.0, 1.0);

  lm_hls_color_to_cairo_color(&hls, out);
}

/*
 * Useful when the gc used by gtk_paint_box() (normally bg_gc) is not
 * appropriate.
 */
void
lm_paint_box (cairo_t *cr,
	      GtkStateType state_type,
	      GtkShadowType shadow_type,
	      GtkWidget *widget,
	      int x,
	      int y,
	      int width,
	      int height)
{
  g_return_if_fail(GTK_IS_WIDGET(widget));

  // GTK3TODO
  cairo_rectangle(cr,x+1,y+1, width-2, height-2);
  cairo_fill(cr);
  /*
  gdk_draw_rectangle(window,
		     background_gc,
		     TRUE,
		     x + 1,
		     y + 1,
		     width - 2,
		     height - 2);
  */	

  gtk_paint_shadow(gtk_widget_get_style(widget),
		   cr,
		   state_type,
		   shadow_type,
		   widget,
		   NULL,
		   x,
		   y,
		   width,
		   height);
}

/*
 * Like gdk_draw_pixbuf(), but respects the @area clip rectangle.
 */
void
lm_paint_pixbuf (cairo_t *cr,
		 GdkPixbuf *pixbuf,
		 int x,
		 int y)
{
  g_return_if_fail(GDK_IS_PIXBUF(pixbuf));

  gdk_cairo_set_source_pixbuf(cr, pixbuf, x, y);
  cairo_paint(cr);
}
