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
    const int MAX(64);
    int storarray[MAX] = {};
    int size;
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
    
    inFile >> lower;
    while (inFile >> size) {
    if( !(inFile >> size)) {
        cout << "You have bad data.";
    }
        if(size < lower) {
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
    
    cout << lower << " , " << upper << endl;
    cout << realthreshup << " , " << realthreshdown << endl ;
    for(int i=0; i <= 63; i++) {
        cout << storarray[i] << " ";
    }

    /*  Read File into Array  */

	/*  Concluding Text  */
    cout << endl << endl;
    cout << "";
    cout << endl << endl << endl << endl;    
    
	/*  Close Write File  */
    inFile.close();

    system("PAUSE");
    //  Exit Program
    return 0;
}
