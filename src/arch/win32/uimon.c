/*
 * uimon.c - Monitor access interface.
 *
 * Written by
 *  Spiro Trikaliotis <Spiro.Trikaliotis@gmx.de>
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

#include <stdio.h>

#include "console.h"
#include "monitor.h"

static console_t *console_log_local = NULL;
static console_t console_log_for_mon = { -50, -50, -50 };

void uimon_set_interface(monitor_interface_t **monitor_interface_init, int count)
{
	//...
}

void uimon_notify_change()
{
}

void uimon_window_close(void)
{
    console_log_for_mon.console_cannot_output = 1;
    console_close(console_log_local);
    console_log_local = NULL;
}

console_t *uimon_window_open(void)
{
    console_log_local = console_open("Monitor");
    return console_log_local;
}

void uimon_window_suspend(void)
{
    console_log_for_mon.console_cannot_output = 1;
    uimon_window_close();
}

console_t *uimon_window_resume(void)
{
    console_log_for_mon.console_cannot_output = 0;
    return uimon_window_open();
}

int uimon_out(const char *buffer)
{
    int   rc = 0;

    if (console_log_local) {
        rc = console_out(console_log_local, "%s", buffer);
    }
    return rc;
}

char *uimon_get_in(char **ppchCommandLine, const char *prompt) {
    return console_in(console_log_local, prompt);
}
