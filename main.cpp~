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
    //---------movement variables|
    int xfactor = 1;			//determines how the position of the ball changes if there is a hit
    int yfactor = 1;			// "
    int xvelocity = 2; 
    int yvelocity  = 2; 
    //---------------------------|
    
    //Initiate variables---------|
    int hit = 0;			//nothing is hit at the beginning 
    Board Game;
    //Game.DisplayBoard(); 
    char type; 
    int shoot = 0; 
    int fallthrough = 0; 		// ball should continue 
    int startpadtimer = 0; 		// start 10 second counter 
    int keepgoing = 0; 			// keep counting 10 seconds for the pad to change back to normal
    int padtimer = 0; 
    int Ondefault = 0; 
    int donext = 0; 
    //---------------------------|
    int x =1; 
    bool Quit = false; // loop flag
    
    
    
    
    while( !Quit ){
        
        for(i = 0; i<4; i++){                    			// all eight positions around the ball going clockwise
            checkxpos = xposofball + radiusofball*cos(i*M_PI/2);
            checkypos = yposofball +radiusofball*sin(i*M_PI/2);
            type = Game.GetType(checkxpos,checkypos); 
            if(type != 'e'){ 
                hit = 1;
		face = i+1;
                break;
            } 
            else
            	hit = 0;    
        }
        if(type == 'i'){
        	fallthrough = 1; 
        	//x = 0; 
        	if(keepgoing == 1)
        		Ondefault = 0; 
        	else
        		Ondefault = 1; 
        	if(Game.Paddlecheck(xposofball,Ondefault)==1){
        		fallthrough = 0;
        		cout << "BOUNCEYA"<< endl;  
       		}
        }   
       
        //change x and y velocity factors ----------|
        if((hit == 1) &&(fallthrough !=1)){
            switch(face){
                case 1:
                    xfactor = -1;
                    //cout << "case 1";
                    break;
                case 2:
                    yfactor = -1;
                    //cout << "case 2";
                    break;
                case 3:
                    xfactor = 1;
                   // cout << "case 3";
                    break;
                case 4:
                    yfactor = 1;
                    break;
            }
        }
        //------------------------------------------|
        
     	if(hit == 1){
     		donext = Game.doHit(checkxpos,checkypos); 
     		
		if(donext == 1) 			//if gun was hit 
			shoot = 1; 
		if(donext == 2){ 			
			startpadtimer = 1;
		}
        }
        
        if(shoot ==1){
        // and space bar is hit, start timer 
        // allow shooting
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
        
        startpadtimer = 0; 
        shoot = 0; 							//reset variable; 
        fallthrough = 0; 
 
   
        //Updating window//-------------------------|
        Game.DrawOnWindow(xposofball,yposofball,shoot); 
        Quit = Game.quit();
        //------------------------------------------|
        
        //update position of ball-------------------|
        xposofball = xposofball+ xfactor*xvelocity; 
        yposofball = yposofball +yfactor*yvelocity;
        //------------------------------------------|
        
        
        
        
      
        
        
    
    }
    
      Game.EndGame(); 

}

