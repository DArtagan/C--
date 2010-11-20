//
//  Implementation file for Solid class
//
#include <cmath>
#include <iostream>

#include "Solid.h"

using namespace std;

/* ctor implementations  */
// Default solid
Solid::Solid(  )
{
    // Default values
	height = 1;
	sideLength = 1;
}
// User specified solid
Solid::Solid( int theHeight, int theSideLength )
{
    if( theHeight > 0 ) { // Insure the height input is valid
		height = theHeight;
	} else {
        height = 1; // If invalid input, set to 1
		cout << "Input Error, the value was set to 1." << endl;  // Notify user
	}
	if( theSideLength > 0 ) { // ensure the sideLength input is valid
	    sideLength = theSideLength;
	} else {
		sideLength = 1;  // If invalid input, set to 1
		cout << "Input Error, the value was set to 1." << endl;  // Notify user
	}
}


/*  Friend/Operator Functions  */
// Subtract two solids
Solid operator-( const Solid& lhs, const Solid& rhs )
{
    Solid small;
    if( lhs.height > rhs.height && lhs.sideLength > rhs.sideLength ) {
        small.height = lhs.height - rhs.height;
        small.sideLength = lhs.sideLength - rhs.sideLength;
    } else if( lhs.height < rhs.height && lhs.sideLength < rhs.sideLength ) {
        small.height = rhs.height - lhs.height;
        small.sideLength = rhs.sideLength - lhs.sideLength;
    } else {
        cout << "These solids are not valid to be subtracted." << endl;
        cout << "You've been given the default solid." << endl;
    }
    return small;
}

// Scale a solid
Solid operator*( const double lhs, const Solid& rhs )
{
    if( lhs > 0 ) {
        Solid scaled;
        scaled.height = lhs * rhs.height;
        scaled.sideLength = lhs * rhs.sideLength;
        return scaled;
    } else {
        cout << endl << "Improper scaler" << endl;
        return rhs;
    }
}

// Scale a solid, alternative order
Solid operator*( const Solid& lhs, const double rhs )
{
    if( rhs > 0 ) {
        Solid scaled;
        scaled.height = rhs * lhs.height;
        scaled.sideLength = rhs * lhs.sideLength;
        return scaled;
    } else {
        cout << endl << "Improper scaler" << endl;
        return lhs;
    }
}

// Compare two solids by volume using <=
bool operator<=( const Solid& lhs, const Solid& rhs )
{
    if( lhs.volume() <= rhs.volume() ) {
        return true;
    } else {
        return false;
    }
}


/*  Functions  */
//  Function to find the volume
double Solid::volume( ) const
{
    return ( pow(sideLength, 2) * height / 3 );
}

//  Function to find the surface area
double Solid::surfaceArea( ) const
{
    return ( pow(sideLength, 2) + sideLength * sqrt((pow(sideLength, 2) + pow((2 * height), 2))));
}

// height getter
double Solid::getHeight() const
{
    return height;
}

// sideLength getter
double Solid::getSideLength() const
{
    return sideLength;
}
