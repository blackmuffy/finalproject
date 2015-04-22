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
    int xvelocity = 1; 
    int yvelocity  = 1; 
    
    //---------------------------|
    
    int hit = 0;
    Board tester;
    tester.DisplayBoard(); 
    cout << tester.FindPopular(); 
    exit(1); 
    
    for(int w = 0; w < 310; w++){
        
        for(i = 0; i<4; i++){                    			// all eight positions around the ball going clockwise
            checkxpos = xposofball + radiusofball*cos(i*M_PI/2);
            checkypos = yposofball +radiusofball*sin(i*M_PI/2);
	    //cout << tester.GetType(checkxpos, checkypos);
            if(tester.GetType(checkxpos, checkypos) != 'e'){ 
		//cout << "something was hit ";
                hit = 1;
		face = i+1;
                break;
            } 
            else
            	hit = 0;    
        }
        cout << "face = " << face << " hit = " << hit; 
        if(hit == 1){
            switch(face){
                case 1:
                    xfactor = -1;
                    cout << "case 1";
                    break;
                case 2:
                    yfactor = -1;
                    cout << "case 2";
                    break;
                case 3:
                    xfactor = 1;
                    cout << "case 3";
                    break;
                case 4:
                    yfactor = 1;
                    cout << "case 4";
                    break;
            }
        }
        
        xposofball = xposofball+ xfactor*xvelocity; 
        cout <<  xfactor*xvelocity << " <--- change --->";  
        yposofball = yposofball +yfactor*yvelocity;
        
        cout << w <<  " x = " << xposofball << " y = " << yposofball << endl;
    
    }

}

