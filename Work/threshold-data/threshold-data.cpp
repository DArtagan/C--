//
//  Program to convert the values in a file to 0, 1, or 2 depending on given bounds for the threshold filter.
//
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    const int MAX(64);
    int storarray[MAX] = {};
    int size;
    int value;
    int lower;
    int upper(0);
    int counter(0);
    double threshup(.9);
    double threshdown(.1);
    double realthreshup;
    double realthreshdown;
    
	/*  Header  */
    cout << "-- Threshhold Filter --" << endl << endl;
    cout << endl;
    
	/*  Open file for reading, check for validity  */
    ifstream inFile( "DATA" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	
	
	/*  Find size bounds and store data  */
    
    inFile >> size;
    while (inFile >> value) {
        if( !(inFile >> value)) {
            cout << "You have bad data.";
        }
        if(value < lower) {
            lower = size;
        }
        if(size > upper) {
            upper = size;
        }
        storarray[counter] = size;
        counter++;
    }
    
    /*  Calculate the thresholds  */
    realthreshup = ( ( upper - lower ) * threshup + lower ); 
    realthreshdown = ( ( upper - lower ) * threshdown + lower ); 

    for(int i=0; i <= (counter - 1); i++) {
        cout << storarray[i];
    }

    /*  Convert Files  */
    for(int i = 0;i <= counter;i++) {
        if(storarray[i] < realthreshdown) {
            storarray[i] = 0;
        } else if(storarray[i] >= realthreshdown && storarray[i] <= realthreshup) {
            storarray[i] = 1;
        } else {
            storarray[i] = 2;
        }
    }    

	/*  Concluding Text  */
    cout << endl;
    cout << "Your new matrix looks like: " << endl;
    for(int i=0; i <= (counter - 1); i++) {
        cout << storarray[i];
    }
    cout << endl << endl << endl << endl;    
    
	/*  Close Write File  */
    inFile.close();

    system("PAUSE");
    //  Exit Program
    return 0;
}
