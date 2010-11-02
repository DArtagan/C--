//
//  The main function for the threshold-finding program
//  This function handles the UI
//
#include "threshold-data-function.h"

int main()
{
    /*  Declare/Identify Variables  */
    const int MAX(64);
    int data[MAX] = {};
    int size;
    double lower(.1);
    double upper(.9);
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
	ofstream outFile( "PROCESSED_DATA" );
    if( !outFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	
	
	
	/*  All the work  */
    // while we can read size datapoints into array from the file
    while( readData( inFile, data, size, MAX ) ) {
        threshold( data, size, upper, lower );
        outputData( outFile, data, size );
    }
    
    /*  Replace data with threshold indicator constants  */
    threshold(data, size, upper, lower);
        
    /*  Concluding Remarks  */
    for(int i(0); i < size; i++) {
        cout << data[i];
    }
    cout << endl << endl << endl;

	/*  Close Write File  */
    inFile.close();

    system("PAUSE");
    //  Exit Program
    return 0;
}
