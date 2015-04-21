/*Header and implemenation of Brick class
specifies the type of brick that files each grid space*/ 

/* TYPE LIST:
	'a' --> normal brick
	'e' --> empty space 
*/

#ifndef BRICK_H
#define BRICK_H

#include<iostream>

class Brick{
	
	public:
		Brick();	// constructor
		void setType(char);  // set type of space
		char getType();	// return type of spce
	private:
		char type; //specify the type of brick that fills the board, i.e. brick, empty, etc. 
};

// constructor 
Brick::Brick(){
	type = 'e'; // assume the board is filled of empty bricks
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
