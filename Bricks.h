/*Header and implemenation of brick class*/

#ifndef BRICKS_H
#define BRICKS_H

#include<iostream>

class Bricks{
	
	public:
		Brick();	// constructor
		void setType(char);
		char getType();	
	private:
		char type;
};

Brick::Brick(){
	type = 'e';
}
void Brick::setType(char t){
	type = t;
}

char Brick::getType(){
	return type;
}

#endif
