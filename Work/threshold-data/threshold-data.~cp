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
    int array[64];
    int test(0);
    int size(64);
    
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
	
	/*  Test DATA size  */
	while(inFile >> test) {
        size++;
    }
	if( !(inFile >> size)) {
        cout << "There are too many data files for the array." << endl << endl;
        system("PAUSE");
        exit(1);
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
