//
//  Computes the surface area and volume of 
//  a square pyramid does this program
//
#include "mysolid-reference-function.h"

double SurfaceArea(double side, double height, double& Volume)
{	
	/*  Calculations  */
	Volume = pow(side, 2) * height / 3
	//  The equation of the volume of a square pyramid is:
	//  V = l^2 * h / 3
	
	return (pow(side, 2) + side * sqrt((pow(side, 2) + pow((2 * height), 2)), 2))
	//  The equation of the surface area of a square pyramid is: 
	//  S = l^2 + l * sqrt(l^2+(2h)^2)
}