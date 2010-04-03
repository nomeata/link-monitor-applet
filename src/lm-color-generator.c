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

#include <stdlib.h>
#include <gtk/gtk.h>
#include "lm-util.h"

#define MAX_RUN_TIME			3000000

#define MIN_BRIGHTNESS_CONTRAST		75
#define MIN_COLOR_CONTRAST		200

/* used for clarity: each channel ranges from 0 to 255 */
typedef struct
{
  int red;
  int green;
  int blue;
} W3Color;

static const GdkColor seed_colors[] = {
  { 0, 64764,	59881,	20303	}, /* Butter #1 */
  { 0, 60909,	54484,	0	}, /* Butter #2 */
  { 0, 50372,	41120,	0	}, /* Butter #3 */
  { 0, 64764,	44975,	15934	}, /* Orange #1 */
  { 0, 62965,	31097,	0	}, /* Orange #2 */
  { 0, 52942,	23644,	0	}, /* Orange #3 */
  { 0, 59811,	47545,	28270	}, /* Chocolate #1 */
  { 0, 49601,	32125,	4369	}, /* Chocolate #2 */
  { 0, 36751,	22873,	514	}, /* Chocolate #3 */
  { 0, 35466,	58082,	13364	}, /* Chameleon #1 */
  { 0, 29555,	53970,	5654	}, /* Chameleon #2 */
  { 0, 20046,	39578,	1542	}, /* Chameleon #3 */
  { 0, 29289,	40863,	53199	}, /* Sky Blue #1 */
  { 0, 13364,	25957,	42148	}, /* Sky Blue #2 */
  { 0, 8224,	19018,	34695	}, /* Sky Blue #3 */
  { 0, 44461,	32639,	43167	}, /* Plum #1 */
  { 0, 30069,	20560,	31611	}, /* Plum #2 */
  { 0, 23644,	13621,	26214	}, /* Plum #3 */
  { 0, 61423,	10537,	10537	}, /* Scarlet Red #1 */
  { 0, 52428,	0,	0	}, /* Scarlet Red #2 */
  { 0, 42148,	0,	0	}, /* Scarlet Red #3 */
  { 0, 34952,	35466,	34181	}, /* Aluminium #4*/
  { 0, 21845,	22359,	21331	}, /* Aluminium #5*/
  { 0, 11822,	13364,	13878	}  /* Aluminium #6*/
};

static void
w3_color_init (W3Color *out, const GdkColor *in)
{
  g_return_if_fail(out != NULL);
  g_return_if_fail(in != NULL);

  out->red = in->red / 256;
  out->green = in->green / 256;
  out->blue = in->blue / 256;
}

static int
w3_color_get_brightness (const W3Color *color)
{
  g_return_val_if_fail(color != NULL, 0);

  return (color->red * 299 + color->green * 587 + color->blue * 114) / 1000;
}

static gboolean
color_is_visible (const GdkColor *fg,
		  const GdkColor *bg,
		  int color_contrast,
		  int brightness_contrast)
{
  W3Color wfg;
  W3Color wbg;
  int fg_brightness;
  int bg_brightness;
  int brightness_diff;
  int color_diff;

  w3_color_init(&wfg, fg);
  w3_color_init(&wbg, bg);

  fg_brightness = w3_color_get_brightness(&wfg);
  bg_brightness = w3_color_get_brightness(&wbg);

  brightness_diff = abs(fg_brightness - bg_brightness);
  color_diff = abs(fg->red - bg->red) + abs(fg->green - bg->green) + abs(fg->blue - bg->blue);

  return color_diff > color_contrast && brightness_diff > brightness_contrast;
}

GArray *
lm_color_generator_generate (int count, const GdkColor *bg)
{
  GArray *colors;
  LMTimeSpan breakout_time;
  int i;

  g_return_val_if_fail(count >= 0, NULL);
  g_return_val_if_fail(bg != NULL, NULL);

  srand(bg->red + bg->green + bg->blue + 1);

  colors = g_array_new(FALSE, FALSE, sizeof(GdkColor));

  for (i = 0; i < G_N_ELEMENTS(seed_colors) && colors->len < count; i++)
    {
      const GdkColor *color = &seed_colors[i];

      if (color_is_visible(color, bg, MIN_COLOR_CONTRAST, MIN_BRIGHTNESS_CONTRAST))
	g_array_append_val(colors, *color);
    }

  breakout_time = lm_get_ticks() + MAX_RUN_TIME;

  while (colors->len < count)
    {
      GdkColor color = { 0, rand() % 0xffff, rand() % 0xffff, rand() % 0xffff };

      if (lm_get_ticks() >= breakout_time)
	{
	  g_warning("unable to generate enough random colors (%i requested, %i generated)", count, colors->len);
	  break;
	}

      if (color_is_visible(&color, bg, MIN_COLOR_CONTRAST, MIN_BRIGHTNESS_CONTRAST))
	g_array_append_val(colors, color);
    }

  return colors;
}
