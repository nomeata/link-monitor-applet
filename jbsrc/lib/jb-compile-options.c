/*
 * JB, the Jean-Yves Lefort's Build System
 * Copyright (C) 2008 Jean-Yves Lefort <jylefort@brutele.be>
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

#include "jb-compile-options.h"
#include "jb-feature.h"
#include "jb-util.h"
#include "jb-variable.h"

JBCompileOptions jb_compile_options;

void
jb_compile_options_init (JBCompileOptions *self)
{
  g_return_if_fail(self != NULL);

  self->cflags = g_string_new(NULL);
  self->cppflags = g_string_new(NULL);
  self->ldflags = g_string_new(NULL);
  self->gob2flags = g_string_new(NULL);
  self->string_defines = NULL;
}

void
jb_compile_options_add_cflags (JBCompileOptions *self, const char *cflags)
{
  g_return_if_fail(self != NULL);
  g_return_if_fail(cflags != NULL);

  g_string_append_printf(self->cflags, " %s", cflags);
}

void
jb_compile_options_add_cppflags (JBCompileOptions *self, const char *cppflags)
{
  g_return_if_fail(self != NULL);
  g_return_if_fail(cppflags != NULL);

  g_string_append_printf(self->cppflags, " %s", cppflags);
}

void
jb_compile_options_add_ldflags (JBCompileOptions *self, const char *ldflags)
{
  g_return_if_fail(self != NULL);
  g_return_if_fail(ldflags != NULL);

  g_string_append_printf(self->ldflags, " %s", ldflags);
}

void
jb_compile_options_add_gob2flags (JBCompileOptions *self, const char *gob2flags)
{
  g_return_if_fail(self != NULL);
  g_return_if_fail(gob2flags != NULL);
  g_return_if_fail(jb_feature_is_enabled(&jb_gob2_feature));

  g_string_append_printf(self->gob2flags, " %s", gob2flags);
}

void
jb_compile_options_add_package (JBCompileOptions *self, const char *name)
{
  g_return_if_fail(self != NULL);
  g_return_if_fail(name != NULL);

  g_string_append_printf(self->cflags, " $%s-cflags", name);
  g_string_append_printf(self->cppflags, " $%s-cppflags", name);
  g_string_append_printf(self->ldflags, " $%s-ldflags", name);
}

void
jb_compile_options_add_string_defines (JBCompileOptions *self,
				       const char *name,
				       ...)
{
  va_list args;

  g_return_if_fail(self != NULL);

  va_start(args, name);

  while (name != NULL)
    {
      const char *value;
      JBStringDefine *define;

      value = va_arg(args, const char *);
      g_assert(value != NULL);

      define = g_new0(JBStringDefine, 1);
      define->name = g_strdup(name);
      define->value = g_strdup(value);

      self->string_defines = g_slist_append(self->string_defines, define);

      name = va_arg(args, const char *);
    }

  va_end(args);
}

/* the returned value is not fully expanded */
const char *
jb_compile_options_get_effective_cppflags (JBCompileOptions *self)
{
  GString *cppflags;
  GSList *l;

  g_return_val_if_fail(self != NULL, NULL);

  if (self->effective_cppflags != NULL)
    return self->effective_cppflags;

  cppflags = g_string_new(self->cppflags->str);

  JB_LIST_FOREACH(l, self->string_defines)
    {
      const JBStringDefine *define = l->data;
      char *evaluated;
      char *c_quoted;
      char *shell_quoted;

      /* expand variables since we need to quote the value */
      evaluated = jb_variable_expand(define->value, NULL);

      c_quoted = jb_c_quote(evaluated);
      g_free(evaluated);

      shell_quoted = g_shell_quote(c_quoted);
      g_free(c_quoted);

      g_string_append_printf(cppflags, " -D%s=%s", define->name, shell_quoted);
      g_free(shell_quoted);
    }

  /* add variable defines if working on the global JBCompileOptions */

  if (self == &jb_compile_options)
    JB_LIST_FOREACH(l, jb_variables)
      {
	JBVariable *variable = l->data;
	char *symbol;

	if ((variable->flags & JB_VARIABLE_C_DEFINE) == 0)
	  continue;

	g_assert(variable->type == jb_variable_type_bool);

	symbol = g_strdelimit(g_ascii_strup(variable->name, -1), "-", '_');
	g_string_append_printf(cppflags, " -DWITH_%s=%i",
			       symbol,
			       g_value_get_boolean(&variable->value) ? 1 : 0);
	g_free(symbol);
      }

  self->effective_cppflags = g_string_free(cppflags, FALSE);

  return self->effective_cppflags;
}
