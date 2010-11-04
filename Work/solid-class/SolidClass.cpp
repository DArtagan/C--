//
//  Implementation file for SolidClass
//
#include <cmath>
#include <iostream>

#include "SolidClass.h"

using namespace std;

//  ctor implementation
SolidClass::SolidClass( int theHeight, int theSideLength )
{
    height = theHeight;
    sideLength = theSideLength;
}

//  Function to find the volume
double SolidClass::volume( )
{
    return ( pow(sideLength, 2) * height / 3 );
}

//  Function to find the surface area
double SolidClass::surfaceArea( )
{
    return ( pow(sideLength, 2) + sideLength * sqrt((pow(sideLength, 2) + pow((2 * height), 2))));
}
