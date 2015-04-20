all: main

main: main.o Board.o
	g++ main.o Board.o -o main -Wall

main.o: main.cpp
	g++ -c main.cpp

Board.o: Board.h Bricks.h
	g++ -c Board.h Bricks.h

clean: 
	rm -f *.o main
