#include "vice.h"

#ifdef __ANDROID__

#include "videoarch.h"
#include "video.h"
#include "lib.h"
#include "../../video.h"

typedef int (*t_fn_init_canvas) (uint32_t width, uint32_t height, uint32_t bpp, uint32_t visible_width, uint32_t visible_height, uint8_t** buffer, uint32_t* pitch);
typedef void (*t_fn_lock_canvas) ();

t_fn_init_canvas canvas_init = NULL;
t_fn_lock_canvas canvas_lock = NULL;
t_fn_lock_canvas canvas_unlock = NULL;

uint8_t *canvas_buffer = NULL;
uint32_t canvas_buffer_pitch = 0;

void video_android_set_init_callback (t_fn_init_canvas init_canvas) {
	canvas_init = init_canvas;
}

void video_android_set_locking_callbacks (t_fn_lock_canvas lock_canvas, t_fn_lock_canvas unlock_canvas) {
	canvas_lock = lock_canvas;
	canvas_unlock = unlock_canvas;
}

video_canvas_t* video_canvas_create_android (video_canvas_t* canvas, unsigned int* width, unsigned int* height) {
	canvas->depth = 32;

	if (video_set_physical_colors (canvas) < 0) {
		return NULL;
	}

	video_canvas_add (canvas);

	if (canvas_init == NULL || canvas_lock == NULL || canvas_unlock == NULL) {
		return NULL;
	}

	int scaleX = canvas->videoconfig->doublesizex + 1;
	int scaleY = canvas->videoconfig->doublesizey + 1;

	if (canvas_init (canvas->draw_buffer->draw_buffer_width * scaleX, canvas->draw_buffer->draw_buffer_height * scaleY, 32
		, canvas->draw_buffer->visible_width * scaleX, canvas->draw_buffer->visible_height * scaleY
		, &canvas_buffer, &canvas_buffer_pitch) < 0) {
		return NULL;
	}

	return canvas;
}

void video_canvas_destroy_android (video_canvas_t *canvas) {
	canvas_buffer = NULL;
	canvas_buffer_pitch = 0;

	canvas_init = NULL;
	canvas_lock = NULL;
	canvas_unlock = NULL;
}

void video_canvas_resize_android (video_canvas_t *canvas) {
}

void video_canvas_refresh_android (video_canvas_t *canvas, unsigned int xs, unsigned int ys, unsigned int xi, unsigned int yi, unsigned int w, unsigned int h) {
	if (canvas->videoconfig->doublesizex) {
		xi *= (canvas->videoconfig->doublesizex + 1);
		w *= (canvas->videoconfig->doublesizex + 1);
	}

	if (canvas->videoconfig->doublesizey) {
		yi *= (canvas->videoconfig->doublesizey + 1);
		h *= (canvas->videoconfig->doublesizey + 1);
	}

	canvas_lock ();
	video_canvas_render(canvas, canvas_buffer, w, h, xs, ys, xi, yi, canvas_buffer_pitch, 32);
	canvas_unlock ();
}

#endif //__ANDROID__
