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
    string ad;
    string output;
    char advice
    char
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

    /*  Open file for writing, check for validity  */
    ofstream outFile( "OUTPUT" );
    if( !outFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }

    /*  Ask for Advice  */
    
    
    /*  Open file  */
    
    ofstream outFile( ADVICE.TXT" );
    if( !outFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }
    
    /*  Shift the characters  */
    while( counter < 2 ) {
        getline(inFile, output, '/n')
        if (output == "") {
            counter++;
    }

    /*  Close File  */
    outFile.close();
    
    /*  Concluding Text  */
    cout << endl << endl;
    cout << "";
    cout << endl << endl << endl << endl;

    system("PAUSE");
    //  Exit Program
    return 0;
}
