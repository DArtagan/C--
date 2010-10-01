//  This program takes a data file from a powerplant that contains
//  the power output sorted into days and weeks, analyzes the data
//  then outputs the maximum wattage and the day/week it occurred.
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
//  Declare stuff
    /* Constants */
    const int NROWS(10);
    const int NCOL(7);
    /* For some reason, putting NCOL as the size broke the code despite the correct array size*/
    const string WEEKDAYS[NROWS]= {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    
    /* Variables */
    double MWatts[NROWS][NCOL];
    double MaxMWatts;
    int MaxWeek;
    int MaxDay;
    
//  Opens the file named power1.dat, checking success/fail
    ifstream inFile( "power1.dat" );
    if ( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }
    cout << "power1.DAT opened!" << endl;
    
//  Begin storing data and analyzing
    /* Stores the data points, 7 points per row (days) and 10 per column (weeks) */
    for( int i(0); i<NROWS; i++ ) {
        for( int j(0); j<NCOL; j++ ) {
            if( !( inFile >> MWatts[i][j] ) ) {
                cout << "The data file ran into a read error!";
                break; // read error
            }
            if(  MWatts[i][j] > MaxMWatts ) {
                MaxMWatts = MWatts[i][j];
            }
        }
    }
    /* The program will now output the maximum wattage detected */
    cout.setf( ios::fixed );
    cout.precision(3);
    cout << "\nThe max wattage was: " << MaxMWatts << " MegaWatts.";    
    
    /* Afterwards, whenever the max wattage occurs, it prints out the day
        and week it occurred */
        for( int i(0); i<NROWS; i++ ) {
                for( int j(0); j<NCOL; j++ ) {
					if ( MWatts[i][j] == MaxMWatts) {
						MaxDay = j;
						MaxWeek = i+1;
						cout << "\nOn " << WEEKDAYS[MaxDay];    
						cout << " during week " << MaxWeek << endl;
            }
        }
    }
    /* Clean up */
    inFile.close();
    
    /* Finish */
    system("PAUSE");
    return 0;
}

