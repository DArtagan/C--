//
//  Program to find how many prime numbers there are from 3 to a user defined 'n', and what the largest prime number therein is.
//
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    
    /*  Ask for final value  */
    cout << "--  --" << endl << endl;
    cout << "";
    cout << endl;
    
    /*  Read File and Display Ivalid Characters  */
    ifstream inFile( "INTDATA1" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        exit(1);
    }
    
    int counter(0);
    char data;
    while( inFile >> data ) {
        cout << int( 'data' );
        if((data >= '0' && data <= '9') || data == '-' || data == '+' ) {
            cout << 'data';
        }
        if( !int( 'data' ) ) {
            cout << data;
            counter++;
        }
    }
    /*while ( inFile >> data ) {
        if ( ++counter % 2 ) {
        cout << counter << " " << data
            << endl;
        }
    }*/
    
    cout << "Total " << counter << " data points." << endl;
    
    inFile.close();

    /*  Display Results with Guiding Text  */
    cout << endl;
    cout << "";
    cout << endl << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}
