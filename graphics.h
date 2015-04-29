/*Graphics.h defines the Grphics Class that uses SDL to produce our graphic representation of Brick Breaker*/
/*bascially everything that needs SDL for brick breaker is contained within this class*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>	// use SDL for the graphics!
#include <sstream> 
#include <vector> 
#include <string> 
//#include <SDL_ttf.h> 
//#include <SDL_image.h> 

using namespace std;

//Screen dimension constants
#define SCREEN_WIDTH	600
#define SCREEN_HEIGHT	900

struct bullet {
	int xpos; 
	int ypos; 
	
}; 

class Graphics {

  public:
 
	Graphics();		// constructor
	void endGame();		// to be run at end of game to free media and shut down sdl	
	static SDL_Surface* load(const char* file); 	// static funciton to load surface
	bool draw(SDL_Surface*, SDL_Surface*, int, int); // static function to draw surface on another surface at specified position
	void placeBrick(int xpos, int ypos, char type, int color);	// place the brick of type in position xpos ypos
	void updatebackground();
	void update();
	void drawBall(int, int);		// draws ball given x and y position
	int drawPaddle(int, int);		// draws paddle given size and center position
  	void WaitEvent(int, int, int,int); 
	bool quitEvent();	
	void drawbullet(int,int,int,int); 
	void deletebullet(int);
	void updatebullet(); 
	int getbulletx(int);
	int getbullety(int); 
	int getsizebullets();   
	bool displayHome();		// displays home screen
	void displayLevelScreen(int); 	// displays level # screen (game over is 0)
	int WaitforClick(); 
	void drawscore(int); 
	
  	
  private:  

	SDL_Window *window = NULL; // the window we'll be rendering to 
	SDL_Surface *display = NULL; // the surface contained by the window
	SDL_Surface *background; //the background image for the screen surface	
	int mouseX; 
	int mouseY; 
	SDL_Event e; 	// event to close window
	vector <bullet> bullets; 
	/*SDL_Renderer* renderer
	int screenWidth, screenHeight; 
	SDL_Rect display Rect; 
	SDL_Texture *background; 
	SDL_Rect rectBackground;  
	TTF_Font *font; 
	SDL_Surface *message; 
	SDL_Texture *text; 
	SDL_Rect textRect; 
	SDL_Color textColor; 
	string data; 
	bool typing; 
	*/
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
			//SDL_Delay(1000); //delay nine seconds
		}
	}
}
int Graphics::WaitforClick(){
	SDL_Event event; 
	SDL_WaitEvent(&event);
	switch(event.type){
		case SDL_MOUSEBUTTONDOWN: 
			return 1;  
	}
	return 0; 
}
void Graphics::WaitEvent(int shoot, int xpos, int ypos, int paddlelength){
	SDL_Event event; 
	SDL_WaitEventTimeout(&event,0); 
	switch (event.type){
		case SDL_MOUSEMOTION:
			 mouseX = event.motion.x;
			 /*if( mouseX < paddlelength/2) mouseX = paddlelength/2;
			 if( mouseX > 600-paddlelength/2) mouseX = 600-paddlelength/2;*/
			 mouseY = event.motion.y; 
			 break; 
		case SDL_KEYDOWN:
			if(shoot == 1){
				string key = SDL_GetKeyName(event.key.keysym.sym); 
				if(key == "Space"){
					bullet A; 
					A.xpos = mouseX-paddlelength/2; 
					A.ypos = 820; 
					bullet B; 
					B.xpos = mouseX+paddlelength/2; 
					B.ypos = 820; 
					bullets.push_back(A);
					bullets.push_back(B); 
				}
			}
				
			break; 
	}
}
void Graphics::drawscore(int score){
	
	/*gfont = TTF_OpenFont("bricks/bebas.ttf",30); 
	if( gFont == NULL)
	{
		printf("failed to load font"); 
	
	}
	else 
	{	SDL_Color textColor = {0,0,0}; 
		if(!gTextTexture.loadFromRenderedText("hello",textcolor); 
	}
	*/

}
void Graphics::updatebullet(){
	int i; 
	for(i = 0; i<bullets.size(); i++){	
		bullets[i].ypos = bullets[i].ypos-2;
	}
}

int Graphics::getbulletx(int i){
	return(bullets[i].xpos); 
}
int Graphics::getbullety(int i){
	return(bullets[i].ypos); 
}
int Graphics::getsizebullets(){
	return(bullets.size()); 
}

void Graphics::deletebullet(int i){
	bullets.erase(bullets.begin()+i); 
}

void Graphics::drawbullet
(int xpos, int ypos,int shoot,int paddlelength){
	WaitEvent(shoot,xpos,ypos,paddlelength);
	int i; 
	SDL_Surface* bullet = load("bricks/bullet.bmp"); 
	SDL_Rect destRect;
	for(i = 0; i<bullets.size(); i++){
		destRect.x = bullets[i].xpos; 
		destRect.y = bullets[i].ypos;
		SDL_BlitSurface(bullet,NULL,display,&destRect);
	}
}
void Graphics::drawBall(int xpos, int ypos){
	SDL_Surface* ball = load("bricks/ball3.bmp"); 
	SDL_Rect destRect;
	destRect.x = xpos-8; 
	destRect.y = ypos-8;
	destRect.h = 16; 
	destRect.w = 16; 
	SDL_BlitSurface(ball,NULL,display,&destRect);

}
int Graphics::drawPaddle(int xpos,int size){
	int centeralign; 
	if(size == 1)
		centeralign = 20; 
	if(size == 2)
		centeralign = 30; 
	if(size ==3)
		centeralign = 40; 
		
	SDL_Surface* paddleS = load("bricks/padS.bmp"); 
	SDL_Surface* paddleM = load("bricks/padM.bmp"); 
	SDL_Surface* paddleL = load("bricks/padL.bmp"); 
	
	SDL_Rect destRect;
	destRect.x = mouseX-centeralign; 	
	destRect.y = 827; 
	
	if(size == 1){
		SDL_BlitSurface(paddleS,NULL,display,&destRect);
	}else if (size == 2){
		SDL_BlitSurface(paddleM,NULL,display,&destRect);
	} 
	else if(size == 3){
		SDL_BlitSurface(paddleL,NULL,display,&destRect);
	}
	return mouseX; 
}


void Graphics::updatebackground(){
  
  SDL_BlitSurface(background, NULL, display, NULL); // blit it to screen
  
} // end background 

void Graphics::update(){

  SDL_UpdateWindowSurface( window ); // update window surface

} // end update

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
		case 'l':
			brick = load("bricks/brickl.bmp");	// load brick l
			break;
		case 'm':
			brick = load("bricks/brickm.bmp");	// load brick m
			break;
		case 'p':
			brick = load("bricks/brickp.bmp");	// load brick p
			break;
	}
	test = draw(display, brick, xpos, ypos);
  	//SDL_UpdateWindowSurface( window ); // update window surface
  	//SDL_Delay(3000); // won't need this later
  	
  }

  SDL_FreeSurface(brick); // free the surface from memory


} // end placeBrick

bool Graphics::quitEvent(){ 
 
  bool quit = false;

  while( SDL_PollEvent( &e) != 0){
	if( e.type == SDL_QUIT){
		quit = true;
	}
  }
  return quit;

}

void Graphics::displayLevelScreen(int level){ // to display level and game over screens for five seconds 
  SDL_Surface *screen = NULL;
  switch(level){
	case(0): //load the game over screen
		screen = SDL_LoadBMP("screens/gameover.bmp"); //load image
		break;
	case(1): //load level 1 screen 
		screen = SDL_LoadBMP("screens/level1.bmp"); //load image
		break;
	case(2): //load level 2 screen 
		screen = SDL_LoadBMP("screens/level2.bmp"); //load image
		break;
	case(3): //load level 3 screen 
		screen = SDL_LoadBMP("screens/level3.bmp"); //load image
		break;
	case(4): //load level 4 screen 
		screen = SDL_LoadBMP("screens/level4.bmp"); //load image
		break;
	case(5): //load level 5 screen 
		screen = SDL_LoadBMP("screens/level5.bmp"); //load image
		break;
	case(6): //load level 6 screen 
		screen = SDL_LoadBMP("screens/level6.bmp"); //load image
		break;
	case(7): //load level 7 screen 
		screen = SDL_LoadBMP("screens/level7.bmp"); //load image
		break;
	case(8): //load level 8 screen 
		screen = SDL_LoadBMP("screens/level8.bmp"); //load image
		break;
	case(9): //load level 9 screen 
		screen = SDL_LoadBMP("screens/level9.bmp"); //load image
		break;
	case(10): //load level 10 screen 
		screen = SDL_LoadBMP("screens/level10.bmp"); //load image
		break;
	case(11): //load you win screen
		screen = SDL_LoadBMP("screens/youwin.bmp"); //load image
  }
	SDL_BlitSurface(screen, NULL, display, NULL); // blit it to screen
	SDL_UpdateWindowSurface( window ); // update window surface
  	SDL_Delay(1000); // display for 1 second 
	SDL_FreeSurface(screen); //free screen surfacce
  
} // end displayLevelScreen

bool Graphics::displayHome(){ // display home page until play selected and allow user to access manual page
	
  SDL_Surface *home = NULL;
  home = SDL_LoadBMP("screens/home.bmp"); // load the home page screen 
  SDL_BlitSurface(home, NULL, display, NULL);
  SDL_UpdateWindowSurface( window );

  SDL_Event m; // mouse event 
  bool play = false; //the user does not want to play yet
  while(!play){ //while the user does not want to play
	//quit = quitEvent();
	if ( quitEvent() ) return true;
	SDL_WaitEvent(&m); // see if there was an event 
	if( m.type == SDL_MOUSEBUTTONDOWN){ //if mouse event happen
		// get mouse position
		int x, y;
		SDL_GetMouseState(&x,&y);
		if (x >= 230 && x <= 380 && y >= 450 && y <= 520){ // if the mouse click happened in the play space
			play = true;	
		} else if( x >= 180 && x <= 430 && y >= 580 && y <= 650){ //if the mouse click happened in the man space
			SDL_Surface *man = NULL;
			man = SDL_LoadBMP("screens/manual.bmp");
			SDL_BlitSurface(man, NULL, display, NULL); // display the manual 
			SDL_UpdateWindowSurface( window );
			SDL_Event o;
			bool exitMan = false;
			while(!exitMan){
				if(SDL_WaitEvent(&o)!=0)
					if(o.type == SDL_MOUSEBUTTONDOWN) exitMan = true;					
				if ( quitEvent() ) return true;
			}
			SDL_BlitSurface(home, NULL, display, NULL);
			SDL_UpdateWindowSurface( window );
			SDL_FreeSurface(man);
		}
	} // end if m->type
  }//end while(!play)

  SDL_FreeSurface(home); //free home surface before returning  
  return false; 

} //end displayHome

#endif

