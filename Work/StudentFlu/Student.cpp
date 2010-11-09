//
//  Implementation file for Student class
//
#include <cmath>
#include <iostream>

#include "Student.h"

using namespace std;

//  Student ctor implementation
Student::Student( int contagious_countdown )
{
    status = 'U';
    status_hours = contagious_countdown;
}

//  nextHour function, advances status hours and status
bool Student::nextHour( )
{
    if( status == 'C' ) {
        return false;
    } else {
        --status_hours;
        if( status_hours == 1 ) {
            if( status == 'U' ) {
                status = 'I';
                status_hours = 52;
            } else if( status == 'I' ) {
                status = 'S';
                status_hours = 24;
            } else if( status == 'S' ) {
                status = 'H';
                status_hours = 48;
            } else {
                status = 'C';
                status_hours = 0;
            }
        }
        return true;
    }
}

//  catchFlu function, handles the chances a 'U' gets the flu
bool Student::catchFlu( )
{
    /*  Variables  */
    const int RESOLUTION = 10000;
    const int INFECTIOUS_HOURS = 52;
    
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

ostream& Student::output( ostream& os ) const
{
    os << status_hours << status << endl;
    return os;
}
//  status accessor function
char Student::getStatus( ) const 
{
    return status;
}

// status_houts accessor function
int Student::getStatus_Hours(  ) const 
{
    return status_hours;
}
