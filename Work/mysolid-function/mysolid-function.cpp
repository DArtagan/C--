//
//  Compute the volume of an ellipsoid does this program
//
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

double volume( double length, double width, double height)
{
	/*  Variables  */
	const double pi = acos(-1);
	const double ratio = 4.0 / 3;
	
	/*  Calculations  */
	return ratio * pi * ( length / 2 * width / 2 * height / 2);
	//  The equation of an ellipsoid is: V = 4/3*pi*(length*width*height)/2
}

int main()
{
    /*  Declare dimensions */
    double length;
    double width;
    double height;

	/*  Header and User Inputs  */
	cout << "-- Volume of an Ellipsoid --" << endl << endl;
	cout << "For your ellipsoid, what is its..." << endl;
	cout << "Height: " << flush;
	cin >> height;
	cout << "Length: " << flush;
	cin >> length;
	cout << "Width: " << flush;
	cin >> width;
    cout << endl << endl;

	/*  Concluding Text, Print the Volume  */
    cout << "The volume is " <<  volume(length, width, height) << " units cubed." ;
    cout << endl << endl << endl << endl;    
	
    system("PAUSE");
    //  Exit program.
    return 0;
}
