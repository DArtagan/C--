//
//  Program to determine the two most 
//  and least frequently lowercase letters 
//  in an input file
//
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    int FIRST_LOWERCASE('a');
    int LAST_LOWERCASE('z');
    const int alphabet(26);
    int LetterCounts[alphabet] = {};
	string LetterArray[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	int LetterResults[2][4] = {};
    char letter;
    int counter(0);
	int range(LAST_LOWERCASE - FIRST_LOWERCASE);
    
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
	for(int i(0); i<26; i++) {
	// Most
		if(LetterCounts[i] > LetterResults[0][0]) {
			LetterResults [0][0] = LetterCounts[i];
			LetterResults[1][0] = i;
		}
	// Second Most
		if(LetterCounts[i] > LetterResults[0][1] && LetterCounts[i] < LetterResults[0][0]) {
			LetterResults [0][1] = LetterCounts[i];
			LetterResults[1][1] = i;
		}
	}
	//  Least
	LetterResults[0][3] = LetterResults[0][0];
	for(int i(0); i<26; i++) {
		if(LetterCounts[i] < LetterResults[0][3]) {
			LetterResults [0][3] = LetterCounts[i];
			LetterResults[1][3] = i;
		}
	}
	//  Second Least
	LetterResults[0][2] = LetterResults[0][0];
	for(int i(0); i<26; i++) {
		if(LetterCounts[i] < LetterResults[0][2] && LetterCounts[i] > LetterResults[0][3]) {
			LetterResults [0][2] = LetterCounts[i];
			LetterResults[1][2] = i;
		}
	}
	
	
	/*  Concluding Text  */
	for(int i(0); i<4; i++) {
        cout << char(LetterResults[1][i] + FIRST_LOWERCASE) << ": " << LetterResults[0][i] << ", ";
    }
    cout << endl << endl << endl << endl;    
    
	/*  Close Write File  */
    inFile.close();

	system("PAUSE");
    //  Exit Program
    return 0;
}
