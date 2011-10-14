/*
 * Random color generation algorithm, taken from Pidgin and edited for
 * style.
 *
 * Pidgin,
 * Copyright (C) 1998-2007 the Pidgin authors
 *
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

#ifndef _LM_COLOR_GENERATOR_H
#define _LM_COLOR_GENERATOR_H

#include <gtk/gtk.h>

GArray *lm_color_generator_generate (int count, const GdkRGBA *bg);

#endif /* _LM_COLOR_GENERATOR_H */
