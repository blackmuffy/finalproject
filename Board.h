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
        char GetType(int, int);      
        void SetType(int, int, char);
        void DisplayBoard();
        void Paddlesettings(int, int); 		// changes the specs of the paddle
        int Paddlecheck(int); 			// checks if ball hit paddle since the paddle is an irregular size
	int doHit(int,int); 			// returns important indicators ie. the shooting brick one is hit 
	char FindPopular(); 			// returns most popular color
	
    private:
        
        Brick ** PlayingBoard;
	int paddlelength; 
	int paddleposition; 
	int newx; 
	int newy; 
};

Board::Board(){                        				  // constructor
    //MAIN BOARD array creation-----------|
    PlayingBoard = new Brick*[36];
    for(int i = 0; i<36; i++)           			  // make an array that is 36 long
        PlayingBoard[i] = new Brick[12];      			  // make each row be 12 wide
        
    for(int n = 0; n<12; n++){					  // initializing board to all empty space
        for(int k = 1; k <36; k++){
        	SetType(n,k,'e');
        }
    }
   //-------------------------------------|
    for(int m= 0; m<12; m++){
    	SetType(m,34,'a');
    }
    
   //PADDLE-------------------------------|			     initalizing all entire bottom row to be solid 
   for( int p = 0; p<12; p++)
   	SetType(p,35,'s');
   								  // initiate normal paddle variables 
   paddlelength = 40; 
   paddleposition = 300-paddlelength/2; 
   //-------------------------------------|
}

Board::~Board(){						  // deconstructor
    delete[] PlayingBoard;
}
char Board::FindPopular(){					  // Finds most popular color on board
	int colorcount[] = {0,0,0,0,0};				  //initialize count to 0  
	int mostpopular;  
	int k; 
	
	for(int i = 0; i<12; i++){
		for(int j = 0; j<36; j++){
		
			if(PlayingBoard[j][i].getType()=='a'){
				cout << "here"; 
				for(int compare = 0; compare< 5; compare++){			// runs through all the colors 
					if(PlayingBoard[j][i].getColor() == compare){	// in SHRINK COORDINATES
						colorcount[compare]++; 
					}
					
				}
			}
		}
	}
	
	mostpopular = 0; 						
	for( k = 0; k<4; k++){
		if(colorcount[k]>colorcount[k+1]){
			mostpopular = k;			//mostpopular is the array in colorcount that has the highest number
			cout << mostpopular<<endl; 
		}
	}
	
	if(mostpopular == 0)
		return(6); 
	else 
		return(mostpopular); 
}

int Board::doHit(int xpos, int ypos){				  // update the type of the spot once hit in WINDOW COORDINATES

	switch(GetType(xpos,ypos)){
		case 'a':					  // single brick type 
			SetType(newx,newy,'e');
			return 0;  
			break; 
		case 'h': 					  // double-hit brick type
			SetType(newx,newy,'a');
			return 0;  
			break; 
		case 'x': 
			SetType(newx,newy,'e');
			for(int i = 0; i<12; i++){
				for(int j = 0; j<36; j++){
					if(PlayingBoard[j][i].getColor() == FindPopular()){
						SetType(i,j,'e'); 
					}
						
				}			
			}
			return 0; 
			break; 
		case 'g': 
			return 1; 				  // return 1 for guns should be turned on 
			break;  
				
	}
	return 0; 
}

int Board::Paddlecheck(int xpos){
	for(int i = 0; i<paddlelength; i++){ 			// paddle length has to be in pixels; 
		if((paddleposition+i)==xpos)
			return 1; 				// ball fell paddle area 
		else 
			return 0; 				// ball fell into "empty space" 	
	}
	return 0; 
	
}

void Board::Paddlesettings(int lengthchange,int positionchange){				//if we want 'easy' change would = 20, if we want hard 'change would = -20
		paddlelength = paddlelength + lengthchange;
		paddleposition = paddleposition + positionchange; 				// given user input to move the paddle;   
}


char Board::GetType( int Xpos , int Ypos){					// IN WINDOW COORDINATES

    if((Xpos < 0) || (Xpos > 600) || (Ypos < 0) || (Ypos > 900)){		// ball hit wall boundaries 
		cout << "w";       
	 return('w');
    }
    newx = (int) Xpos/50;
    newy = (int) Ypos/25;
     
    cout << PlayingBoard[newy][newx].getType(); 
    return(PlayingBoard[newy][newx].getType());         	 // using the objfill member function to get stored type

}

void Board::SetType(int Xpos, int Ypos, char type){       	 // using the objfill member function to set type in BOARD COORDINATES
            PlayingBoard[Ypos][Xpos].setType(type);         
}

void Board::DisplayBoard(){

    for(int i = 0; i<36; i++){
        for(int j = 0; j< 12; j++){
            cout << PlayingBoard[i][j].getType();        	 // displaying the type
        }
        cout << endl;
    }
}

#endif

