all: main

main: main.cpp Board.h Brick.h
	g++ main.cpp -o main -Wall

#main.o: main.cpp
#	g++ -c main.cpp

#Board.o: Board.h Bricks.h
#	g++ -c Board.h Bricks.h

clean: 
	rm -f *.o main
