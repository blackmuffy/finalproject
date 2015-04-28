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
        
        // most important functions 
        int doHit(int,int); 			// executes a hit 
	void DrawOnWindow(int, int,int); 	// draw everything needed on the screen 
        
	// functions for features     
        void Paddlesettings(int); 		// changes the specs of the paddle
        int Paddlecheck(int,int); 		// checks if ball hit paddle since the paddle is an irregular size
	int WhereOnPaddle(int);			// check where on the paddle the ball hit to calculate rebound angle
        char FindPopular(); 			// returns most popular color
        int sizeofbullets();  			// interfaces with the bullets vector in graphics.h
	int getxbullet(int); 			// get bullets[int].xpos
	int getybullet(int); 			// get bullets[int].ypos
	int erasebullet(int); 			// get rid of bullets[int]
	
	// directly interfaces with Brick.h 
        char GetType(int, int);      
        void SetType(int, int, char,int);
      

	// set up and end functions 
	void readfiles(string);			// to read in level board file
	bool quit();
	void EndGame(); 
	int StartGame(); 
	
	void DisplayBoard();			// unused function to display all the types of each position on the board 
	
	bool DisplayHome();			// display home screen and access man page

 	void LevelUp(int);
	bool LevelComplete();			// is the level complete?
	void resetScore();			// to reset the score when playing a new game 

			
	
	
    private:
        Graphics window; 			// initiate window 
        Brick ** PlayingBoard;			
	int newx; 				// x position relative to board with types 
	int newy; 				// y position relative to board with types 
	
	int paddlelength; 			
	int paddleposition; 			// follows the x pos of the mouse 
	int paddlenumber; 			// 1,2,3 = small medium and large paddles
	
	vector< vector <char> > typeVec; 	// vec to store board types
  	vector< vector <int> > colorVec; 	// vec to store board colors
	int score;				// to keep track of the score
};

Board::Board(){                        				  // constructor
    
     score = 0; // beginning of game and the score is 0
    //MAIN BOARD array creation-----------|
    PlayingBoard = new Brick*[36];
    for(int i = 0; i<36; i++)           			  // make an array that is 36 long
        PlayingBoard[i] = new Brick[12];      			  // make each row be 12 wide
    
    
   //PADDLE-------------------------------|			  // initalizing all entire bottom row to be solid 
   paddlenumber = 2; 						  // initiate normal paddle variables 
   paddleposition = 300-paddlelength/2; 			  // and position 
}

Board::~Board(){						  // deconstructor
    delete[] PlayingBoard;
}
int Board::StartGame(){
	return window.WaitforClick(); 
}
void Board::DrawOnWindow(int xpos, int ypos,int shoot){
	window.updatebackground(); 
	
	for(int i = 0; i<12; i++){
		for(int j = 0; j<36; j++){
			window.placeBrick(i*50,j*25,PlayingBoard[j][i].getType(),PlayingBoard[j][i].getColor()); 
		}
	}
	
	window.drawBall(xpos,ypos);
	paddleposition = window.drawPaddle(paddleposition,paddlenumber);
	window.drawbullet(xpos,ypos,shoot,paddlelength); 
	window.updatebullet(); // move position of bullets 
	window.update(); 
	
}

int Board::doHit(int xpos, int ypos){				  // update the type of the spot once hit in WINDOW COORDINATES
	int set; 
	
	switch(GetType(xpos,ypos)){
		case 'a':					  // single brick type 
			SetType(newx,newy,'e',1);
			//cout << "A" << endl; 
			score += 10;
			return 0;  
			break; 
		case 'h': 					  // double-hit brick type
			SetType(newx,newy,'a',1);
			score += 20;
			//cout << "hit double" << endl; 
			return 0;  
			break; 
		case 'x': 
			//out << "special hit" << endl; 
			//cout << FindPopular()<< endl; 
			SetType(newx,newy,'e',1);
			score += 30;
			set = FindPopular(); 
			for(int i = 0; i<12; i++){
				for(int j = 0; j<36; j++){
					if(PlayingBoard[j][i].getColor() == set){
						SetType(i,j,'e',1); 
					}
						
				}			
			}
			return 0; 
			break; 
		case 'g': 
			SetType(newx,newy,'e',1);
			score += 50;
			return 1; 				  // return 1 for guns should be turned on 
			break;  
		case 'l':
			paddlenumber = 3; 
			score += 40;
			SetType(newx,newy,'e',1);
			return 2; 
			break; 
		case 'm': 
			paddlenumber = 1; 
			score += 40;
			SetType(newx,newy,'e',1);
			return 2; 
			break; 	
		case 'p':
			score += 30;
			SetType(newx,newy,'e',1);
			break;
	}
	return 0; 
}

char Board::FindPopular(){					  // Finds most popular color on board
	int colorcount[] = {0,0,0,0,0};				  //initialize count to 0  
	int mostpopular;  
	int k; 
	
	for(int i = 0; i<12; i++){
		for(int j = 0; j<36; j++){
		
			if(PlayingBoard[j][i].getType()=='a'){
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
			 
		}
	} 
	if(mostpopular == 0)
		return(6); 
	else 
		return(mostpopular); 
}



int Board::Paddlecheck(int xpos,int paddledefault){
	
	
	if(paddledefault == 1){
		paddlenumber = 2; 
	}
	
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

void Board::Paddlesettings(int positionchange){				//if we want 'easy' change would = 20, if we want hard 'change would = -20
		paddleposition = paddleposition + positionchange; 				// given user input to move the paddle;   
}

int Board::erasebullet(int k){
	window.deletebullet(k);
}
int Board::getxbullet(int x){
	return(window.getbulletx(x)); 
}
int Board::getybullet(int y){
	return(window.getbullety(y)); 
}

int Board::sizeofbullets(){
	return(window.getsizebullets()); 
}

char Board::GetType( int Xpos , int Ypos){					// IN WINDOW COORDINATES

    if((Xpos < 0) || (Xpos > 600) || (Ypos < 0)){		// ball hit wall boundaries      
	 return('w');
    }
    if(Ypos > 880)
	return('d');

    newx = (int) Xpos/50;
    newy = (int) Ypos/25;
    return(PlayingBoard[newy][newx].getType());         	 // using the objfill member function to get stored type

}

void Board::SetType(int Xpos, int Ypos, char type, int color){       	 // using the objfill member function to set type in BOARD COORDINATES
            PlayingBoard[Ypos][Xpos].setType(type);         
            PlayingBoard[Ypos][Xpos].setColor(color);  
}



void Board::readfiles(string filename){ // function to read in text files for different levels
  
  ifstream inFile;
  inFile.open(filename.c_str());

  // read in file
  char tempType; // temp char to store type being read in 
  int tempColor; // temp int to store color code being read in
  vector<char> tempTypeVec; // temp vec to store row of types
  vector<int> tempColorVec; // temp vec to store row of color codes
    //if(!inFile) cout << "inFile";
  typeVec.clear(); // clear vecs to read in new board
  colorVec.clear();
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

  cout << "size type" << typeVec.size();
   for(int n = 0; n<12; n++){	// setting type and color with read in data
        for(int k = 0; k <36; k++){
        	SetType(n,k,typeVec[k][n],colorVec[k][n]);
        }
    }

  inFile.close();

} // end readfiles

bool Board::quit(){

  return window.quitEvent();
  
}
void Board::EndGame(){
  window.endGame(); 
  
}

void Board::DisplayBoard(){

    for(int i = 0; i<36; i++){
        for(int j = 0; j< 12; j++){
            cout << PlayingBoard[i][j].getType();        	 // displaying the type
        }
        cout << endl;
    }
}

void Board::LevelUp(int level){
  window.displayLevelScreen(level);
  switch(level){ 
	case (0):
	case (1):
 		readfiles("levels/level1.txt"); 				  // read in level file
		break;
	case (2):
 		readfiles("levels/level2.txt");				  // read in level file
		break;
	case (3):
 		readfiles("levels/level3.txt"); 				  // read in level file
		break;
	case (4):
 		readfiles("levels/level4.txt"); 				  // read in level file
		break;
	case (5):
 		readfiles("levels/level5.txt"); 				  // read in level file
		break;
	case (6):
 		readfiles("levels/level6.txt"); 				  // read in level file
		break;
	case (7):
 		readfiles("levels/level7.txt"); 				  // read in level file
		break;
	case (8):
 		readfiles("levels/level8.txt"); 				  // read in level file
		break;
	case (9):
 		readfiles("levels/level9.txt"); 				  // read in level file
		break;
	case (10):
 		readfiles("levels/level10.txt"); 				  // read in level file
		break;
	case (11):
		break;
  } // end switch 

}

bool Board::DisplayHome(){
  return window.displayHome();
}

bool Board::LevelComplete(){ // function to determine if the level is complete

  int bricks = 0;
  for(int i = 0; i<33; i++){
        for(int j = 0; j< 12; j++){
            if( PlayingBoard[i][j].getType() != 'e') bricks++;        	
        }    
  }	
  if (bricks==0) return true;
  else return false; 


} // end LevelComplete

void Board::resetScore(){ // function to reset score at beginning of new game 
	score = 0;
}// end resetScore

int Board::WhereOnPaddle(int xposofball){

  for(int i = 0; i < 10; i++){
	if(xposofball == padddleposition-paddlelength/2+i) return 0;
	else return 1; 
  }

} // end WhereOnPaddle

#endif

