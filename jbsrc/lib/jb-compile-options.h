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

#ifndef _JB_COMPILE_OPTIONS_H
#define _JB_COMPILE_OPTIONS_H

#include <stdarg.h>
#include <glib.h>

typedef struct
{
  char		*name;
  char		*value;
} JBStringDefine;

typedef struct
{
  GString	*cflags;
  GString	*cppflags;
  GString	*ldflags;
  GString	*gob2flags;
  GSList	*string_defines;

  char		*effective_cppflags;
} JBCompileOptions;

extern JBCompileOptions jb_compile_options;

void jb_compile_options_init (JBCompileOptions *self);

void jb_compile_options_add_cflags (JBCompileOptions *self, const char *cflags);
void jb_compile_options_add_cppflags (JBCompileOptions *self, const char *cppflags);
void jb_compile_options_add_ldflags (JBCompileOptions *self, const char *ldflags);
void jb_compile_options_add_gob2flags (JBCompileOptions *self, const char *gob2flags);

void jb_compile_options_add_package (JBCompileOptions *self, const char *name);

void jb_compile_options_add_string_defines (JBCompileOptions *self,
					    const char *name,
					    ...) G_GNUC_NULL_TERMINATED;

const char *jb_compile_options_get_effective_cppflags (JBCompileOptions *self);

#endif /* _JB_COMPILE_OPTIONS_H */
