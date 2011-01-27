/**
 * A class representing a n-dimensional point
 */
#pragma once  

#include <iostream>
#include <string>
using namespace std;

/**
 * point interface
 */
class point {
public:
	// compiled as a three dimensional
	// point
	static const int COORDS = 3; 
	// for input and output notation
	static const char OPENTUPLE = '<';
	static const char CLOSETUPLE = '>';
	// default ctor makes "origin"
	point ( );   
	// origin by another name
	point( const string& theName );
	point( const string& theName, 
			const double xi[], const int num );

	// accessor functions
	void setName( const string& newname );
	string getName( ) const;
	void setCoord( int coord, double newvalue );
	double getCoord( int coord ) const;

	// friended global operators.  Note that all arithmetic operators
	// return NEW point objects.
	friend point operator-( const point& lhs, const point& rhs );
	friend point operator+( const point& lhs, const point& rhs );
	friend point operator*( double lhs, const point& rhs );
	friend point operator*( const point& lhs, double rhs );
	// return bools
	friend bool operator>( const point& lhs, const point& rhs );
	static const int EPSILON_POWER = -6;
	friend bool operator==( const point& lhs, const point& rhs );
	// return the streams
	friend istream& operator>>( istream& is, point& rhs );
	friend ostream& operator<<( ostream& os, const point& rhs );
		
	/***
	 * We don't need the notion of reflection or negation, because anyone
	 * using point should understand that a point x's reflection is simply
	 *   -x
	 * or, in C++:
	 *   -1*x
	 */

	// but we still need length
	double length( ) const;	

private:
	// helper functions
	void init_values( double x );
	void init_values( const double xi[], const int num );
	// data members
	string name;
	double coords[COORDS];
};
