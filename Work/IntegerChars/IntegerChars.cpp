//
//  Program to find and count the number of invalid characters in a file
//
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   
    /*  Heading  */
    cout << "-- Find all the invalid characters in a program --" << endl << endl;
    cout << endl;
    
    /*  Check if file exists and open it  */
    ifstream inFile( "INTDATA" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }
    
    /*  Find all invalid characters  */
    int counter(0);
    char data;
    while( inFile >> data ) {
        if(!((data >= '0' && data <= '9') || data == '-' || data == '+' )) {
            cout << data;
            counter++;
        }
    }
    
    inFile.close();

    /*  Display Counter Result with Guiding Text  */
    cout << endl << endl;
    cout << counter << " invalid characters found." << endl;
    cout << endl << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}
