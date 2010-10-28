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
    int data;
    int counter(-1);
    int size;
    int max(0);
    double lower;
    double upper;
    
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
	
	/*  Store data  */
    while(inFile >> data) {
        if(counter == -1) {
            size = data;
        } else {
            storarray[counter] = data;
        }
        counter++;
    }
    
    /*  Calculate Max  */
    for( int i(0); i < size; i++ ) {
        if( storarray[i] > max ) max = storarray[i];
    }
    
    /*  Calculate Thresholds  */
    upper = max * .9;
    lower = max * .1;
    
    /*  Replace data with indicator constants  */
    for( int i(0); i < size; i++ ) {
        if( storarray[i] > upper ) {
            storarray[i] = 2;
        } else if( storarray[i] < lower ) {
            storarray[i] = 0;
        } else {
            storarray[i] = 1;
        }
    }
        
    /*  Concluding Remarks  */
    for(int i(0); i < size; i++) {
        cout << storarray[i];
    }
    cout << endl << endl << endl;

	/*  Close Write File  */
    inFile.close();

    system("PAUSE");
    //  Exit Program
    return 0;
}
