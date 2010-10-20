//
//  Program to find the surface area and volume
//  of a user defined square bottomed pyramid
//
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

double Reference (double side, double height, double& Volume);

void interface ( void )
{
    /*  Declare variables */
    double side;
    double height;
	double Volume;

	/*  Header and User Inputs  */
	cout << "-- Volume of a Square Pyramid --" << endl << endl;
	cout << "For your pyramid, what is..." << endl;
	cout << "The length of one of the square sides: " << flush;
	cin >> side;
	cout << "The height of the pyramid: " << flush;
	cin >> height;
    cout << endl << endl;
	
	/*  Concluding Text, Print the Volume  */
    cout << "Your pyramid of square side length " << side << " and height " << height\
		 << "; has a surface area of " << Reference(side, height, Volume) << " and volume of " << Volume;
    cout << endl << endl << endl << endl;    
	
    system("PAUSE");
    //  Exit program.
    return ;
}

double Reference(double side, double height, double& Volume)
{	
	/*  Calculations  */
	Volume = pow(side, 2) * height / 3;
	//  The equation of the volume of a square pyramid is:
	//  V = l^2 * h / 3
	
	return (pow(side, 2) + side * sqrt((pow(side, 2) + pow((2 * height), 2))));
	//  The equation of the surface area of a square pyramid is: 
	//  S = l^2 + l * sqrt(l^2+(2h)^2)
}
