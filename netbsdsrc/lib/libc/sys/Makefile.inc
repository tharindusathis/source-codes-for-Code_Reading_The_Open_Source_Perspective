#	$NetBSD: Makefile.inc,v 1.71.2.4 1997/11/09 01:00:12 lukem Exp $
#	@(#)Makefile.inc	8.1 (Berkeley) 6/17/93

# sys sources
.PATH: ${.CURDIR}/arch/${MACHINE_ARCH}/sys ${.CURDIR}/sys

# modules with non-default implementations on at least one architecture:
SRCS+=	Ovfork.S brk.S exect.S fork.S pipe.S ptrace.S sbrk.S setlogin.S \
	sigpending.S sigprocmask.S sigreturn.S sigsuspend.S syscall.S
SRCS+=	cerror.S

LSRCS+=	Lint_Ovfork.c Lint_brk.c Lint_exect.c Lint_fork.c Lint_pipe.c \
	Lint_ptrace.c Lint_sbrk.c Lint_setlogin.c Lint_sigpending.c \
	Lint_sigprocmask.c Lint_sigreturn.c Lint_sigsuspend.c \
	Lint_syscall.c
DPSRCS+= Lint_Ovfork.c Lint_brk.c Lint_exect.c Lint_fork.c Lint_pipe.c \
	Lint_ptrace.c Lint_sbrk.c Lint_setlogin.c Lint_sigpending.c \
	Lint_sigprocmask.c Lint_sigreturn.c Lint_sigsuspend.c \
	Lint_syscall.c

# glue to provide compatibility between GCC 1.X and 2.X and for compat
# with old syscall interfaces.
SRCS+=	ftruncate.c lseek.c mmap.c semctl.c truncate.c stat.c msync.c swapon.c \
	getdirentries.c

# "stub" POSIX.1b interfaces which return -1 and set errno to ENOSYS, so
# we can avoid bumping libc's minor number as functions are added to the
# kernel.
SRCS+=	timer_create.c timer_delete.c timer_gettime.c timer_settime.c \
	timer_getoverrun.c

# modules with default implementations on all architectures:
ASM=	accept.o access.o acct.o adjtime.o bind.o chdir.o chflags.o chmod.o \
	chown.o chroot.o \
	clock_getres.o clock_gettime.o clock_settime.o \
	close.o connect.o dup.o dup2.o execve.o fchdir.o \
	fchflags.o fchmod.o fchown.o fcntl.o flock.o fpathconf.o \
	__fstat13.o fstatfs.o fsync.o futimes.o \
	getdents.o getfh.o getfsstat.o \
	getgroups.o getitimer.o __getlogin.o getpeername.o getpgid.o \
	getpgrp.o getpriority.o getrlimit.o getrusage.o \
	getsockname.o getsockopt.o gettimeofday.o ioctl.o kill.o \
	ktrace.o lchmod.o lchown.o __lstat13.o \
	lfs_bmapv.o lfs_markv.o lfs_segclean.o lfs_segwait.o link.o \
	listen.o lutimes.o madvise.o mincore.o minherit.o \
	mkdir.o mkfifo.o mknod.o mlock.o \
	mount.o mprotect.o msgctl.o msgget.o msgrcv.o msgsnd.o __msync13.o \
	munlock.o munmap.o nanosleep.o nfssvc.o ntp_adjtime.o ntp_gettime.o \
	open.o pathconf.o poll.o \
	profil.o quotactl.o \
	read.o readlink.o readv.o reboot.o \
	recvfrom.o recvmsg.o rename.o revoke.o \
	rmdir.o select.o semconfig.o semget.o semop.o sendmsg.o sendto.o \
	setegid.o seteuid.o setgid.o setgroups.o setitimer.o setpgid.o \
	setpriority.o setregid.o setreuid.o \
	setrlimit.o setsid.o setsockopt.o settimeofday.o \
	setuid.o shmat.o shmctl.o shmdt.o shmget.o shutdown.o sigaction.o \
	sigaltstack.o socket.o socketpair.o __stat13.o statfs.o swapctl.o \
	symlink.o sysarch.o umask.o undelete.o unlink.o unmount.o \
	utimes.o vadvise.o wait4.o write.o writev.o __semctl.o __syscall.o \
	__sysctl.o

PASM=	${ASM:.o=.po}
SASM=	${ASM:.o=.so}

NOERR=	getegid.o geteuid.o getgid.o getpid.o getppid.o getuid.o sync.o
PNOERR= ${NOERR:.o=.po}
SNOERR= ${NOERR:.o=.so}

PSEUDONOERR=	_exit.o
PPSEUDONOERR=	${PSEUDONOERR:.o=.po}
SPSEUDONOERR=	${PSEUDONOERR:.o=.so}

OBJS+=	${ASM} ${NOERR} ${PSEUDONOERR}

${PASM}: ${.CURDIR}/arch/${MACHINE_ARCH}/SYS.h \
    ${DESTDIR}/usr/include/sys/syscall.h
	@echo creating ${.TARGET}
	@printf '#include "SYS.h"\nRSYSCALL(${.PREFIX})\n' | \
	    ${CPP} -DPROF ${CPPFLAGS:M-[ID]*} ${AINC} | ${AS} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

${SASM}: ${.CURDIR}/arch/${MACHINE_ARCH}/SYS.h \
    ${DESTDIR}/usr/include/sys/syscall.h
	@echo creating ${.TARGET}
	@printf '#include "SYS.h"\nRSYSCALL(${.PREFIX})\n' | \
	    ${CPP} ${CPPPICFLAGS} ${CPPFLAGS:M-[ID]*} ${AINC} | \
	    ${AS} ${APICFLAGS} -o ${.TARGET}

${ASM}: ${.CURDIR}/arch/${MACHINE_ARCH}/SYS.h \
    ${DESTDIR}/usr/include/sys/syscall.h
	@echo creating ${.TARGET}
	@printf '#include "SYS.h"\nRSYSCALL(${.PREFIX})\n' | \
	    ${CPP} ${CPPFLAGS:M-[ID]*} ${AINC} | ${AS} -o ${.TARGET}.o
	@${LD} -x -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

${PNOERR}: ${.CURDIR}/arch/${MACHINE_ARCH}/SYS.h \
    ${DESTDIR}/usr/include/sys/syscall.h
	@echo creating ${.TARGET}
	@printf '#include "SYS.h"\nRSYSCALL_NOERROR(${.PREFIX})\n' | \
	    ${CPP} -DPROF ${CPPFLAGS:M-[ID]*} ${AINC} | ${AS} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

${SNOERR}: ${.CURDIR}/arch/${MACHINE_ARCH}/SYS.h \
    ${DESTDIR}/usr/include/sys/syscall.h
	@echo creating ${.TARGET}
	@printf '#include "SYS.h"\nRSYSCALL_NOERROR(${.PREFIX})\n' | \
	    ${CPP} ${CPPPICFLAGS} ${CPPFLAGS:M-[ID]*} ${AINC} | \
	    ${AS} ${APICFLAGS} -o ${.TARGET}

${NOERR}: ${.CURDIR}/arch/${MACHINE_ARCH}/SYS.h \
    ${DESTDIR}/usr/include/sys/syscall.h
	@echo creating ${.TARGET}
	@printf '#include "SYS.h"\nRSYSCALL_NOERROR(${.PREFIX})\n' | \
	    ${CPP} ${CPPFLAGS:M-[ID]*} ${AINC} | ${AS} -o ${.TARGET}.o
	@${LD} -x -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

${PPSEUDONOERR}: ${.CURDIR}/arch/${MACHINE_ARCH}/SYS.h \
    ${DESTDIR}/usr/include/sys/syscall.h
	@echo creating ${.TARGET}
	@printf '#include "SYS.h"\n \
	    PSEUDO_NOERROR(${.PREFIX},${.PREFIX:S/_//})\n' | \
	    ${CPP} -DPROF ${CPPFLAGS:M-[ID]*} ${AINC} | ${AS} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

${SPSEUDONOERR}: ${.CURDIR}/arch/${MACHINE_ARCH}/SYS.h \
    ${DESTDIR}/usr/include/sys/syscall.h
	@echo creating ${.TARGET}
	@printf '#include "SYS.h"\n \
	    PSEUDO_NOERROR(${.PREFIX},${.PREFIX:S/_//})\n' | \
	    ${CPP} ${CPPPICFLAGS} ${CPPFLAGS:M-[ID]*} ${AINC} | \
	    ${AS} ${APICFLAGS} -o ${.TARGET}


${PSEUDONOERR}: ${.CURDIR}/arch/${MACHINE_ARCH}/SYS.h \
    ${DESTDIR}/usr/include/sys/syscall.h
	@echo creating ${.TARGET}
	@printf '#include "SYS.h"\n \
	    PSEUDO_NOERROR(${.PREFIX},${.PREFIX:S/_//})\n' | \
	    ${CPP} ${CPPFLAGS:M-[ID]*} ${AINC} | ${AS} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

# Lint stubs for all automatically-generated assembly stubs (GENERATED)
LSRCS+=	LintSysNormal.c LintSysNoerr.c LintSysPseudoNoerr.c
DPSRCS+= LintSysNormal.c LintSysNoerr.c LintSysPseudoNoerr.c

CLEANFILES+= LintSysNormal.c LintSysNoerr.c LintSysPseudo.c

LintSysNormal.c: ${.CURDIR}/sys/makelintstub \
    ${DESTDIR}/usr/include/sys/syscall.h
	@echo creating ${.TARGET}
	@sh ${.CURDIR}/sys/makelintstub -o ${.TARGET} \
	    -s ${DESTDIR}/usr/include/sys/syscall.h ${ASM}

LintSysNoerr.c: ${.CURDIR}/sys/makelintstub \
    ${DESTDIR}/usr/include/sys/syscall.h
	@echo creating ${.TARGET}
	@sh ${.CURDIR}/sys/makelintstub -o ${.TARGET} -n \
	    -s ${DESTDIR}/usr/include/sys/syscall.h ${NOERR}

LintSysPseudoNoerr.c: ${.CURDIR}/sys/makelintstub \
    ${DESTDIR}/usr/include/sys/syscall.h
	@echo creating ${.TARGET}
	@sh ${.CURDIR}/sys/makelintstub -o ${.TARGET} -p \
	    -s ${DESTDIR}/usr/include/sys/syscall.h ${PSEUDONOERR}

MAN+=	accept.2 access.2 acct.2 adjtime.2 bind.2 brk.2 chdir.2 chflags.2 \
	chmod.2 chown.2 chroot.2 close.2 connect.2 dup.2 execve.2 _exit.2 \
	fcntl.2 flock.2 fork.2 fsync.2 getdents.2 getdirentries.3 getfh.2 \
	getfsstat.2 getgid.2 getgroups.2 getitimer.2 getlogin.2 getpeername.2 \
	getpgrp.2 getpid.2 getpriority.2 getrlimit.2 getrusage.2 getsockname.2 \
	getsockopt.2 gettimeofday.2 getuid.2 intro.2 ioctl.2 kill.2 ktrace.2 \
	link.2 listen.2 lseek.2 mkdir.2 \
	mkfifo.2 mknod.2 madvise.2 mincore.2 minherit.2 \
	mlock.2 mmap.2 mount.2 mprotect.2 msgctl.2 msgget.2 msgrcv.2 \
	msgsnd.2 msync.2 munmap.2 nanosleep.2 nfssvc.2 open.2 pathconf.2 \
	pipe.2 poll.2 \
	profil.2 ptrace.2 quotactl.2 read.2 readlink.2 reboot.2 recv.2 \
	rename.2 revoke.2 rmdir.2 select.2 semctl.2 semget.2 semop.2 \
	send.2 setgroups.2 setpgid.2 setregid.2 setreuid.2 setsid.2 setuid.2 \
	shmat.2 shmctl.2 shmget.2 \
	shutdown.2 sigaction.2 sigaltstack.2 sigpending.2 \
	sigprocmask.2 sigreturn.2 sigstack.2 sigsuspend.2 socket.2 \
	socketpair.2 stat.2 statfs.2 swapctl.2 swapon.3 symlink.2 sync.2 \
	sysarch.2 syscall.2 truncate.2 umask.2 unlink.2 utimes.2 vfork.2 \
	wait.2 write.2

MLINKS+=brk.2 sbrk.2
MLINKS+=dup.2 dup2.2
MLINKS+=chdir.2 fchdir.2
MLINKS+=chflags.2 fchflags.2
MLINKS+=chmod.2 fchmod.2 chmod.2 lchmod.2
MLINKS+=chown.2 fchown.2 chown.2 lchown.2
MLINKS+=getgid.2 getegid.2
MLINKS+=getitimer.2 setitimer.2
MLINKS+=getlogin.2 setlogin.2
MLINKS+=getpgrp.2 getpgid.2
MLINKS+=getpid.2 getppid.2
MLINKS+=getpriority.2 setpriority.2
MLINKS+=getrlimit.2 setrlimit.2
MLINKS+=getsockopt.2 setsockopt.2
MLINKS+=gettimeofday.2 settimeofday.2
MLINKS+=getuid.2 geteuid.2
MLINKS+=intro.2 errno.2
MLINKS+=lseek.2 seek.2
MLINKS+=mlock.2 munlock.2
MLINKS+=mount.2 unmount.2
MLINKS+=pathconf.2 fpathconf.2
MLINKS+=read.2 readv.2
MLINKS+=recv.2 recvfrom.2 recv.2 recvmsg.2
MLINKS+=send.2 sendmsg.2 send.2 sendto.2
MLINKS+=setpgid.2 setpgrp.2
MLINKS+=setuid.2 setegid.2 setuid.2 seteuid.2 setuid.2 setgid.2
MLINKS+=shmat.2 shmdt.2
MLINKS+=stat.2 fstat.2 stat.2 lstat.2
MLINKS+=statfs.2 fstatfs.2
MLINKS+=syscall.2 __syscall.2
MLINKS+=truncate.2 ftruncate.2
MLINKS+=utimes.2 futimes.2 utimes.2 lutimes.2
MLINKS+=wait.2 wait3.2 wait.2 wait4.2 wait.2 waitpid.2
MLINKS+=write.2 writev.2
