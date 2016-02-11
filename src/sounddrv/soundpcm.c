/*
 * soundpcm.c - Implementation of the RIFF/WAV dump sound device (for android os)
 *
 * Written by
 *  Zoltan Laki
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

#ifdef __ANDROID__

#include <stdio.h>

#include "sound.h"
#include "types.h"
#include "archdep.h"
#include "log.h"

typedef void (*t_fn_sound_init) (int numChannels, int sampleRate, int bytesPerSample);
typedef void (*t_fn_sound_close) ();
typedef void (*t_fn_sound_write) (const uint8_t* buffer, size_t size);

t_fn_sound_init sound_android_init = NULL;
t_fn_sound_close sound_android_close = NULL;
t_fn_sound_write sound_android_write = NULL;

void sound_android_set_pcm_callbacks (t_fn_sound_init sound_init, t_fn_sound_close sound_close, t_fn_sound_write sound_write) {
	sound_android_init = sound_init;
	sound_android_close = sound_close;
	sound_android_write = sound_write;
}

static int pcm_init(const char *param, int *speed, int *fragsize, int *fragnr, int *channels)
{
	if (sound_android_init) {
		int sampleRate = *speed;
		int bytesPerSample = *speed * *channels * 2;
		int numChannels = *channels;

		sound_android_init (numChannels, sampleRate, bytesPerSample);
	}

    return 0;
}

static int pcm_write(SWORD *pbuf, size_t nr)
{
	if (sound_android_write)
		sound_android_write ((const uint8_t*) pbuf, nr * sizeof (SWORD));
    return 0;
}

static void pcm_close(void)
{
	if (sound_android_close)
		sound_android_close ();
}

static sound_device_t pcm_device =
{
    "pcm",
    pcm_init,
    pcm_write,
    NULL,
    NULL,
    NULL,
    pcm_close,
    NULL,
    NULL,
    0,
    2
};

#endif //__ANDROID__

int sound_init_pcm_device(void)
{
#ifdef __ANDROID__
    return sound_register_device(&pcm_device);
#else //__ANDROID__
    return 0;
#endif //__ANDROID__
}

