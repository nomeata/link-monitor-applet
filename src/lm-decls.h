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

#ifndef _LM_DECLS_H
#define _LM_DECLS_H

/* forward declarations to avoid circular includes */

#ifndef __TYPEDEF_LM_APPLET__
#define __TYPEDEF_LM_APPLET__
typedef struct _LMApplet LMApplet;
#endif

#ifndef __TYPEDEF_LM_HOST__
#define __TYPEDEF_LM_HOST__
typedef struct _LMHost LMHost;
#endif

#ifndef __TYPEDEF_LM_HOST_FRONTEND__
#define __TYPEDEF_LM_HOST_FRONTEND__
typedef struct _LMHostFrontend LMHostFrontend;
#endif

#endif /* _LM_DECLS_H */
