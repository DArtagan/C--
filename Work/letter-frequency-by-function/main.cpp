//
//  The main function for the letter-frequency finding program, handles I/O
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
	int LetterCounts [range] = {};
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
    most = findMost(LetterCounts, range);
	// Second Most
    nextMost = findNextMost(LetterCounts, range);
	//  Least
    least = findLeast(LetterCounts, range);
	//  Second Least
    nextLeast = findNextLeast(LetterCounts, range); 
	
	/*  Concluding Text  */
	cout << setw(12) << right << "Character"\
	<< "  |  " << left << "Frequency" << endl;
    cout << setw(12) << right << char(most + firstLetter) << "  |  " << left << LetterCounts[most] << endl;
    cout << setw(12) << right << char(nextMost + firstLetter) << "  |  " << left << LetterCounts[nextMost] << endl;
    cout << setw(12) << right << char(nextLeast + firstLetter) << "  |  " << left << LetterCounts[nextLeast] << endl;
    cout << setw(12) << right << char(least + firstLetter) << "  |  " << left << LetterCounts[least] << endl;
    cout << endl << endl << endl;
    
	/*  Close Write File  */
    inFile.close();

	system("PAUSE");
    //  Exit Program
    return 0;
}
