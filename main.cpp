#include <iostream>
#include "Board.h"
#include <cstdlib>
#include <math.h>

using namespace std;

int main(){
    //relating to the ball-------
    double xposofball = 300;         //center of ball in pixel values
    double yposofball = 880;         // "
    double checkxpos;             // which of the 4 parts of the ball is hit
    double checkypos;             // "
    int xfactor = 1;                 //determines how the position of the ball changes if there is a hit
    int yfactor = -1;                 // "
    int i;                     //which face of the ball was in contact with an object
    int face; 

    int radiusofball = 8;
    //---------------------------
    int hit = 0;
    Board tester;
    
    
    for(int w = 0; w < 310; w++){
        
        for(i = 0; i<4; i++){                    // all eight positions around the ball going clockwise
            checkxpos = xposofball + radiusofball*cos(i*M_PI/2);
            checkypos = yposofball +radiusofball*sin(i*M_PI/2);
	    cout << tester.GetType(checkxpos, checkypos);
            if(tester.GetType(checkxpos, checkypos) != 'e'){ 
		cout << "WALLL";
                hit = 1;
		face = i+1;
                break;
            }    
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
        xposofball = xposofball+ xfactor;  
        yposofball = yposofball +yfactor;
        
        cout << w <<  " x = " << xposofball << " y = " << yposofball << endl;
    
    }

}

