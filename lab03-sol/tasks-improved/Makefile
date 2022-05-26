# Copyright 2020 Darius Neatu (neatudarius@gmail.com)

# compiler
CC = gcc

# compiler flags
CFLAGS = -Wall -Wextra

# object files
OBJ = util.o tester.o main.o

build: util tester main
	$(CC) $(OBJ) -o lab_fun

util: util.h util.c
	$(CC) $(CFLAGS) -c $@.c

tester: tester.h tester.c
	$(CC) $(CFLAGS) -c $@.c

main: main.c
	$(CC) $(CFLAGS) -c $@.c

run: build
	./lab_fun

clean:
	rm -f *.o lab_fun
