/*Graphics.h defines the Grphics Class that uses SDL to produce our graphic representation of Brick Breaker*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>	// use SDL for the graphics
using namespace std;

//Screen dimension constants
#define SCREEN_WIDTH	600
#define SCREEN_HEIGHT	900

class Graphics {

  public:
 
	Graphics();		// constructor
	void endGame();		// to be run at end of game to free media and shut down sdl	
	static SDL_Surface* load(const char* file); 	// static funciton to load surface
	bool draw(SDL_Surface*, SDL_Surface*, int, int); // static function to draw surface on another surface at specified position
	void placeBrick(int xpos, int ypos, char type, int color);	// place the brick of type in position xpos ypos
  private:  

	SDL_Window *window = NULL; // the window we'll be rendering to 
	SDL_Surface *display = NULL; // the surface contained by the window
	SDL_Surface *background; //the background image for the screen surface	


};

// constructor to start up sdl and create window with space background
Graphics::Graphics(){

  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
	//Create window
	window = SDL_CreateWindow( "Brick Breaker", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL ) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		} else {
			display = SDL_GetWindowSurface( window ); //get 
			background = SDL_LoadBMP("deep-space-2.bmp"); //load image
			SDL_BlitSurface(background, NULL, display, NULL); // blit it to screen
			SDL_UpdateWindowSurface( window ); // update window surface
			SDL_Delay( 1000 ); //delay nine seconds
		}
	}
}

// free media and shut down SDL at end of game 
void Graphics::endGame(){

  SDL_FreeSurface( background );
  background = NULL;
  SDL_DestroyWindow( window ); //destroy window
  window = NULL;
  SDL_Quit(); // quit SDL

} // end endGame

// static funcition to load surface
SDL_Surface* Graphics::load(const char* File) {

  SDL_Surface* tempSurf = NULL; // temporary surface
  //SDL_Surface* returnSurf = NULL; // surface to return 

  // load BMP to surface and return NULL if it doen't load correctly
  if( (tempSurf = SDL_LoadBMP(File)) == NULL) return NULL;

  // unsure what to do here... SDL2 got rid of SDL_DisplayFormat... sooo surface free in space 
  /*returnSurf = SDL_DisplayFormat(tempSurf); // formate surface to return
  SDL_FreeSurface(tempSurf); // free temporary surface */
  /*returnSurf = SDL_ConvertSurface( tempSurf, window->format, NULL);
  SDL_FreeSurface(tempSurf);*/

  return tempSurf; // return loaded surface

} // end load


// static function to draw surface to destination surface at xpos, ypos
bool Graphics::draw(SDL_Surface* dest, SDL_Surface* surface, int xpos, int ypos){

  SDL_Rect destRect; // defined rectangle
  destRect.x = xpos; // x positon of obj
  destRect.y = ypos; // y position of obj
  destRect.h = 25; // brick is 25 pix tall
  destRect.w = 50; // brick is 50 pix wide

  SDL_BlitSurface(surface, NULL, dest, &destRect);

} // end draw

void Graphics::placeBrick(int xpos, int ypos, char type, int color){

  SDL_Surface* brick = NULL;
  bool test;

  if(type != 'e'){ // do not need to place any empty bricks 
	
	switch(type){
		case 'a': 
			switch(color){
				case 0:
					brick = load("bricks/bricka0.bmp");	// load brick a color 0
					break;
				case 1:
					brick = load("bricks/bricka1.bmp");	// load brick a color 1
					break;
				case 2:
					brick = load("bricks/bricka2.bmp");	// load brick a color 2
					break;
				case 3:
					brick = load("bricks/bricka3.bmp");	// load brick a color 3
					break;
				case 4:
					brick = load("bricks/bricka4.bmp");	// load brick a color 4
					break;
			}
			break;
		case 'h':
			brick = load("bricks/brickh.bmp");	// load brick h
			break;
		case 'x':
			brick = load("bricks/brickx.bmp");	// load brick x
			break;
		case 's':
			brick = load("bricks/bricks.bmp");	// load brick s
			break;
		case 'g':
			brick = load("bricks/brickg.bmp");	// load brick g
			break;
	}
	test = draw(display, brick, xpos, ypos);
  	SDL_UpdateWindowSurface( window ); // update window surface
  	SDL_Delay(3000); // won't need this later
  	SDL_FreeSurface(brick); // free the surface from memory
  }
} // end placeBrick

#endif

