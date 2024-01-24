CC = gcc
CFLAGS = -g -std=c11 -Werror
LIBS = -lcurses
OUT = sokoban

all:	$(OUT)

$(OUT):	*.c *.h
	cppcheck *.c
	$(CC) $(CFLAGS) *.c -o $(OUT) $(LIBS)

clean:
	rm -f $(OUT) *.o
