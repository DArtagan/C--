//
//  Program to determine the two most 
//  and least frequently used lowercase 
//  letters in an input file
//
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
	//  Constants
	const int FIRST_LOWERCASE('a');
    const int LAST_LOWERCASE('z');
    const int range(LAST_LOWERCASE - FIRST_LOWERCASE + 1);
	
	//  Variables
    int LetterCounts[range] = {}, LetterResults[2][4] = {};
	char letter;
    
	/*  Open file for reading, check for validity  */
    ifstream inFile( "INPUT.TXT" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	
	
	/*  Header  */
    cout << "-- Letter Frequency Counter --" << endl << endl;
    cout << endl;
    
    /*  Store counts in the array  */
    while(inFile >> letter) {
        if(letter >= FIRST_LOWERCASE && letter <= LAST_LOWERCASE) {
			LetterCounts[(letter - 'a')]++;
        }
    }
	
	/*  Find Letters  */
	// Most
	for(int i(0); i<range; i++) {
		if(LetterCounts[i] > LetterResults[0][0]) {
			LetterResults [0][0] = LetterCounts[i];
			LetterResults[1][0] = i;
		}
    }
	// Second Most
	for(int i(0); i<range; i++) {
    	if(LetterCounts[i] > LetterResults[0][1] && LetterCounts[i] % LetterResults[0][0] != 0) {
			LetterResults [0][1] = LetterCounts[i];
			LetterResults[1][1] = i;
		}
	}
	//  Least
	LetterResults[0][3] = LetterResults[0][0];
	for(int i(0); i < range; i++) {
		if(LetterCounts[i] < LetterResults[0][3]) {
			LetterResults [0][3] = LetterCounts[i];
			LetterResults[1][3] = i;
		}
	}
	//  Second Least
	LetterResults[0][2] = LetterResults[0][0];
	for(int i(0); i < range; i++) {
		if(LetterCounts[i] < LetterResults[0][2] && LetterCounts[i] > LetterResults[0][3]) {
			LetterResults [0][2] = LetterCounts[i];
			LetterResults[1][2] = i;
		}
	}
	
	/*  Concluding Text  */
	cout << setw(12) << right << "Character"\
	<< "  |  " << left << "Frequency" << endl;
	for(int i(0); i < 4; i++) {
        cout << setw(12) << right << char(LetterResults[1][i] + FIRST_LOWERCASE)\
		<< "  |  " << left << LetterResults[0][i]\
		<< endl;
    }
    cout << endl << endl << endl;
    
	/*  Close Write File  */
    inFile.close();

	system("PAUSE");
    //  Exit Program
    return 0;
}
