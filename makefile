GCC = gcc -g

all: tunez.o
	$(GCC) tunez.o -o tunetest

tunez.o: tunez.c tunez.h
	$(GCC) -c tunez.c

clean:
	rm *.o
	rm *~

run: all
	./tunetest
