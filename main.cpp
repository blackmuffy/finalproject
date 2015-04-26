#include <iostream>
#include "Board.h"
#include <cstdlib>
#include <math.h>

using namespace std;

int main(){
	
    //Ball variables-------------|
    
    int xposofball = 300;		//center of ball in pixel values
    int yposofball = 400;		// "
    int checkxpos;			// which of the 4 parts of the ball is hit
    int checkypos;			// "
    int i;				//which face of the ball was in contact with an object
    int face;				//"
    int radiusofball = 8;
    //movement variables---------|
    int xfactor = 1;			//determines how the position of the ball changes if there is a hit
    int yfactor = 1;			// "
    int xvelocity = 1; 
    int yvelocity  = 1; 
    
    //Initiate variables---------|
    int hit = 0;			//variable turns on when an object(ball or bullet) hits something 
    char type; 				//the type that an object goes through 
    
    //timed features-------------|
   				
    int startpadtimer = 0; 		// when 1 this triggers counter for pad size change 
    int startshoottimer = 0;		// when 1 triggers counter for shooting 
    
    int padtimer = 0; 			// this counter var increments as long as keepgoing is 1 
    int shoottimer = 0; 		// this counter var increments as long as keepshooting is 1 
    
    int keepgoing = 0; 			// keep counting until pad should change back to normal
    int keepshooting = 0;		// keep counting until shooting permission is taken away 
     
    int fallthrough = 0; 		// ball should continue through the bottom invisible row 
    
    int Ondefault = 0; 			// indicating that the paddle should go back to default middle sized paddle since keep going is not 1
    int donext = 0; 			// accepts result of the doHit functio to indicate the start of certain timers (shoot/paddle change) 	
   
    int hitball = 0;  			// hitball = 1 when the ball hits something 
    
    int objectx; 			// recieves the x coordinate that should execute doHit
    int objecty;  			// recieves the y coordinate that should execute doHit
    
    Board Game;
    
    bool Quit = false; 			// loop flag
    
    
    
    //MAIN LOOP-----------------|
    while( !Quit ){
        
        //SEE IF ANY PART OF THE BALL WAS HIT-------|
        for(i = 0; i<4; i++){                    			// all eight positions around the ball going clockwise
            checkxpos = xposofball + radiusofball*cos(i*M_PI/2);
            checkypos = yposofball +radiusofball*sin(i*M_PI/2);
            type = Game.GetType(checkxpos,checkypos); 
            if(type == 'w')
            	Quit = 1; 
          
            if(type != 'e'){ 
                hitball = 1;
		face = i+1;
                break;
            } 
            else
            	hit = 0;    
        }
        if(type == 'i'){
        	fallthrough = 1; 
        	if(keepgoing == 1)
        		Ondefault = 0; 
        	else
        		Ondefault = 1; 
        	if(Game.Paddlecheck(xposofball,Ondefault)==1){
        		fallthrough = 0;
       		}
        }   
       
        //CHANGE VELOCITY FACTORS-------------------|
        if((hitball == 1) &&(fallthrough !=1)){
            switch(face){
                case 1:
                    xfactor = -1;
                    break;
                case 2:
                    yfactor = -1;
                    break;
                case 3:
                    xfactor = 1;
                    break;
                case 4:
                    yfactor = 1;
                    break;
            }
        }
        
        //CHECK IF ANYTHING WAS HIT-----------------|
        for(int k = 0; k<= Game.sizeofbullets(); k++){
        	if(k == Game.sizeofbullets()){
        		if(hitball == 1){
				objectx = checkxpos; 
				objecty = checkypos; 
				hit = 1; 
        		}
        	}
        	else{
        		objectx = Game.getxbullet(k); 
        		objecty = Game.getybullet(k); 
        	}
        	
        	type = Game.GetType(objectx,objecty); 
        	
        	if(type != 'e'){
        		hit = 1;
        		if(k!=Game.sizeofbullets())
        			Game.erasebullet(k);  
        	}
        		
        	if(hit == 1){
	     		donext = Game.doHit(objectx,objecty); 
	     		
			if(donext == 1) 			
				startshoottimer = 1; 
			if(donext == 2){ 			
				startpadtimer = 1;
			}
	
       		}
        
		if((startshoottimer == 1)||(keepshooting ==1)){
	       		shoottimer++; 
	       		keepshooting = 1; 
	       		if(shoottimer == 6000){
	       			keepshooting = 0; 
	       			shoottimer = 0; 
	       		}
        	}
 
	       	if((startpadtimer == 1) || (keepgoing == 1)){
			padtimer++; 
			keepgoing = 1; 
			if(padtimer == 2000){
				keepgoing = 0;
				Game.Paddlecheck(xposofball,1); 
				padtimer = 0; 
			} 
		}
        } 
     	
        //RESET VARIABLES---------------------------|
        startshoottimer = 0; 
        startpadtimer = 0; 							
        fallthrough = 0; 
 
   
        //UPDATE WINDOW-----------------------------|
        Game.DrawOnWindow(xposofball,yposofball,keepshooting); 
        Quit = Game.quit();
        
        
        //UPDATE BALL POSITION----------------------|
        xposofball = xposofball+ xfactor*xvelocity; 
        yposofball = yposofball +yfactor*yvelocity;

    
    }
    
      Game.EndGame(); 

}

