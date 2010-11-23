//
//  Implementation file for the Triangle class
//
#include <cstdlib>
#include <iostream>
#include <cmath>

#include "Triangle.h"

using namespace std;

/*  Constructors  */
    // Default ctor
    Triangle::Triangle( )
	{
        name = "no-name";
        for(int i(0); i < SIDES; i++) {
            sides[i] = 0;
        }
	}

/*  Operators  */
    // < Operator
    bool operator<( const Triangle& lhs, const Triangle& rhs )
	{
        if( lhs.Triangle::perimeter() < rhs.Triangle::perimeter() ) {
            return true;
        } else {
            return false;
        }
	}
	// >> Operator
    istream& operator>>( istream& is, Triangle& rhs )
	{
        string tempName;
        double tempSide;
        if( !( is >> tempName )) {
            is.setstate( ios::failbit );
            return is;
        }
        rhs.name = tempName;
        for( int i(0); i < Triangle::SIDES; i++ ) {
            if( !( is >> tempSide )) {
                is.setstate( ios::failbit );
                return is;
            } else {
                rhs.sides[i] = tempSide;
            }
        }
        return is;
	}
	// << Operator
    ostream& operator<<( ostream& os, const Triangle& rhs )
	{
        os << rhs.name;
        for( int i(0); i < Triangle::SIDES; i++) {
            os << " " << rhs.sides[i];
        }
        return os;
	}

/*  Accessor Functions  */
    // Returns the object's name
    string Triangle::getName( ) const
	{
	   return name;
	}
    // Returns the object's length of a specified side
    double Triangle::getSide( int theSide ) const
	{
	   return sides[theSide];
	}
    // Set the name for the object
    void Triangle::setName( string newName )
	{
	   name = newName;
	}
    // Set a specific side of the object
    void Triangle::setSide( double newLength, int theSide )
	{
	   sides[theSide] = newLength;
	}
    // Set each side of the object, as specified
    void Triangle::setSide( double newLengthOne, double newLengthTwo, double newLengthThree )
	{
	   sides[0] = newLengthOne;
	   sides[1] = newLengthTwo;
	   sides[2] = newLengthThree;
	}

/*  Functions  */
    //  Returns the perimeter of the object
    double Triangle::perimeter( ) const
	{
        double perimeter(0);
        for( int i(0); i < SIDES; i++) {  // Perimeter is the sum of all the sides
            perimeter += sides[i];
        }
        return perimeter;
	}
    //  Returns true is all sides are within .001 of each other
    bool Triangle::isEquilateral( ) const
	{
        double EPSILON = .001;
        bool equilateral(true);
        for( int i(1); i < SIDES; i++) {
            equilateral = ( abs( sides[i] - sides[i-1]) <= EPSILON);
            if( equilateral == false ) return false;
        }
        if( !( abs(sides[0] - sides[SIDES - 1] <= EPSILON ))) return false;
        return true;
	}
