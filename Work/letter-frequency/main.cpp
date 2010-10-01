//
//  Program to determine the two most 
//  and least frequently lowercase letters 
//  in an input file
//
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    
	/*  Open file for reading, check for validity  */
    ifstream inFile( "" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	
	
	/*  Ask for initial values  */
    cout << "--  --" << endl << endl;
    cout << "" << flush;
    cin >> shift; 
    cout << endl;

	/*  Concluding Text  */
    cout << endl << endl;
    cout << ;
    cout << endl << endl << endl << endl;    
    
	/*  Close Write File  */
    inFile.close();

	system("PAUSE");
    //  Exit Program
    return 0;
}
