#makefile do zadania 16 rozdzial04 tic++

__start__: all
	./a.out

all: zad16

zad16: zad16.cpp stash16.cpp stash16.h
	g++ -Wall -pedantic zad16.cpp stash16.cpp

clean:
	rm a.out
