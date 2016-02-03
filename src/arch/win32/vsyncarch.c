/*
 * vsyncarch.c - End-of-frame handling for Win32
 *
 * Written by
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
#include "ui.h"
#include "lightpendrv.h"
#include "mousedrv.h"
#include "kbdbuf.h"

#ifdef HAS_JOYSTICK
#include "joy.h"
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////
//Multiplatform functions
//////////////////////////////////////////////////////////////////////////////////////////////////
static unsigned long frequency = 0;
static int perf_rotate = 0;
static int perf_inited = 0;
enum { EXTRA_PRECISION = 10 };

signed long vsyncarch_frequency(void) {
    return 1000 << EXTRA_PRECISION;
}

void vsyncarch_presync(void)
{
    /* Update mouse */
    mouse_update_mouse();

    /* Update lightpen */
    win32_lightpen_update();

    /* Flush keypresses emulated through the keyboard buffer.  */
    kbdbuf_flush();
    joystick_update();
}

void vsyncarch_postsync(void)
{
    /* Dispatch all the pending UI events.  */
    ui_dispatch_events();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//Android platform specific functions
//////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __ANDROID__

#include <unistd.h>

void (*vsyncarch_fn_speed_callback) (double speed, double frame_rate, int warp_enabled) = NULL;

void vsyncarch_android_set_speed_callback (void (*fn_speed_callback) (double speed, double frame_rate, int warp_enabled)) {
	vsyncarch_fn_speed_callback = fn_speed_callback;
}

static uint64_t vsyncarch_current_time_msec(void) {
	struct timespec now;
	clock_gettime (CLOCK_MONOTONIC, &now);
	return ((uint64_t) now.tv_sec * 1000000000ULL + (uint64_t) now.tv_nsec) / 1000000ULL; //millisec = 1000*1000 * nanosec
}

unsigned long vsyncarch_gettime(void) {
    return (unsigned long) (vsyncarch_current_time_msec() << EXTRA_PRECISION);
}

void vsyncarch_init(void) {
}

void vsyncarch_display_speed(double speed, double frame_rate, int warp_enabled) {
	if (vsyncarch_fn_speed_callback)
		vsyncarch_fn_speed_callback (speed, frame_rate, warp_enabled);
}

void vsyncarch_sleep(signed long delay)
{
    uint64_t current_time = vsyncarch_current_time_msec();
    uint64_t target_time = (uint64_t) (current_time + (delay >> EXTRA_PRECISION));
    while (current_time < target_time) {
    	uint64_t sleep_duration = target_time - current_time;
    	if (sleep_duration >= 1000000ULL)
    		sleep_duration = 1000000ULL - 1ULL;
    	
        usleep(sleep_duration);
        current_time = vsyncarch_current_time_msec();
    }
}

#else //__ANDROID__
//////////////////////////////////////////////////////////////////////////////////////////////////
//Windows platform specific functions
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "vsync.h"
#include "log.h"
#include "machine.h"
#include "uiapi.h"
#include "videoarch.h"
#include "vsyncapi.h"

// -------------------------------------------------------------------------

unsigned long vsyncarch_gettime(void)
{
    return timeGetTime() << EXTRA_PRECISION;
}

void vsyncarch_init(void)
{
    MMRESULT res = timeBeginPeriod(1);
    if (res != TIMERR_NOERROR)
        log_warning(LOG_DEFAULT, "VSYNC: 1 ms scheduling latency not available.");
}

// -------------------------------------------------------------------------

// Display speed (percentage) and frame rate (frames per second).
void vsyncarch_display_speed(double speed, double frame_rate, int warp_enabled)
{
    ui_display_speed((float) speed, (float)frame_rate, warp_enabled);
}

void vsyncarch_sleep(signed long delay)
{
    SDWORD current_time = (SDWORD) timeGetTime();
    SDWORD target_time = current_time + (delay >> EXTRA_PRECISION);
    while (current_time < target_time) {
        Sleep(target_time - current_time);
        current_time = timeGetTime();
    }
    //log_debug("Sleep %d ms target reached to %d ms", delay >> EXTRA_PRECISION, current_time - target_time);
}

int vsyncarch_vbl_sync_enabled(void)
{
    //return ui_vblank_sync_enabled();
	return 0; //default
}

#endif //__ANDROID__
