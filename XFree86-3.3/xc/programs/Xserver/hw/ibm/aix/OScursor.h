/*
 * $XConsortium: OScursor.h,v 1.2 91/07/16 12:56:33 jap Exp $
 *
 * Copyright IBM Corporation 1987,1988,1989,1990,1991
 *
 * All Rights Reserved
 *
 * License to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted,
 * provided that the above copyright notice appear in all copies and that
 * both that copyright notice and this permission notice appear in
 * supporting documentation, and that the name of IBM not be
 * used in advertising or publicity pertaining to distribution of the
 * software without specific, written prior permission.
 *
 * IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
 * ALL IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS, AND 
 * NONINFRINGEMENT OF THIRD PARTY RIGHTS, IN NO EVENT SHALL
 * IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
 * ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 *
*/

#ifndef OSCURSOR_H
#define OSCURSOR_H

#define	OS_TellCursorPosition(x,y) \
	{ AIXCurrentX = (x) ; AIXCurrentY = (y) ; }

extern	int	AIXSetCursorPosition() ;
extern	void	AIXPointerNonInterestBox() ;
extern	void	AIXConstrainCursor() ;
extern  void   	AIXCursorLimits() ; 

#define	OS_SetCursorPosition		AIXSetCursorPosition
#define	OS_PointerNonInterestBox	AIXPointerNonInterestBox
#define OS_ConstrainCursor		AIXConstrainCursor
#define	OS_CursorLimits			AIXCursorLimits

#endif /* OSCURSOR_H */
