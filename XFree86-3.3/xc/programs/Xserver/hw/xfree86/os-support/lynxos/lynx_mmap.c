/*
 * Copyright 1993 by Thomas Mueller
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Thomas Mueller not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  Thomas Mueller makes no representations
 * about the suitability of this software for any purpose.  It is provided
 * "as is" without express or implied warranty.
 *
 * THOMAS MUELLER DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THOMAS MUELLER BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 */

/* $XFree86: xc/programs/Xserver/hw/xfree86/os-support/lynxos/lynx_mmap.c,v 3.2 1996/09/29 13:38:29 dawes Exp $ */

#include "X.h"
#include "input.h"
#include "scrnintstr.h"

#include "xf86.h"
#include "xf86Priv.h"
#include "xf86_OSlib.h"

/*
 * Read BIOS using smem_create facility
 */

int xf86ReadBIOS(Base, Offset, Buf, Len)
unsigned long Base;
unsigned long Offset;
unsigned char *Buf;
int Len;
{
	char *p;
	int mlen;

	mlen = (Offset + Len + 4095) & ~4096;
	p = smem_create("BIOS-probe", (char *)Base, mlen, SM_READ);
	if (p == NULL)
	{
		/* check if there is a stale segment around */
		if (smem_remove("BIOS-probe") == 0) {
		    ErrorF("xf86ReadBios: removed stale smem_ segment\n");
		    p = smem_create("BIOS-probe", (char *)Base, mlen, SM_READ);
		}
		if (p == NULL) {
		    ErrorF("xf86ReadBios: Failed to smem_create Base %x len %x %s \n",
			    Base, mlen, strerror(errno));
		    return(-1);
		}
	}
	memcpy(Buf, p + Offset, Len);
	smem_create(NULL, p, 0, SM_DETACH);
	smem_remove("BIOS-probe");
	return(Len);
}
