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
    Student( int height, int sideLength );
    /*  Functions  */
    bool nextHour( );
    bool catchFlu( );
    ostream& output( ostream& outputf ) const;
private:
    /*  Data Members  */
    int contagious_countdown;
    char status;
    int status_hours;
    //char statusSymbols [5] = {'U', 'I', 'S', 'H', 'C'};
    int RESOLUTION(10000);
    int INFECTIOUS_HOURS(6 * 24);
};
