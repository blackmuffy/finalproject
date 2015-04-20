#include <iostream>
#include "SDL/SDL.h"
//#include "SDL_image.h"
using namespace std; 

int main( int argc, char* args[])
{
//	SDL_Surface* hello = NULL; 
//	SDL_Surface* screen = NULL; 

	SDL_Init(SDL_INIT_EVERYTHING); 
	//screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);
	//cout << "Hello World!"; 
	SDL_Surface *IMG_Load(const char *file); 
	SDL_Surface *IMG_ReadXPMFromArray(char **xpm); 
//	hello = SDL_Load("testphoto.h"); 
	SDL_Quit(); 


}
