//
//  Program to shift the alphanumeric characters in a file and output them to another file, in the style of a shift-cypher
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
    
    /*  Shift the characters  */
    while( inFile >> inChar ) {
        if( inChar >= '0' && inChar <= '9' ) {
            outChar = inChar - '0';
            outChar += 10 + shift;
            outChar %= 10;
            outChar += '0';
        } else if( inChar >= 'a' && inChar <= 'z' ) {
            outChar = inChar - 'a';
            outChar += 26 + shift;
            outChar %= 26;
            outChar += 'a';
        } else if ( inChar >= 'A' && inChar <= 'Z' ) {
            outChar = inChar - 'A';
            outChar += 26 + shift;
            outChar %= 26;
            outChar += 'A';
        } else {
            outChar = inChar;
        }
        outFile << outChar;
    }

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
