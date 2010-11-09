//
//  Student class header file
//
#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

class Student {
public:
/*  Class Type Declaration  */
    Student( int contagious_countdown );
/*  Functions  */
    //  Advances status_hours and status
    bool nextHour( );
    //  Handles the possibility of a 'U' becoming an 'I'
    bool catchFlu( );
    ostream& output( ostream& outputf ) const;
    //  accessor function for status
    char getStatus( ) const;
    //  accessor function for status
    int getStatus_Hours(  ) const;
private:
/*  Data Members  */
    char status;
    int status_hours;
};
