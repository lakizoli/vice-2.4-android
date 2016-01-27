/*
 * console.c - Console access interface.
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

int console_out(console_t *log, const char *format, ...)
{
    //console_private_t *pcp = log->private;

    //va_list ap;

    //char *buffer;
    //char *pBuffer;

    //pcp->bBreak = FALSE;

    //va_start(ap, format);
    //buffer = lib_mvsprintf(format, ap);
    //va_end(ap);
    //pBuffer = buffer;

    //FileOut(pcp, pBuffer);

    ///* restore character under cursor */
    //cursor(pcp, CS_SUSPEND);

    ///* perform an optimization:
    // * as long as no special char is used, output line by line.
    // * only special chars (ascii < 32) are handled individually.
    // */
    //while (*pBuffer) {
    //    char *p = pBuffer;

    //    /* advance p to the first non-printable char (< 32) */
    //    while (*p >= 32) {
    //        p++;
    //    }

    //    /* output the printable parts */
    //    if (p - pBuffer > 0) {
    //        console_out_printables_only(pcp, pBuffer, (int)(p - pBuffer));
    //    }

    //    /* now, process the exta char(s), if any */
    //    while (*p && (*p < 32)) {
    //        console_out_character(pcp, *p++);
    //    }

    //    pBuffer = p;
    //}

    //cursor(pcp, CS_RESUME);

    //lib_free(buffer);

    //return pcp->bBreak ? -1 : 0;
	return 0;
}

char *console_in(console_t *log, const char *prompt)
{
    //console_private_t *pcp = log->private ;

    //char *p;

    //console_out(log, "%s", prompt);

    //pcp->xPosInputLineStart = pcp->xPos;
    //pcp->yPosInputLineStart = pcp->yPos;
    //pcp->yPosInputLineStartValid = 1;

    //pcp->posInputBuffer = pcp->cntInputBuffer = 0;
    //pcp->bInsertMode = TRUE;
    //pcp->bInputReady = FALSE;

    //pcp->nCurrentSelectHistory = 0;

    ///* allow the cursor to start */
    //cursor(pcp, CS_RESUME);

    //do {
    //    ui_dispatch_next_event();
    //} while (!pcp->bInputReady);

    ///* stop the cursor */
    //cursor(pcp, CS_SUSPEND);

    //p = lib_stralloc(pcp->achInputBuffer);

    ///* Remove trailing newlines.  */
    //{
    //    int len;

    //    for (len = (int)strlen(p); len > 0 && (p[len - 1] == '\r' || p[len - 1] == '\n'); len--) {
    //        p[len - 1] = '\0';
    //    }
    //}

    ///* output input as output into file */
    //FileOut(pcp, p);
    //FileOut(pcp, "\n");

    //add_to_history(pcp, p);

    //return p;
	return 0;
}

console_t *console_open(const char *id)
{
	//...
	return NULL;
}

int console_close(console_t *log)
{
	//...
    return 0;
}

int console_init( void )
{
	//...
    return 0;
}

int console_close_all( void )
{
	//...
    return 0;
}
