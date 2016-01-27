/*
 * hardsid.c
 *
 * Written by
 *  Andreas Boose <viceteam@t-online.de>
 *  HardSID Support <support@hardsid.com>
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

void hardsid_reset(void)
{
}

int hardsid_open(void)
{
	return -1;
}

int hardsid_close(void)
{
    return 0;
}

int hardsid_read(uint16_t addr, int chipno)
{
    return 0;
}

void hardsid_store(uint16_t addr, uint8_t val, int chipno)
{
}

void hardsid_set_machine_parameter(long cycles_per_sec)
{
}

int hardsid_available(void)
{
	return 0;
}

void hardsid_set_device(unsigned int chipno, unsigned int device)
{
}
