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
    double value;
    int counter(0);
    string WEEKDAYS[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
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
    
    /*  Count number of data points  */
    while(inFile >> value) {
        counter++;
    }
    
    /*  Check inFile size  */
    if (counter > (NROWS) * (NCOLS)) {
        cout << "Your input file is too big." << endl << endl << endl;
        system("PAUSE");
        exit(1);
    }
    
    /*  Store data into array  */
    for( int i(0); i < NROWS; i++) {
        for( int j(0); j < NCOLS; j++) {
            if( !(inFile >> powerarray[i][j])) break;
        }
    }

	/*  Concluding Text  */
    cout << endl << endl;
    for( int i(0); i <= ((counter - (counter % NCOLS)) / NCOLS); i++) {
        for(int j(0); (i < NROWS && j < NCOLS) || (i = NROWS && j < (counter % NCOLS)); j++) {
            cout << powerarray[i][j] << " , ";
        }
        cout << endl;
    }
    cout << endl << endl << endl << endl;    
    
	/*  Close Write File  */
    inFile.close();

	system("PAUSE");
    //  Exit Program
    return 0;
}
