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
    string inAdvice;
    string outAdvice;
    int counter(0);

    /*  Open file for reading, check for validity  */
    ifstream inFile( "ADVICE.TXT" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }

    /*  Display Advice  */
    cout << "-- Code-Advice --" << endl << endl;
    while(getline(inFile, inAdvice)) {
        cout << inAdvice << endl;
    }
    cout << endl << endl;

    /*  Close Read File  */
    inFile.close();
    
    /*  Open file for reading, check for validity  */
    ofstream outFile( "ADVICE.TXT" );
    if( !outFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }
    
    /*  Prompt for, and store, advice  */
    cout << "Type your advice for a future generation.  End your message with two blank line." << endl << endl;
        while(counter < 2) {
           getline(cin, outAdvice);
           if( outAdvice == "") {
                counter++;
                outFile << endl;
            } else {
                counter = 0;
            }
           outFile << outAdvice << endl;
        }

    
    /*  Close Write File  */
    outFile.close();

    //  Exit Program
    return 0;
}
