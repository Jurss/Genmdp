CC=gcc
CFLAGS=-Wall -Wextra -Werror
LDFLAGS=
EXEC=Genmdp
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

Genmdp: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

*.o: *.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)
