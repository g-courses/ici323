TARGET=./io_example

DEBUG=-DDEBUG
DEBUG=

CXX = g++

#
DIR_OBJ=objs
SOURCES=$(wildcard *.cc)
OBJECTS=$(patsubst %.cc,$(DIR_OBJ)/%.o,$(SOURCES))

RESTCLIENT_DIR=/usr/local/restclient-cpp
RESTCLIENT_INCLUDE=$(RESTCLIENT_DIR)/include
RESTCLIENT_LIB=$(RESTCLIENT_DIR)/lib
RESTCLIENT_LDFLAGS=$(RESTCLIENT_LIB) -Wl,-rpath -Wl,$(RESTCLIENT_LIB)

INCLUDES =-I. -I./include -I$(RESTCLIENT_INCLUDE)
CPPFLAGS =-std=c++17  -Wno-deprecated $(INTRINSICS)  
LDFLAGS =-L/usr/local/lib -L$(RESTCLIENT_LDFLAGS)
LDLIBS = -lm -lpthread -lrestclient-cpp

all: $(TARGET)
	@echo Made [ $? ] OK :\)
	
$(TARGET): $(OBJECTS) 
	@echo Linking [$@]
	@eval $(CXX) $(LDFLAGS) $^ $(LDLIBS)  -o $@ 
	
$(DIR_OBJ)/%.o: %.cc
	@echo Compiling [$@]
	@mkdir -p $(DIR_OBJ)
	@eval $(CXX) -c $(INCLUDES) $(CPPFLAGS)  $< -o $@
	
clean:
	@$(RM) core *~ \#*\# *.bak *.BAK *\%
	@$(RM) -f .dummy $(OBJECTS)

distclean:
	@$(RM) $(TARGET)







