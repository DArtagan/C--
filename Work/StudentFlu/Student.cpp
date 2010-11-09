//
//  Implementation file for SolidClass
//
#include <cmath>
#include <iostream>

#include "SolidClass.h"

using namespace std;

//  ctor implementation
Student::Student(  )
{
    status_hours = contagious_countdown;
    status = 'U';
}

//  Functions
bool nextHour( )
{
    if( status == 'c' ) {
        return false;
    } else {
        --status_hours;
    }
    if( status_hours == 1 ) {
        if( status == 'U' ) {
            status = 'I';
            status_hours = ;
        } else if( status == 'I' ) {
            status = 'S';
            status_hours = ;
        } else if( status == 'H' ) {
            status = 'H';
            status_hours = ;
        } else {
            status = 'C'
            status_hours = 0;
        }
        return true;
    }
}

bool catchFlu( )
{
    if( status = 'U' ) {
        if( rand()%RESOLUTION/double(RESOLUTION) < 0.05 ) {
            status_hours = INFECTIOUS_HOURS;
            status = 'I';
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

ostream& output( ostream& outputf ) const
{
    cout << 
    
    return outputf;
}
