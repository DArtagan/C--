//
//  Program to find the surface area and volume
//  of a user defined square bottomed pyramid
//
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

void Reference (double side, double height, double& Volume, double& SurfaceArea);

/*
    In function `int main()';
    Line 30: void value not ignored as it ought to be
    [Build Error] [mysolid-void-function.o] Error 1
    
    Nothing, it was a void function.
    Inside the main function, a void value was called upon when it shouldn't have been, the program couldn't build
    I attempted to store a void value
*/

int main() {
    /*  Declare variables */
    double side;
    double height;
	double Volume;
	double SurfaceArea;
	double x;

	/*  Header and User Inputs  */
	cout << "-- Volume of a Square Pyramid --" << endl << endl;
	cout << "For your pyramid, what is..." << endl;
	cout << "The length of one of the square sides: " << flush;
	cin >> side;
	cout << "The height of the pyramid: " << flush;
	cin >> height;
    cout << endl << endl;
    
    /*  Calculations  */
    Reference(side, height, Volume, SurfaceArea);
	
	/*  Concluding Text, Print the Volume  */
    cout << "Your pyramid of square side length " << side << " and height " << height\
		 << "; has a surface area of " << SurfaceArea << " and volume of " << Volume;
    cout << endl << endl << endl << endl;    
	
    system("PAUSE");
    //  Exit program
}

void Reference(double side, double height, double& Volume, double& SurfaceArea)
{	
	/*  Calculations  */
	Volume = (pow(side, 2) * height / 3);
	//  The equation of the volume of a square pyramid is:
	//  V = l^2 * h / 3
	
	SurfaceArea = (pow(side, 2) + side * sqrt((pow(side, 2) + pow((2 * height), 2))));
	//  The equation of the surface area of a square pyramid is: 
	//  S = l^2 + l * sqrt(l^2+(2h)^2)
}
