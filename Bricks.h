/*Header and implemenation of brick class*/

#ifndef BRICKS_H
#define BRICKS_H

#include<iostream>

class Bricks{
	
	public:
		Bricks();	// constructor
		void setType(char);
		char getType();	
	private:
		char type;
};

Bricks::Bricks(){
	type = 'e';
}
void Bricks::setType(char t){
	type = t;
}

char Bricks::getType(){
	return type;
}

#endif
