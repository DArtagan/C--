//
//  The main routine for a program for finding 
//  the surface area and volume of a square pyramid
//
#include "mysolid-reference-function.h"

int main()
{
    /*  Declare dimensions */
    double s;
    double h;
	double V;

	/*  Header and User Inputs  */
	cout << "-- Volume of a Square Pyramid --" << endl << endl;
	cout << "For your pyramid, what is..." << endl;
	cout << "The length of one of the square sides: " << flush;
	cin >> s;
	cout << "The height of the pyramid: " << flush;
	cin >> h;
    cout << endl << endl;

	/*  Concluding Text, Print the Volume  */
    cout << "Your pyramid of square side length " << side << " and height " << height\
		 << "; has a volume of << Volume << and 
    cout << endl << endl << endl << endl;    
	
    system("PAUSE");
    //  Exit program.
    return 0;
}