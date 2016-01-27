/*
 * parsid.c - PARallel port SID support for WIN32.
 *
 * Written by
 *  Marco van den Heuvel <blackystardust68@yahoo.com>
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
#	include <unistd.h>
#else //__ANDROID__
#	include <stdint.h>
#endif //__ANDROID__

#include "parsid.h"

int parsid_check_port(int port)
{
    return 0;
}

void parsid_reset(void)
{
}

int parsid_open(int port)
{
	return -1;
}

int parsid_close(void)
{
	return 0;
}

int parsid_read(uint16_t addr, int chipno)
{
    return 0;
}

void parsid_store(uint16_t addr, uint8_t outval, int chipno)
{
}
