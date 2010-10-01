//
//  Program to find the maximum power output in a set of data, and what day it occured
//
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    const int NROWS(10);
    const int NCOLS(7);
    double powerarray[NROWS][NCOLS] = {};
    double maxpower;
    string WEEKDAYS[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int maxday;
    int maxweek;
    
	/*  Header  */
    cout << "-- Powerplant Average Maximum --" << endl << endl;
    
	/*  Open file for reading, check for validity  */
    ifstream inFile( "power1.dat" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	

    /*  Store data into array  */
    for( int i(0); i<NROWS; i++ ) {
        for( int j(0); j<NCOLS; j++ ) {
            if( !( inFile >> powerarray[i][j] ) ) {
                cout << "The data contains an invalid point.";
                break; // read error
            }
            if(  powerarray[i][j] > maxpower ) {
                maxpower = powerarray[i][j];
            }
        }
    }

	/*  Concluding Text  */
	cout << "There was a maximum power during:";
    for( int i(0);i < NROWS; i++) {
        for( int j(0); j < NCOLS; j++) {
			if ( powerarray[i][j] == maxpower) {
        		maxday = j;
        		maxweek = i+1;
        		cout << endl << WEEKDAYS[maxday] << " of week " << maxweek;
            }
        }
    }
    cout << endl << endl << "The maximum was " << maxpower << "."; 
    cout << endl << endl << endl;
    
	/*  Close Write File  */
    inFile.close();

	system("PAUSE");
    //  Exit Program
    return 0;
}
