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

#ifndef _LM_NON_LINEAR_RANGE_H
#define _LM_NON_LINEAR_RANGE_H

#include <gtk/gtk.h>

typedef struct
{
  int min;			/* inclusive */
  int max;			/* inclusive */
  int step;
} LMNonLinearRangeBlock;

void lm_non_linear_range_setup_static (GtkRange *range,
				       const LMNonLinearRangeBlock *blocks,
				       int num_blocks);

int lm_non_linear_range_get_value (GtkRange *range);
void lm_non_linear_range_set_value (GtkRange *range, int value);

#endif /* _LM_NON_LINEAR_RANGE_H */
