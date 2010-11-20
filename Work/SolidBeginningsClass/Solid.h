//
//  Solid class Header File
//
#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

class Solid {
public:
/*  Class Type Declaration  */
	Solid(  );
    Solid( int height, int sideLength );
/*  Friend Prototypes  */
    // Subract Solids
	friend Solid operator-( const Solid& lhs, const Solid& rhs );
    // Scale
	friend Solid operator*( const double lhs, const Solid& rhs );
	friend Solid operator*( const Solid& lhs, const double rhs );
    // Check if one solid is <= another
	friend bool operator<=( const Solid& lhs, const Solid& rhs );
/*  Functions  */
    // Volume
    double volume( ) const;
    // Surface Area
    double surfaceArea( ) const;
    // height getter
    double getHeight() const;
    // sideLength getter
    double getSideLength() const;
private:
/*  Data Members  */
    double height;
    double sideLength;
};
