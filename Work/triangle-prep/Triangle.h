//
//  Header file for the Triangle class
//
#pragma once

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Triangle {
public:
/*  Constructors  */
    // Default ctor
    Triangle( );

/*  Constants  */
    static const int SIDES = 3;

/*  Operators  */
    friend bool operator<( const Triangle& lhs, const Triangle& rhs );
    friend istream& operator>>( istream& is, Triangle& rhs );
    friend ostream& operator<<( ostream& os, const Triangle& rhs );

/*  Accessor Functions  */
    // Returns the object's name
    string getName( ) const;
    // Returns the object's length of a specified side
    double getSide( int theSide ) const;
    // Set the name for the object
    void setName( string newName );
    // Set a specific side of the object
    void setSide( double newLength, int theSide );
    // Set each side of the object, as specified
    void setSide( double newLengthOne, double newLengthTwo, double newLengthThree );

/*  Functions  */
    //  Returns the perimeter of the object
    double perimeter( ) const;
    //  Returns true is all sides are within .001 of each other
    bool isEquilateral( ) const;

private:
/*  Data Members  */
    string name;
    double sides[SIDES];
};
