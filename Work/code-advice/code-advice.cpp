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
    string output;
    char advice;
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
    cout << "" << flush;
    while (inFile >> advice) {
        cout << advice;
    }
    cout << endl;
    
    /*  Close Files  */
    inFile.close();

    system("PAUSE");
    //  Exit Program
    return 0;
}
