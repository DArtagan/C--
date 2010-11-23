//
//  Main routine for a program that tests the Triangle class
//
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Triangle.h"

using namespace std;

int main()
{
    /*  Header  */
    cout << " -- Driver Application for the Triangle class --" << endl << endl << endl;
    
    /*  Test the default ctor  */
    // Call for the default Triangle and display it
    Triangle testTriangle;
    cout << "The default creates a initial triangle: " << testTriangle << endl << endl;

    /*  Test the setters and the perimeter function  */
    // Set new values for that Triangle
    testTriangle.setName( "right-tri" );
    testTriangle.setSide( 3, 4, 5 );
    // Display the new Triangle's data
    cout << "Setting all data members makes triangle one: " << testTriangle << endl;
    // Verify to the user that the sides were set correctly
    cout << "With perimeter " << testTriangle.perimeter() << ", which should equal 12." << endl << endl;
    
    /*  Open file for writing, check for validity  */
    ofstream outFile( "OUTPUT.dat" );
    if( !outFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	

    /*  Check the << operator  */
    // Write the triangle to a file
    outFile << testTriangle << endl;
    // Change the values
    testTriangle.setSide( 6, 0 );
    testTriangle.setSide( 8, 1 );
    testTriangle.setSide( 10, 2 );
    // Write the revised triangle to that file as well
    outFile << testTriangle << endl;

    /*  Close Write File  */
    outFile.close();
    
    /*  Open file for writing, check for validity  */
    ifstream inFile( "OUTPUT.dat" );
    if( !outFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	
    
    /*  Check the >> operator  */
    // Output every triangle in that file
    cout << "Reading all the triangles from a file outputs:" << endl;
    while( inFile >> testTriangle ) {
        cout << testTriangle << endl;
    }
    
    /*  Close Read File  */
    inFile.close();
    
    /*  Footer  */
    cout << endl << endl << endl;
    
    system("PAUSE");
    return 0;
}
