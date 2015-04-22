//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//Screen dimension constants
#define SCREEN_WIDTH	600
#define SCREEN_HEIGHT	900


int main( int argc, char* args[] ){

	SDL_Window *window = NULL; // the window we'll be rendering to 
	SDL_Surface *surface = NULL; // the surface contained by the window
	SDL_Surface *background = NULL; //the background image for the screen surface	
	SDL_Surface *brick = NULL;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
	//Create window
	window = SDL_CreateWindow( "Brick Breaker", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL ) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		} else {
			surface = SDL_GetWindowSurface( window ); //get window surface
			//Fill the surface white
			//SDL_FillRect( surface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			background = SDL_LoadBMP("deep-space-2.bmp"); //load image
			SDL_BlitSurface(background, NULL, surface, NULL); // blit it to screen
			SDL_UpdateWindowSurface( window ); // update window surface
			SDL_Delay( 2000 ); //delay nine seconds
		}
	}
        
 	// where it should all go
       	SDL_Rect destRect; // defined rectangle
  	destRect.x = 20; // x positon of obj
 	destRect.y = 20; // y position of obj
 	destRect.h = 25; // brick is 25 pix tall
  	destRect.w = 50; // brick is 50 pix wide
    
        brick = SDL_LoadBMP("brick.bmp"); //load image
	SDL_BlitSurface(brick, NULL, background, &destRect);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(9000);


  SDL_DestroyWindow( window ); //destroy window

	SDL_Quit(); // quit SDL

	return 0;
} // end main 
