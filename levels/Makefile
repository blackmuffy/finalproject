all: main

main: main.cpp Board.h Brick.h graphics.h
    g++ main.cpp -o main -Wall -w -lSDL2 -lSDL2_image -lSDL2_ttf -std=c++0x

#main.o: main.cpp
#    g++ -c main.cpp

#Board.o: Board.h Bricks.h
#    g++ -c Board.h Bricks.h

clean:
    rm -f *.o main
