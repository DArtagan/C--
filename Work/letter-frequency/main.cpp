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
    char letter;
    int counter(0);
    
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
            letter >> LetterCounts[counter];
            counter++;
        }
    }
    
	/*  Concluding Text  */
	for(int i(0); i<26; i++) {
        cout << LetterCounts[i];
    }
    cout << endl << endl << endl << endl;    
    
	/*  Close Write File  */
    inFile.close();

	system("PAUSE");
    //  Exit Program
    return 0;
}
