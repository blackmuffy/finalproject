/*Header and implemenation of ObjFill class
specifies the type of object that filles that space on the board */ 

/* TYPE LIST:
	'a' --> normal brick
	'b' --> normal ball
	'e' --> empty space 
*/

#ifndef OBJFILL_H
#define OBJFILL_H

#include<iostream>

class ObjFill{
	
	public:
		ObjFill();	// constructor
		void setType(char);
		char getType();	
	private:
		char type;
};

// constructor 
ObjFill::ObjFill(){
	type = 'e'; // asuume the board is filled of empty spaces
}

void ObjFill::setType(char t){
	type = t;
}

char ObjFill::getType(){
	return type;
}

#endif
