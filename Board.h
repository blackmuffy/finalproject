// this is the Board class 
#ifndef BOARD_H 
#define BOARD_H
#include<iostream> 
#include"Bricks.h" 
using namespace std; 

class Board{

	public: 
		Board(); 
		~Board(); 
		char GetType(int, int);  	
		void SetType(int, int, char); 
		void DisplayBoard(); 
	private:
		
		Bricks ** PlayingBoard;

}; 

Board::Board(){
	
	PlayingBoard = new Bricks*[42];
	for(int i = 0; i<42; i++)
		PlayingBoard[i] = new Bricks[36];  
		
	for(int m = 0; m<42; m++){
		PlayingBoard[0][m].setType('a');   
	}
	for(int n = 0; n<42; n++){
		for(int k = 1; k <36; k++){
			PlayingBoard[k][n].setType('e'); 
		} 
	}
	SetType(35,21,'p');
}

Board::~Board(){
	delete[] PlayingBoard; 
}

char Board::GetType( int Xpos , int Ypos){
	

}

void Board::SetType(int Ypos, int Xpos, char type){
	for(int i = 0; i<3; i++){
			PlayingBoard[Ypos][Xpos+i].setType(type);   	  
	}
}

void Board::DisplayBoard(){

	for(int i = 0; i<36; i++){
		for(int j = 0; j< 42; j++){
			cout << PlayingBoard[i][j].getType(); 
		}
		cout << endl; 
	}
}

#endif
