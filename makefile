GCC = gcc -g

all: tunez.o main.o
	$(GCC) tunez.o main.o -o tunetest

tunez.o: tunez.c tunez.h
	$(GCC) -c tunez.c

main.o: main.c
	$(GCC) -c main.c
clean:
	rm *.o
	rm *~

run: all
	./tunetest
