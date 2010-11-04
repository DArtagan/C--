//
//  The main routine for a program for finding 
//  the surface area and volume of a square-based pyramid
//
#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "SolidClass.h"

using namespace std;

int main()
{
    /*  Declare dimensions */
    SolidClass pyramid1( 100, 5);
    SolidClass pyramid2( 2, 12);
    SolidClass pyramid3( 5, 3);

	/*  Header and User Inputs  */
	cout << "-- Volume of 3 Square-Bottomed Pyramids --" << endl << endl;
    cout << endl;

	/*  Concluding Text, Print the Volumes  */
    cout.setf( ios::left );
    cout.precision(4);
    cout.setf( ios::fixed ); 
    cout << "pyramid1 volume" << setw(9) << right << pyramid1.volume() << " un^3, surface area" << setw(10) << right << pyramid1.surfaceArea() << " un^2" << endl;
    cout << "pyramid2 volume" << setw(9) << right << pyramid2.volume() << " un^3, surface area" << setw(10) << right << pyramid2.surfaceArea() << " un^2" << endl;
    cout << "pyramid3 volume" << setw(9) << right << pyramid3.volume() << " un^3, surface area" << setw(10) << right << pyramid3.surfaceArea() << " un^2" << endl;
	cout << endl << endl << endl;
	
    system("PAUSE");
    //  Exit program.
    return 0;
}
