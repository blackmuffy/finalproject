/*Header and implemenation of ObjFill class
specifies the type of object that filles that space on the board */ 

/* TYPE LIST:
	'a' --> normal brick
	'e' --> empty space 
*/

#ifndef BRICKS_H
#define BRICKS_H

#include<iostream>

class ObjFill{
	
	public:
		ObjFill();	// constructor
		void setType(char);  // set type of space
		char getType();	// return type of spce
	private:
		char type; //specify the type of object that fills the board, i.e. brick, ball, empty, etc. 
};

// constructor 
ObjFill::ObjFill(){
	type = 'e'; // assume the board is filled of empty spaces
}

// member function to set the type of object that fills the space
void ObjFill::setType(char t){
	type = t;
}

// member function to return the type of object that fills the space
char ObjFill::getType(){
	return type;
}

#endif
