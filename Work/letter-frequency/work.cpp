#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main () {

	char letter('a');

		/*  Open file for reading, check for validity  */
    ofstream inFile( "letters" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	
	
	for(int i(0); i<26; i++) {
		inFile << "\"" << letter << "\"," ;
		letter++;
	}

		/*  Close Write File  */
    inFile.close();
	
}
