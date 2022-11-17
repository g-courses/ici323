TARGET=./example

CC=gcc
RM=rm -f



INCLUDES=-I.
LDFLAGS=-L/usr/local/lib 
LDLIBS=-lpthread

CCFLAGS=-std=c17 -Wall

DIR_OBJ=objs

SRCS=$(wildcard *.c)

OBJS=$(patsubst %.c,$(DIR_OBJ)/%.o,$(SRCS))


all: $(TARGET)
	@echo Made [ $? ] OK :\)

$(TARGET): $(OBJS)
	@echo Linking [$@]
	@$(CC) -o $@ $^ $(CCFLAGS) $(LDLIBS) $(LDFLAGS) 

$(DIR_OBJ)/%.o: %.c
	@echo Compiling [$@]
	@mkdir -p $(DIR_OBJ)
	@$(CC) -c -o $@ $< $(CCFLAGS) $(INCLUDES)

clean:
	@$(RM) $(OBJS)
	@$(RM) *~ core

distclean: clean
	@$(RM) $(TARGET)
	@$(RM) -r $(DIR_OBJ)

.PHONY: all clean distclean
	
