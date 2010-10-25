//
//  The main routine for a program for finding 
//  the surface area and volume of a square pyramid
//
#include "letter-frequency-by-function.h"

int main()
{
    /*  Declare/Identify Variables  */
	//  Constants
	const int firstLetter('a');
    const int lastLetter('z');
    const int range(lastLetter - firstLetter + 1);
	
	//  Variables
	string text;
	int most;
	int nextMost;
	int least;
	int nextLeast;
    
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
    
    /*  Store file into string  */
    if( !getline( inFile, text, char(0) )) {
        // Failure!
        exit(1);
    }
	
    /*  Count the letters in the file  */
    countLetters(text, firstLetter, lastLetter, LetterCounts);
	
	/*  Find Letters  */
	// Most
    findMost(LetterCounts, range, Most);
	// Second Most
    findNextMost(LetterCounts, range, nextMost);
	//  Least
    findLeast(LetterCounts, range, least);
	//  Second Least
    findNextLeast(LetterCounts, range, nextLeast);
	
	/*  Concluding Text  */
	cout << setw(12) << right << "Character"\
	<< "  |  " << left << "Frequency" << endl;
	for(int i(0); i < 4; i++) {
        cout << setw(12) << right << char(most + FIRST_LOWERCASE) << "  |  " << left << LetterResults[most] << endl;
        cout << setw(12) << right << char(nextMost + FIRST_LOWERCASE) << "  |  " << left << LetterResults[nextMost] << endl;
        cout << setw(12) << right << char(nextLeast + FIRST_LOWERCASE) << "  |  " << left << LetterResults[nextLeast] << endl;
        cout << setw(12) << right << char(least + FIRST_LOWERCASE) << "  |  " << left << LetterResults[least] << endl;
    }
    cout << endl << endl << endl;
    
	/*  Close Write File  */
    inFile.close();

	system("PAUSE");
    //  Exit Program
    return 0;
}
