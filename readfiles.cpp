#include <fstream> // include fstream to read in files
#include <cstring> // needed to use file.open
#include <vector> // to store types and colors in 
#include <iostream>
#include <string> // to store filename 
using namespace std; 

int main() {

 /// open file
  ifstream inFile;
  string filename = "levels/level1.txt";
  inFile.open(filename.c_str());

  // read in file
  char tempType; // temp char to store type being read in 
  int tempColor; // temp int to store color code being read in
  vector<char> tempTypeVec; // temp vec to store row of types
  vector<int> tempColorVec; // temp vec to store row of color codes
  vector< vector <char> > typeVec; // vec to store board types
  vector< vector <int> > colorVec; // vec to store board colors 
  if(!inFile) cout << "inFile";
  while(!inFile.eof()){ //while the file in not at the end
	for(int i = 0; i < 12 ; i++){ // go through files, 12 bricks per row
		inFile >> tempType >> tempColor; // take in the type and color of each element
		tempTypeVec.push_back(tempType); // push type into temp vec
		tempColorVec.push_back(tempColor); // push color into temp vec
	}
	typeVec.push_back(tempTypeVec); // push temp vec into vec
	colorVec.push_back(tempColorVec); // """"
	tempTypeVec.clear(); // clear the temp vec so you can push next row into
	tempColorVec.clear(); // """"
  }
  /*for(int n = 0; n<12; n++){		// setting type and color... uncommment this when made a func
        for(int k = 1; k <36; k++){
        	SetType(n,k,typeVec[k][n],col);
        }
  }*/
  inFile.close();

 


return 0;

}


