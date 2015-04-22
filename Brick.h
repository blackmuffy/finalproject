/*Header and implemenation of Brick class
specifies the type of brick that files each grid space*/ 

/* TYPE LIST:
	'a' --> normal brick
	'e' --> empty space 	
	'w' --> wall - not a brick type but this is returned if the ball goes out of bounds the same way the other types might be returned
	'h' --> hard brick, takes 2 times to kill 
	'i' --> invisible solid row that does not change for the row that contains the paddle 
	's' --> solid bricks never get destroyed
	'x' --> delete all bricks of most popular color; 
*/

#ifndef BRICK_H
#define BRICK_H

#include<iostream>

class Brick{
	
	public:
		Brick();		// constructor
		void setType(char);  	// set type of space
		char getType();		// return type of spce
		int getColor(); 
		void setColor(int); 
		
	private:
		char type; 		//specify the type of brick that fills the board, i.e. brick, empty, etc. 
		int color; 		// value from 0-4 
};
void Brick::setColor(int x){
	color = x; 
}

// member function returns the color of the brick 
int Brick::getColor(){
	return color; 
}

// constructor 
Brick::Brick(){
	type = 'e'; // assume the board is filled of empty bricks
	color = 2; 
}

// member function to set the type of brick that fills the space
void Brick::setType(char t){
	type = t;
}

// member function to return the type of brick that fills the space
char Brick::getType(){
	return type;
}

#endif
