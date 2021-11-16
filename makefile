all: forker

forker: main.o
	gcc main.o -o forker
main.o: main.c
	gcc -c main.c

run:
	./forker

