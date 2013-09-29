TOPDIR=./
include ./Makefile.env

CXX=g++
RM=rm -f
MKDIR=mkdir -p
RMDIR=rm -Rf
CP=cp -f
CPDIR=cp -fr
MV=mv -f

SRC_PATH=./src
TEST_PATH=./test
CONF_PATH=./conf
RELEASE_DIR=./output/
RELEASE_CONF_DIR=$(RELEASE_DIR)/conf
RELEASE_BIN_DIR=$(RELEASE_DIR)/bin

TEST_PARA=$(UNIT_TEST)

CC_EXEC=bnet
output : all
	if [ -d $(RELEASE_DIR) ]; then $(RMDIR) $(RELEASE_DIR); fi
	$(MKDIR) $(RELEASE_DIR)
	$(MKDIR) $(RELEASE_CONF_DIR)
	$(MKDIR) $(RELEASE_BIN_DIR)
	$(CP) $(CONF_PATH)/*.conf* $(RELEASE_CONF_DIR)/
	$(CP) $(CC_EXEC) $(RELEASE_BIN_DIR)/
	$(CP) $(CC_EXEC) $(RELEASE_BIN_DIR)

all: $(CC_EXEC) libtrade.a

CLEANFILES = $(OBJS) $(CONCHECK_EXEC) 
clean :
	$(RM) $(CLEANFILES)
	$(RMDIR) $(RELEASE_DIR)
	$(RM) $(CC_EXEC) 
SOURCES=$(wildcard ./src/*.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SOURCES))

$(CC_EXEC) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
