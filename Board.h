// this is the Board class 
#ifndef BOARD_H 
#define BOARD_H
#include<iostream> 
#include"ObjFill.h" 

using namespace std; 

class Board{

	public: 
		Board(); 
		~Board(); 
		char GetType(int, int);  	
		void SetType(int, int, char); 
		void DisplayBoard(); 
	private:
		
		ObjFill ** PlayingBoard;

}; 

Board::Board(){
	
	PlayingBoard = new ObjFill*[12];
	for(int i = 0; i<12; i++)
		PlayingBoard[i] = new ObjFill[36];  
		
	for(int m = 0; m<12; m++){
		PlayingBoard[0][m].setType('a');   
	}
	for(int n = 0; n<12; n++){
		for(int k = 1; k <36; k++){
			PlayingBoard[k][n].setType('e'); 
		} 
	}
	//SetType(35,21,'p');
}

Board::~Board(){
	delete[] PlayingBoard; 
}

char Board::GetType( int Xpos , int Ypos){
	return(PlayingBoard[Ypos][Xpos].getType()); 

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