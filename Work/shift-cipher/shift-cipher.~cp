//
//  Program to find and count the number of invalid characters in a file
//
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    int shift;
    char inChar;
    char outChar;
    
    /*  Ask for final value  */
    cout << "-- Shift Cipher --" << endl << endl;
    cout << "Enter a shift value: " << flush;
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
    
    /*  Shift the characters  */
    while( inFile >> inChar ) {
        if( inChar >= '0' && inChar <= '9' ) { // ASCII codes sequential from 0-9 
            // reduce the inChar down to the range 0-9 by subtracting off the ASCII code of zero
            outChar = inChar - '0';
            // Now add the shift AND the value 10, so that even if shift is -9, the result is positive.
            outChar += 10 + shift;
            // Use modulus to make sure the value is between 0 and 9 again
            outChar %= 10;
            // Add the ASCII code of zero back, shoving the result back into the proper region of the ASCII table
            outChar += '0';
            
            // outChar now holds the properly shifted character code, regardless of whether
            // shift is positive, negative, or zero.
        }
        if( inChar >= 'a' && inChar <= 'z' ) { // ASCII codes sequential from 0-9 
            outChar = inChar - 'a';
            outChar += 26 + shift;
            outChar %= 26;
            outChar += 'a';
        }
        if( inChar >= 'A' && inChar <= 'Z' ) { // ASCII codes sequential from 0-9 
            outChar = inChar - 'A';
            outChar += 26 + shift;
            outChar %= 26;
            outChar += 'A';
        }
        outFile << outChar;
    }

    /*  Close Files  */
    inFile.close();
    outFile.close();

    /*  Display Counter Result with Guiding Text  */
    cout << endl << endl;
    cout << "Your shifted message is now stored in a file called OUTPUT in the same directory as this program.";
    cout << endl << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}
