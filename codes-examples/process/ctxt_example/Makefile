TARGET=./example

CC=cc

#
DIR_OBJ=objs
SOURCES=$(wildcard *.c)
OBJECTS=$(patsubst %.c,$(DIR_OBJ)/%.o,$(SOURCES))

INCLUDES =-I. -I./include
CFLAGS =-std=c17 -Wno-deprecated  
LDFLAGS =-L/usr/local/lib 
LDLIBS = -lm -lpthread 

all: $(TARGET)
	@echo Made [ $? ] OK :\)
	
$(TARGET): $(OBJECTS) 
	@echo Linking [$@]
	@eval $(CC) $(LDFLAGS) $^ $(LDLIBS)  -o $@ 
	
$(DIR_OBJ)/%.o: %.c
	@echo Compiling [$@]
	@mkdir -p $(DIR_OBJ)
	@eval $(CC) -c $(INCLUDES) $(CFLAGS)  $< -o $@
	
clean:
	@$(RM) core *~ \#*\# *.bak *.BAK *\%
	@$(RM) -f .dummy $(OBJECTS)

distclean:
	@$(RM) $(TARGET)
	@$(RM) -rf $(DIR_OBJ)






