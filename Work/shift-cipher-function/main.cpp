//
//  A program to shift a message a given amount, encoding or decoding it
//
#include "shift-cipher-function.h"

int main()
{
    /*  Declare/Identify Variables  */
    int shift;
    string text;
    
    /*  Ask for final value  */
    cout << "-- Shift Cipher --" << endl << endl;
    cout << "Enter a value by which to shift the characters: " << flush;
    cin >> shift; 
    cout << endl;
    
    /*  Check if file exists and open it  */
    ifstream inFile( "INPUT" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }
    ofstream outFile( "OUTPUT" );
    if( !outFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }
    
    /*  Store file into string  */
    if( !getline( inFile, text, char(0) )) {
        // Failure!
        exit(1);
    }

    /*  Function to shift the text  */
    shiftCipher(text, shift);

    /*  Write output to file  */
    outFile << text;

    /*  Close Files  */
    inFile.close();
    outFile.close();

    /*  Concluding Text  */
    cout << endl << endl;
    cout << "Your shifted message is now stored in a file called 'OUTPUT' in the same directory as this program.";
    cout << endl << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}
