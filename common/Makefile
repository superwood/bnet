include Makefile.env

VERSION64_SIGN=64bit
ifeq ($(MAC),64)
	VERSION_SIGN=-D__64BIT__
else
	VERSION_SIGN=32bit
endif


TOPDIR=.
INCDIR=$(TOPDIR)/include
SRCDIR=$(TOPDIR)/src

LIBDIR=lib
LIBNAME=libbnet.a
SCRIPTDIR=script
OUTPUTDIR=output

vpath %.h $(INCDIR) : ./
vpath %.cpp $(SRCDIR) : ./

CC=gcc
CXX=g++
LD=ld
AR=ar cr
RM=rm -rf
CP=cp -rf
MKDIR=mkdir -p

CFLAGS= -g -W -Wall -Wshadow -Wno-unused-parameter -Wformat -Wconversion -Wdeprecated -Wfloat-equal -Werror \
		-finline-functions \
		-I./ \
		-I$(INCDIR) \
		-D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 \
		$(VERSION_SIGN)

CXXFLAGS=$(CFLAGS)

LDFLAGS=  \

LDLIBS= -lpthread \
		-lcrypto \

_DEBUG= 0
ifeq ($(_DEBUG), 1)
	#CFLAGS+= -pg
	CXXFLAGS+= -pg
	LDFLAGS+= -pg
else
	#CFLAGS+= -DNDEBUG
	CXXFLAGS+= -DNDEBUG
	LDFLAGS+= -DNDEBUG
endif

CLEANFILES= *.o core.* *.gdb *.out nulllog nulllog.wf \
			$(LIBDIR)/$(LIBNAME) $(OUTPUTDIR)

OBJS = thread.o 

all: $(LIBDIR)/$(LIBNAME)

$(IDL_NAME).o : $(IDL_NAME)
	$(CXX) $(CXXFLAGS) -c  -o $(IDL_NAME).o $(IDL_NAME).cpp

$(LIBDIR)/$(LIBNAME): $(OBJS)
	if [ ! -d $(LIBDIR) ]; then $(MKDIR) $(LIBDIR); fi
	if [ ! -d $(OUTPUTDIR) ]; then $(MKDIR) $(OUTPUTDIR); fi
	$(RM) $@
	$(AR) $@ $^
	$(CP) $(LIBDIR) $(INCDIR) $(OUTPUTDIR)
	$(CP) $(IDL_NAME).h $(OUTPUTDIR)/include
	#$(CP) $(SCRIPTDIR) $(OUTPUTDIR)

.PHONY: clean
clean:
	$(RM) $(CLEANFILES)
