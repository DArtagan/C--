//
//  Program to
//
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    const int NROWS(50);
    const int NCOLS(7);
    double powerarray[NROWS][NCOLS] = {};
    double test;
    int counter(0);
    //string WEEKDAYS[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
	/*  Header  */
    cout << "-- Powerplant Average Maximum --" << endl << endl;
    cout << endl;
    
	/*  Open file for reading, check for validity  */
    ifstream inFile( "power1.dat" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	
    
    /*  Count data points  */
    while(inFile >> test) {
        counter++;
    }
    
    /*  Store data into array  */
     for( int i(0);i < (counter - (counter % NCOLS)) / NCOLS; i++) {
        for( int j(0); j < NCOLS && (i * NCOLS + j) < counter; j++) {
            if( inFile >> powerarray[i][j]) break;
        }
    }

	/*  Concluding Text  */
    for( int i(0);i < (counter - (counter % NCOLS)) / NCOLS; i++) {
        for( int j(0); j < NCOLS && (i * NCOLS + j) < counter; j++) {
            cout << powerarray[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;
    
	/*  Close Write File  */
    inFile.close();

	system("PAUSE");
    //  Exit Program
    return 0;
}
