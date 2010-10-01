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
    const int NROWS(10);
    const int NCOLS(7);
    double powerarray[NROWS][NCOLS] = {};
    double test;
    int counter(0);
    double maxpower;
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
    
    //while(inFile >> test) {
    //    cout << test;
    //}
    
    /*  Count data points  */
    while(inFile >> test) {
        counter++;
    }
    
    /*  Store data into array  */
    for( int i(0); i<NROWS; i++ ) {
        for( int j(0); j<NCOL; j++ ) {
            if( !( inFile >> powerarray[i][j] ) ) {
                cout << "The data file ran into a read error!";
                break; // read error
            }
            if(  powerarray[i][j] > maxpower ) {
                maxpower = powerarray[i][j];
            }
        }
    }
    /* The program will no

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
