/*
 * video.c - Common video functions for Win32
 *
 * Written by
 *  Tibor Biczo <crown@matavnet.hu>
 *  Andreas Matthies <andreas.matthies@gmx.net>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include "vice.h"
#include "lib.h"
#include "log.h"
#include "palette.h"
#include "videoarch.h"
#include "video.h"
#include "viewport.h"

#ifndef __ANDROID__

#include "cmdline.h"
#include "res.h"
#include "resources.h"
#include "translate.h"
#include "ui.h"
#include "uiapi.h"
#include <stdint.h>

static int video_number_of_canvases;
static video_canvas_t *video_canvases[2];
static int dx9_available;

/* ------------------------------------------------------------------------ */
/* Video-related resources.  */

/* Flag: are we in fullscreen mode?  */
int fullscreen_enabled;
int dx_primary_surface_rendering;
int dx9_disable;

#endif // !__ANDROID__

//////////////////////////////////////////////////////////////////////////////////////////////////
//Multiplatform functions
//////////////////////////////////////////////////////////////////////////////////////////////////
int video_canvas_set_palette(video_canvas_t *canvas, palette_t *p)
{
    if (p == NULL) {
        return 0; /* no palette, nothing to do */
    }
    canvas->palette = p;

    video_set_physical_colors(canvas);
    return 0;
}

void video_arch_canvas_init(struct video_canvas_s *canvas)
{
#ifdef __ANDROID__
//TODO: ...
#else //__ANDROID__
	if (video_setup_dx9() < 0) {
		dx9_available = 0;
	} else {
		dx9_available = 1;
	}
#endif //__ANDROID__

	canvas->video_draw_buffer_callback = NULL;
}

video_canvas_t *video_canvas_create(video_canvas_t *canvas, unsigned int *width, unsigned int *height, int mapped)
{
	canvas->title = lib_stralloc(canvas->viewport->title);

#ifdef __ANDROID__
	return video_canvas_create_android (canvas, width, height);
#else //__ANDROID__
    video_canvas_t *canvas_temp;

    ui_open_canvas_window(canvas);
    ui_canvas_child_window(canvas, video_dx9_enabled());

    if (video_dx9_enabled()) {
        canvas_temp = video_canvas_create_dx9(canvas, width, height);
        if (canvas_temp == NULL) {
            log_debug("video: Falling back to DirectDraw canvas!");
            dx9_available = 0;
            ui_canvas_child_window(canvas, 0);
        } else {
            return canvas_temp;
        }
    }
    return video_canvas_create_ddraw(canvas);
#endif //__ANDROID__
}

void video_canvas_destroy(video_canvas_t *canvas)
{
#ifdef __ANDROID__
	video_canvas_destroy_android (canvas);
#else //__ANDROID__
    if (video_dx9_enabled()) {
        video_device_release_dx9(canvas);
    }

    if (canvas != NULL) {
        if (canvas->hwnd !=0) {
            DestroyWindow(canvas->hwnd);
        }
    }
#endif //__ANDROID__

	if (canvas != NULL) {
		lib_free(canvas->title);
		lib_free(canvas->pixels);
		canvas->title = NULL;
	}
}

int video_set_physical_colors(video_canvas_t *c)
{
    unsigned int i;
    int rshift;
    int rbits;
    int gshift;
    int gbits;
    int bshift;
    int bbits;
	uint32_t rmask;
	uint32_t gmask;
	uint32_t bmask;

    /* Use hard coded D3DFMT_X8R8G8B8 format, driver does conversion */
    rshift = 16;
    rmask = 0xff;
    rbits = 0;

    gshift = 8;
    gmask = 0xff;
    gbits = 0;

    bshift = 0;
    bmask = 0xff;
    bbits = 0;

    if (c->depth > 8) {
        for (i = 0; i < 256; i++) {
            video_render_setrawrgb(i, ((i & (rmask << rbits)) >> rbits) << rshift, ((i & (gmask << gbits)) >> gbits) << gshift, ((i & (bmask << bbits)) >> bbits) << bshift);
        }
        video_render_initraw(c->videoconfig);
    }

    if (c->palette) {
        for (i = 0; i < c->palette->num_entries; i++) {
            uint32_t p = (((c->palette->entries[i].red&(rmask << rbits)) >> rbits) << rshift) +
                      	 (((c->palette->entries[i].green&(gmask << gbits)) >> gbits) << gshift) +
                      	 (((c->palette->entries[i].blue&(bmask << bbits)) >> bbits) << bshift);
            video_render_setphysicalcolor(c->videoconfig, i, p, c->depth);
        }
    }
    return 0;
}

/* Change the size of `s' to `width' * `height' pixels.  */
void video_canvas_resize(video_canvas_t *canvas, char resize_canvas)
{
#ifdef __ANDROID__
	video_canvas_resize_android(canvas);
#else //__ANDROID__
    //int device;
    //int fullscreen_width;
    //int fullscreen_height;
    //int bitdepth;
    //int refreshrate;

    //if (IsFullscreenEnabled()) {
    //    GetCurrentModeParameters(&device, &fullscreen_width, &fullscreen_height, &bitdepth, &refreshrate);
    //} else {
    ui_resize_canvas_window(canvas);
    //}

    if (video_dx9_enabled()) {
        video_canvas_reset_dx9(canvas);
    } else {
        video_canvas_reset_ddraw(canvas);
    }
#endif //__ANDROID__
}

/* Raster code has updated display */
void video_canvas_refresh(video_canvas_t *canvas, unsigned int xs, unsigned int ys, unsigned int xi, unsigned int yi, unsigned int w, unsigned int h)
{
#ifdef __ANDROID__
	video_canvas_refresh_android(canvas, xs, ys, xi, yi, w, h);
#else //__ANDROID__
    if (video_dx9_enabled()) {
        video_canvas_refresh_dx9(canvas, xs, ys, xi, yi, w, h);
    } else {
        video_canvas_refresh_ddraw(canvas, xs, ys, xi, yi, w, h);
    }
#endif //__ANDROID__
}

char video_canvas_can_resize(video_canvas_t *canvas)
{
#ifdef __ANDROID__
    return (char) 1;
#else //__ANDROID__
    return !IsZoomed(canvas->hwnd);
#endif //__ANDROID__
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//Android platform specific functions
//////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __ANDROID__

static video_canvas_t *video_canvases = NULL;

int video_init_cmdline_options(void) {
	return 0;
}

int video_init(void) {
    return 0;
}

void video_shutdown(void) {
}

int video_arch_resources_init(void) {
	return 0;
}

void video_arch_resources_shutdown(void) {
}

void video_canvas_add(video_canvas_t *canvas)
{
	video_canvases = canvas;
}

#else //__ANDROID__
//////////////////////////////////////////////////////////////////////////////////////////////////
//Windows platform specific functions
//////////////////////////////////////////////////////////////////////////////////////////////////

static int set_dx_primary_surface_rendering(int val, void *param)
{
    int i;

    dx_primary_surface_rendering = val;

    if (video_dx9_enabled()) {
        for (i = 0; i < video_number_of_canvases; i++) {
            video_canvas_reset_dx9(video_canvases[i]);
        }
    }

    return 0;
}

static int set_dx9_disable(int val, void *param)
{
    int i;
    int old_dx9_disable, old_num_of_canvases;
    int old_width[2], old_height[2];

    if (!dx9_available) {
        return 0;
    }

    old_dx9_disable = dx9_disable;
    old_num_of_canvases = video_number_of_canvases;

    if (old_dx9_disable != val) {
        for (i = 0; i < video_number_of_canvases; i++) {       
            old_width[i] = video_canvases[i]->draw_buffer->canvas_physical_width;
            old_height[i] = video_canvases[i]->draw_buffer->canvas_physical_height;
            if (old_dx9_disable) {
                /* Anything to do here?? */
            } else {
                video_device_release_dx9(video_canvases[i]);
            }
        }

        dx9_disable = val;
        video_number_of_canvases = 0;

        for (i = 0; i < old_num_of_canvases; i++) {
            if (old_dx9_disable) {
                if (video_canvas_create_dx9(video_canvases[i], &old_width[i], &old_height[i]) == NULL) {
                    dx9_disable = old_dx9_disable;
                }
            }
            if (dx9_disable) {
                video_canvas_create_ddraw(video_canvases[i]);
            }
            ui_canvas_child_window(video_canvases[i], old_dx9_disable);
            video_canvas_resize(video_canvases[i], 1);
        }
        
        //fullscreen_getmodes();
    }

    return 0;
}

static const resource_int_t resources_int[] = {
    { "DXPrimarySurfaceRendering", 0, RES_EVENT_NO, NULL,
      &dx_primary_surface_rendering, set_dx_primary_surface_rendering, NULL },
#ifdef HAVE_D3D9_H
    { "DX9Disable", 0, RES_EVENT_NO, NULL,
      &dx9_disable, set_dx9_disable, NULL },
#endif
    { NULL }
};

int video_arch_resources_init(void)
{
    return resources_register_int(resources_int);
}

void video_arch_resources_shutdown(void)
{
}

/* ------------------------------------------------------------------------ */

/* Video-related command-line options.  */

static const cmdline_option_t cmdline_options[] = {
    { "-fullscreen", SET_RESOURCE, 0,
      NULL, NULL, "FullScreenEnabled", (resource_value_t) 1,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDS_START_VICE_FULLSCREEN_MODE,
      NULL, NULL },
#ifdef HAVE_D3D9_H
    { "-dx9disable", SET_RESOURCE, 0,
      NULL, NULL, "DX9Disable", (resource_value_t) 1,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDS_DISABLE_DX9,
      NULL, NULL },
#endif
    { NULL }
};

int video_init_cmdline_options(void)
{
    return cmdline_register_options(cmdline_options);
}


/* ------------------------------------------------------------------------ */

/* Initialization.  */
int video_init(void)
{
    return 0;
}

void video_shutdown(void)
{
    video_shutdown_dx9();
}

int video_dx9_enabled(void)
{
    return (dx9_available && !dx9_disable);
}

int video_dx9_available(void)
{
    return dx9_available;
}

/* ------------------------------------------------------------------------ */

video_canvas_t *video_canvas_for_hwnd(HWND hwnd)
{
    int i;

    for (i = 0; i < video_number_of_canvases; i++) {
        if (video_canvases[i]->hwnd == hwnd) {
            return video_canvases[i];
        }
    }

    return NULL;
}

int video_canvas_nr_for_hwnd(HWND hwnd)
{
    int i;

    for (i = 0; i < video_number_of_canvases; i++) {
        if (video_canvases[i]->hwnd == hwnd) {
            return i;
        }
    }

    return 0;
}

void video_canvas_add(video_canvas_t *canvas)
{
    video_canvases[video_number_of_canvases++] = canvas;
}

/* Window got a WM_PAINT and needs a refresh */
void video_canvas_update(HWND hwnd, HDC hdc, int xclient, int yclient, int w, int h)
{
    if (video_dx9_enabled()) {
        video_canvas_update_dx9(hwnd, hdc, xclient, yclient, w, h);
    } else {
        video_canvas_update_ddraw(hwnd, hdc, xclient, yclient, w, h);
    }
}

#endif //__ANDROID__
