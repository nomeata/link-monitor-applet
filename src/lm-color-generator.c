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

static const GdkRGBA seed_colors[] = {
  {  0.0 / 65535.0,  64764.0 / 65535.0, 	59881.0 / 65535.0, 	20303.0 / 65535.0	}, /* Butter #1 */
  {  0.0 / 65535.0,  60909.0 / 65535.0, 	54484.0 / 65535.0, 	0.0 / 65535.0	}, /* Butter #2 */
  {  0.0 / 65535.0,  50372.0 / 65535.0, 	41120.0 / 65535.0, 	0.0 / 65535.0	}, /* Butter #3 */
  {  0.0 / 65535.0,  64764.0 / 65535.0, 	44975.0 / 65535.0, 	15934.0 / 65535.0	}, /* Orange #1 */
  {  0.0 / 65535.0,  62965.0 / 65535.0, 	31097.0 / 65535.0, 	0.0 / 65535.0	}, /* Orange #2 */
  {  0.0 / 65535.0,  52942.0 / 65535.0, 	23644.0 / 65535.0, 	0.0 / 65535.0	}, /* Orange #3 */
  {  0.0 / 65535.0,  59811.0 / 65535.0, 	47545.0 / 65535.0, 	28270.0 / 65535.0	}, /* Chocolate #1 */
  {  0.0 / 65535.0,  49601.0 / 65535.0, 	32125.0 / 65535.0, 	4369.0 / 65535.0	}, /* Chocolate #2 */
  {  0.0 / 65535.0,  36751.0 / 65535.0, 	22873.0 / 65535.0, 	514.0 / 65535.0	}, /* Chocolate #3 */
  {  0.0 / 65535.0,  35466.0 / 65535.0, 	58082.0 / 65535.0, 	13364.0 / 65535.0	}, /* Chameleon #1 */
  {  0.0 / 65535.0,  29555.0 / 65535.0, 	53970.0 / 65535.0, 	5654.0 / 65535.0	}, /* Chameleon #2 */
  {  0.0 / 65535.0,  20046.0 / 65535.0, 	39578.0 / 65535.0, 	1542.0 / 65535.0	}, /* Chameleon #3 */
  {  0.0 / 65535.0,  29289.0 / 65535.0, 	40863.0 / 65535.0, 	53199.0 / 65535.0	}, /* Sky Blue #1 */
  {  0.0 / 65535.0,  13364.0 / 65535.0, 	25957.0 / 65535.0, 	42148.0 / 65535.0	}, /* Sky Blue #2 */
  {  0.0 / 65535.0,  8224.0 / 65535.0, 	19018.0 / 65535.0, 	34695.0 / 65535.0	}, /* Sky Blue #3 */
  {  0.0 / 65535.0,  44461.0 / 65535.0, 	32639.0 / 65535.0, 	43167.0 / 65535.0	}, /* Plum #1 */
  {  0.0 / 65535.0,  30069.0 / 65535.0, 	20560.0 / 65535.0, 	31611.0 / 65535.0	}, /* Plum #2 */
  {  0.0 / 65535.0,  23644.0 / 65535.0, 	13621.0 / 65535.0, 	26214.0 / 65535.0	}, /* Plum #3 */
  {  0.0 / 65535.0,  61423.0 / 65535.0, 	10537.0 / 65535.0, 	10537.0 / 65535.0	}, /* Scarlet Red #1 */
  {  0.0 / 65535.0,  52428.0 / 65535.0, 	0.0 / 65535.0, 	0.0 / 65535.0	}, /* Scarlet Red #2 */
  {  0.0 / 65535.0,  42148.0 / 65535.0, 	0.0 / 65535.0, 	0.0 / 65535.0	}, /* Scarlet Red #3 */
  {  0.0 / 65535.0,  34952.0 / 65535.0, 	35466.0 / 65535.0, 	34181.0 / 65535.0	}, /* Aluminium #4*/
  {  0.0 / 65535.0,  21845.0 / 65535.0, 	22359.0 / 65535.0, 	21331.0 / 65535.0	}, /* Aluminium #5*/
  {  0.0 / 65535.0,  11822.0 / 65535.0, 	13364.0 / 65535.0, 	13878.0 / 65535.0	}  /* Aluminium #6*/
};

static void
w3_color_init (W3Color *out, const GdkRGBA *in)
{
  g_return_if_fail(out != NULL);
  g_return_if_fail(in != NULL);

  out->red = in->red * 256.0;
  out->green = in->green * 256.0;
  out->blue = in->blue * 256.0;
}

static int
w3_color_get_brightness (const W3Color *color)
{
  g_return_val_if_fail(color != NULL, 0);

  return (color->red * 299 + color->green * 587 + color->blue * 114) / 1000;
}

static gboolean
color_is_visible (const GdkRGBA *fg,
		  const GdkRGBA *bg,
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
lm_color_generator_generate (int count, const GdkRGBA *bg)
{
  GArray *colors;
  LMTimeSpan breakout_time;
  int i;

  g_return_val_if_fail(count >= 0, NULL);
  g_return_val_if_fail(bg != NULL, NULL);

  srand(bg->red + bg->green + bg->blue + 1);

  colors = g_array_new(FALSE, FALSE, sizeof(GdkRGBA));

  for (i = 0; i < G_N_ELEMENTS(seed_colors) && colors->len < count; i++)
    {
      const GdkRGBA *color = &seed_colors[i];

      if (color_is_visible(color, bg, MIN_COLOR_CONTRAST, MIN_BRIGHTNESS_CONTRAST))
	g_array_append_val(colors, *color);
    }

  breakout_time = lm_get_ticks() + MAX_RUN_TIME;

  while (colors->len < count)
    {
      GdkRGBA color = { 0.0, (rand() % 0xffff)/65535.0, (rand() % 0xffff)/65535.0, (rand() % 0xffff)/65535.0 };

      if (lm_get_ticks() >= breakout_time)
	{
	  g_warning("unable to generate enough random colors (%i requested, %i generated)", count, colors->len);
	  break;
	}

      // GTK3TODO
      if (1) // (color_is_visible(&color, bg, MIN_COLOR_CONTRAST, MIN_BRIGHTNESS_CONTRAST))
	g_array_append_val(colors, color);
    }

  return colors;
}
