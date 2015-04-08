/* This is a simple SDL program. A .bmp image is displayed inn a window and then a new window displays a .png*/
#include <SDL2/SDL.h> // this is the graphics library
#include <stdio.h>
#include <SDL/SDL_image.h> // image library to load .png files
#include <string>

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

	// do it all again with a png instead
	const int SCREEN_WIDTH_2 = 400;
	const int SCREEN_HEIGHT_2 = 470;
	SDL_Window* window2 = NULL;
	SDL_Surface* surface2 = NULL;
	SDL_Surface* png = NULL;
	SDL_Surface* opSurface = NULL; 	// final img 
	int imgFlags = IMG_INIT_PNG; 

	window2 = SDL_CreateWindow("Lab 7/8: SDL Tutorials 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH_2, SCREEN_HEIGHT_2, SDL_WINDOW_SHOWN); // create window 
	IMG_Init( imgFlags); //initalize PNG loading 
	surface2 = SDL_GetWindowSurface( window2 ); // get window surface
	

	SDL_Surface* loadedSurface = IMG_Load ("penguin.png"); // load png penguin 
	opSurface = SDL_ConvertSurface( loadedSurface, surface2->format, NULL);
	SDL_FreeSurface( loadedSurface );

	SDL_BlitSurface(png, NULL, surface2 , NULL); //apply png to surface
	SDL_UpdateWindowSurface( window2 ); //update surface to window

	SDL_Delay(5000); //delay for 5 seconds 

	// quit and free everything up
	SDL_FreeSurface(png);
	png = NULL;
	SDL_DestroyWindow(window2);
	window  = NULL;
	IMG_Quit();
	SDL_Quit();


	return 0;
}
