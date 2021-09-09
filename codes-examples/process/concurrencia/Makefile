#
# Seccion 1
#
# Esta seccion se puede modificar segun
# los requerimientos de su proyecto

CC=gcc
SRC=ejemplo.c

#
# Seccion 2 (NO MODIFICAR!!!)
#

OBJ=$(SRC:.c=.o)
BIN=$(SRC:.c= )

default: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)
	
%.o: %.c
	$(CC) -c -o $@ $<

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f $(BIN)

run:
	./$(BIN)	