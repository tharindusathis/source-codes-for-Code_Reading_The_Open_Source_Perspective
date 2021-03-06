# platform_sunos5_ghs.GNU,v 4.8 2000/10/27 17:29:16 cleeland Exp

# SunOS 5.x (Solaris 2.x) with GreenHills compiler.

debug = 1
exceptions = 0
optimize = 1
threads = 1

CC       = gcx
CXX      = $(CC)
CCFLAGS  += $(CFLAGS) --no_rtti -tnone
DCFLAGS  += -g
DLD      = $(CXX)
LD       = $(CXX)
LDFLAGS  = --no_auto_instantiation
LIBS     += -lsocket -ldl -lgen -lnsl -lposix4
OCFLAGS  += -OL -OM
PIC      = -PIC
RANLIB   = @true
AR       = $(CC) $(LDFLAGS)
ARFLAGS  = -archive -o
RANLIB   = @true
SOFLAGS  = -shared

ifeq ($(threads),1)
  #### Don't use g7 register with threading.
  CFLAGS += -Xleaveg7
  LIBS += -lthread
else  # ! threads
  CFLAGS += -DACE_MT_SAFE=0
endif # ! threads

ifeq (1,$(exceptions))
  CCFLAGS += --exceptions
else  # ! exceptions
  CCFLAGS += --no_exceptions
endif # ! exceptions
