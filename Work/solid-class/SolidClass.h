//
//  SolidClass Header File
//
#pragma once

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class SolidClass {
public:
    /*  Class Type Declaration  */
    SolidClass( int height, int sideLength );
    /*  Functions  */
    // Voluem
    double volume( );
    // Surface Area
    double surfaceArea( );
private:
    /*  Data Members  */
    double height;
    double sideLength;
};
