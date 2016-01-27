/*
 * catweaselmkiii.c
 *
 * Written by
 *  Andreas Boose <viceteam@t-online.de>
 *  Dirk Jagdmann <doj@cubic.org>
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
#include "catweaselmkiii.h"

#ifdef __ANDROID__
#	include <unistd.h>
#else //__ANDROID__
#	include <stdint.h>
#endif //__ANDROID__

int catweaselmkiii_open(void)
{
    return -1;
}

/* close all open device handles */
int catweaselmkiii_close(void)
{
    return 0;
}

int catweaselmkiii_read(uint16_t addr, int chipno)
{
    return 0;
}

/* write a value */
void catweaselmkiii_store(uint16_t addr, uint8_t val, int chipno)
{
}

/* set current main clock frequency, which gives us the possibilty to
   choose between pal and ntsc frequencies */
void catweaselmkiii_set_machine_parameter(long cycles_per_sec)
{
}

int catweaselmkiii_available(void)
{
    return 0;
}
