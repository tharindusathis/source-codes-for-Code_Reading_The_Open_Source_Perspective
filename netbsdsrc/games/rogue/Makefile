#	$NetBSD: Makefile,v 1.8.2.2 1997/11/20 09:06:47 mrg Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	rogue
CPPFLAGS+=-DUNIX -fwritable-strings
SRCS=	curses.c hit.c init.c inventory.c level.c machdep.c main.c \
	message.c monster.c move.c object.c pack.c play.c random.c ring.c \
	room.c save.c score.c spec_hit.c throw.c trap.c use.c zap.c
DPADD=	${LIBCURSES} ${LIBTERM} ${LIBCOMPAT}
LDADD=	-lcurses -ltermlib -lcompat
HIDEGAME=hidegame
SETUIDGAME=yes
MAN=	rogue.6

.if make(install)
SUBDIR+=USD.doc
.endif

.include <bsd.prog.mk>
.include <bsd.subdir.mk>
