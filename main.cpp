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
    int xvelocity = 3; 
    int yvelocity  = 3; 
    //---------------------------|
    
    //Initiate variables---------|
    int hit = 0;			//nothing is hit at the beginning 
    Board Game;
    //Game.DisplayBoard(); 
    char type; 
    int TurnOnGun = 0; 
    int fallthrough = 0; 		// ball should continue 
    
    //---------------------------|
    int x =1; 
    
    
    
    
    
    while(x){
        
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
        	if(Game.Paddlecheck(xposofball)==1){
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
           
                    cout << "case 4";
                    break;
            }
        }
        //------------------------------------------|
        
     	if(hit == 1){
		if((Game.doHit(checkxpos,checkypos) == 1)) 			//if gun was hit 
			TurnOnGun = 1; 
        }
        if(TurnOnGun ==1){
        // and space bar is hit, start timer 
        // allow shooting
        }
        
        TurnOnGun = 0; 							//reset variable; 
        fallthrough = 0; 
        
        
        //cout << w <<  " x = " << xposofball << " y = " << yposofball << endl;
        
        //userinput <> 
        // move pad 
        //**Game.Paddlesettings(int length change, int position change ); 
        //space to shoot up only if something special is hit 
        //
   
        
        Game.DrawOnWindow(xposofball,yposofball); 
        
        
        //update position of ball-------------------|
        xposofball = xposofball+ xfactor*xvelocity; 
        yposofball = yposofball +yfactor*yvelocity;
        //------------------------------------------|
        
        
        
        
      
        
        
    
    }
    
      Game.EndGame(); 

}

