// this is the Board class
#ifndef BOARD_H
#define BOARD_H
#include<iostream>
#include"Brick.h"
#include"graphics.h"
#include <fstream> // include fstream to read in files
#include <cstring> // needed to use file.open
#include <vector> // to store types and colors in 
#include <string> // to store filename 

using namespace std;

class Board{

    public:
        Board();
        ~Board();
        char GetType(int, int);      
        void SetType(int, int, char,int);
        void DisplayBoard();
        void Paddlesettings(int, int); 		// changes the specs of the paddle
        int Paddlecheck(int); 			// checks if ball hit paddle since the paddle is an irregular size
	int doHit(int,int); 			// returns important indicators ie. the shooting brick one is hit 
	char FindPopular(); 			// returns most popular color
	void DrawOnWindow(int, int); 
	void EndGame(); 
	void readfiles(string);			// to read in level board file
	bool quit();
	
    private:
        
        Brick ** PlayingBoard;
	int paddlelength; 
	int paddleposition; 
	int paddlenumber; 
	
	int newx; 
	int newy; 
	Graphics window; 					  //initiate window 
	vector< vector <char> > typeVec; // vec to store board types
  	vector< vector <int> > colorVec; // vec to store board colors
};

Board::Board(){                        				  // constructor
    
    //MAIN BOARD array creation-----------|
    PlayingBoard = new Brick*[36];
    for(int i = 0; i<36; i++)           			  // make an array that is 36 long
        PlayingBoard[i] = new Brick[12];      			  // make each row be 12 wide
    //-------------------------------------|

    //INIT BOARD WITHOUT FILE -------------|    
    /*for(int n = 0; n<12; n++){					  // initializing board to all empty space
        for(int k = 1; k <36; k++){
        	SetType(n,k,'e',1);
        }
    }
    for(int m= 0; m<12; m++){
    	SetType(m,0,'a',1);
    	SetType(m,2,'a',1); 
    	SetType(m,5,'a',1); 
    }*/
    //------------------------------------|

  // INIT BOARD WITH FILE ----------------|
	readfiles("levels/level4.txt"); // read in level file
	for(int n = 0; n<12; n++){		// setting type and color
        	for(int k = 0; k <36; k++){
        		SetType(n,k,typeVec[k][n],colorVec[k][n]);
        	}
  	}
  //-------------------------------------|
    
   //PADDLE-------------------------------|			     initalizing all entire bottom row to be solid 
   for( int p = 0; p<12; p++)
   	SetType(p,35,'i',1);
    
   paddlenumber = 2; 								  // initiate normal paddle variables 
   paddleposition = 300-paddlelength/2; 
   //-------------------------------------|
}

Board::~Board(){						  // deconstructor
    delete[] PlayingBoard;
}
void Board::EndGame(){
	window.endGame(); 
}
void Board::DrawOnWindow(int xpos, int ypos){
	window.updatebackground(); 
	
	for(int i = 0; i<12; i++){
		for(int j = 0; j<36; j++){
			window.placeBrick(i*50,j*25,PlayingBoard[j][i].getType(),PlayingBoard[j][i].getColor()); 
		}
	}
	
       /* for(int a = 0; a<12; a++){ // sara added all this shit in lab and it probably shouldnt be hre
		SetType(a,0,'a',3);
	}
        for(int b = 0; b<12; b++){
		SetType(b,35,'i',3);
	}*/
	
	window.drawBall(xpos,ypos);
	paddleposition = window.drawPaddle(paddleposition,2);
	window.update(); 
	
}

char Board::FindPopular(){					  // Finds most popular color on board
	int colorcount[] = {0,0,0,0,0};				  //initialize count to 0  
	int mostpopular;  
	int k; 
	
	for(int i = 0; i<12; i++){
		for(int j = 0; j<36; j++){
		
			if(PlayingBoard[j][i].getType()=='a'){
				//cout << "here"; 
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
			//cout << mostpopular<<endl; 
		}
	}
	
	if(mostpopular == 0)
		return(6); 
	else 
		return(mostpopular); 
}

int Board::doHit(int xpos, int ypos){				  // update the type of the spot once hit in WINDOW COORDINATES
	//cout << "here" << endl;
	//cout << GetType(xpos,ypos) << endl; 
	//cout << newx <<" "<<newy << endl; 
	switch(GetType(xpos,ypos)){
		case 'a':					  // single brick type 
			SetType(newx,newy,'e',1);
			cout << "A" << endl; 
			return 0;  
			break; 
		case 'h': 					  // double-hit brick type
			SetType(newx,newy,'a',1);
			return 0;  
			break; 
		case 'x': 
			SetType(newx,newy,'e',1);
			for(int i = 0; i<12; i++){
				for(int j = 0; j<36; j++){
					if(PlayingBoard[j][i].getColor() == FindPopular()){
						SetType(i,j,'e',1); 
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
	//cout << paddleposition<<" "<< xpos << endl; 
	
	if(paddlenumber == 1)
		paddlelength = 40; 
	if(paddlenumber == 2)
		paddlelength = 60; 
	if(paddlenumber == 3) 
		paddlelength = 80; 
		
	for(int i = 0; i<paddlelength; i++){ 			// paddle length has to be in pixels; 
		if((paddleposition-paddlelength/2+i)==xpos)
			return 1; 				// ball fell paddle area 	
	}
	return 0; 
	
}

void Board::Paddlesettings(int lengthchange,int positionchange){				//if we want 'easy' change would = 20, if we want hard 'change would = -20
		paddlelength = paddlelength + lengthchange;
		paddleposition = paddleposition + positionchange; 				// given user input to move the paddle;   
}


char Board::GetType( int Xpos , int Ypos){					// IN WINDOW COORDINATES

    if((Xpos < 0) || (Xpos > 600) || (Ypos < 0) || (Ypos > 900)){		// ball hit wall boundaries 
		//cout << "w";       
	 return('w');
    }
    newx = (int) Xpos/50;
    newy = (int) Ypos/25;

   // cout << PlayingBoard[newy][newx].getType(); 
    return(PlayingBoard[newy][newx].getType());         	 // using the objfill member function to get stored type

}

void Board::SetType(int Xpos, int Ypos, char type, int color){       	 // using the objfill member function to set type in BOARD COORDINATES
            PlayingBoard[Ypos][Xpos].setType(type);         
            PlayingBoard[Ypos][Xpos].setColor(color);  
}

void Board::DisplayBoard(){

    for(int i = 0; i<36; i++){
        for(int j = 0; j< 12; j++){
            cout << PlayingBoard[i][j].getType();        	 // displaying the type
        }
        cout << endl;
    }
}

void Board::readfiles(string filename){

  ifstream inFile;
  inFile.open(filename.c_str());

  // read in file
  char tempType; // temp char to store type being read in 
  int tempColor; // temp int to store color code being read in
  vector<char> tempTypeVec; // temp vec to store row of types
  vector<int> tempColorVec; // temp vec to store row of color codes
  
  //if(!inFile) cout << "inFile";
  while(!inFile.eof()){ //while the file in not at the end
	for(int i = 0; i < 12 ; i++){ // go through files, 12 bricks per row
		inFile >> tempType >> tempColor; // take in the type and color of each element
		tempTypeVec.push_back(tempType); // push type into temp vec
		tempColorVec.push_back(tempColor); // push color into temp vec
	}
	typeVec.push_back(tempTypeVec); // push temp vec into vec
	colorVec.push_back(tempColorVec); // """"
	tempTypeVec.clear(); // clear the temp vec so you can push next row into
	tempColorVec.clear(); // """"
  }

  inFile.close();



} // end readfiles
bool Board::quit(){

  return window.quitEvent();

}

#endif

