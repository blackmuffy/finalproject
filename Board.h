// this is the Board class
#ifndef BOARD_H
#define BOARD_H
#include<iostream>
#include"Brick.h"

using namespace std;

class Board{

    public:
        Board();
        ~Board();
        char GetType(double, double);      
        void SetType(int, int, char);
        void DisplayBoard();

    private:
        
        Brick ** PlayingBoard;

};

Board::Board(){                        // make a board of Brick members

    PlayingBoard = new Brick*[36];
    for(int i = 0; i<36; i++)            // make an array that is 36 long
        PlayingBoard[i] = new Brick[12];      // make each row be 12 wide
        
    for(int m = 0; m<12; m++){
        PlayingBoard[0][m].setType('a');   
    }
    for(int n = 0; n<12; n++){
        for(int k = 1; k <36; k++){
            PlayingBoard[k][n].setType('e');
        }
    }
    //SetType(35,5,'p');
}

Board::~Board(){
    delete[] PlayingBoard;
}


char Board::GetType( double Xpos , double Ypos){
    int newx;
    int newy;
	//cout << Xpos << Ypos;
    if((Xpos < 0) || (Xpos > 600) || (Ypos < 0) || (Ypos > 900)){
		cout << "w";       
	 return('w');
    }
    newx = (int) Xpos/50;
    newy = (int) Ypos/25;
     
    cout << PlayingBoard[newy][newx].getType(); 
    return(PlayingBoard[newy][newx].getType());         // using the objfill member function to get stored type

}

void Board::SetType(int Ypos, int Xpos, char type){        // using the objfill member function to set type
    for(int i = 0; i<3; i++){
            PlayingBoard[Ypos][Xpos+i].setType(type);         
    }
}

void Board::DisplayBoard(){

    for(int i = 0; i<36; i++){
        for(int j = 0; j< 12; j++){
            cout << PlayingBoard[i][j].getType();         // displaying the type
        }
        cout << endl;
    }
}

#endif

