// load bmp only 
#include <SDL2/SDL.h> // this is the graphics library
#include <stdio.h>


int main( int argc, char* args[] ){

	//Screen dimension constants
	const int SCREEN_WIDTH = 256;
	const int SCREEN_HEIGHT = 256;


	SDL_Window* window = NULL; // window 
	SDL_Surface* surface = NULL; // surface
	SDL_Surface* image = NULL; //image 
	
	// startup and create window
	window = SDL_CreateWindow("Lab 7/8: SDL Tutorials", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); //create window
	surface = SDL_GetWindowSurface( window ); //get window surface


	// load sample bmp of question mark 
	image = SDL_LoadBMP("sample.bmp"); 

	SDL_BlitSurface(image, NULL, surface, NULL); //apply image
	SDL_UpdateWindowSurface(window); // update window
	SDL_Delay(5000); // delay for 5 seconds
	

	// quit and free everything up
	SDL_FreeSurface(image); // deallocate surface
	image = NULL;
	SDL_DestroyWindow(window); // destroy window 
	window = NULL;
	SDL_Quit(); // quit SDL
}
