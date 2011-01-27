/***
 * Implementation for point
 */

#include <cmath>
#include "point-class-operators.h"
#include "string_substitute.h"
using namespace std;

// origin maker
point::point ( )   
{
	init_values( 0 );
	name = "origin";
}

point::point ( const string& theName )   
{
	name = string_substitute(theName, " \n\t", '_');
	init_values( 0 );
}

// arbitrary point maker
point::point( const string& theName, 
		const double xi[], const int num )
{
	name = string_substitute(theName, " \n\t", '_');
	init_values( xi, num );
}

// accessor functions
void point::setName( const string& newname )
{
	name = string_substitute(newname, " \n\t", '_');
}

string point::getName( ) const
{
	return name;
}

void point::setCoord( int coord, double newvalue )
{
	// be sure to stay within array size with % COORDS
	coords[coord%COORDS] = newvalue;	
}

double point::getCoord( int coord ) const
{
	// be sure to stay within array size with % COORDS
	return coords[coord%COORDS];
}

double point::length( ) const
{
	// Pythagoras would be proud
	double sqsum = 0;
	for( int i=0; i<COORDS; i++ ) {
		// square and add
		sqsum += coords[i] * coords[i];
	}
	return sqrt( sqsum );
}

// returns a new object
point operator-( const point& lhs, const point& rhs )
{
	return lhs + -1.0*rhs;  // adding a negative is subtraction
}

// operation + returns a new point object
point operator+( const point& lhs, const point& rhs )
{
	// create a point with appropriate name, and calculate
	// the coords --- default ctor is used so NO PARENS!
	point sum( lhs.name + " + " + rhs.name );
	for( int i=0; i<point::COORDS; i++ ) {
		sum.coords[i] = lhs.coords[i] + rhs.coords[i];
	}

	return sum;
}

// same as scaling
point operator*( double factor, const point& rhs )
{
	// create a point with an appropriate name
	// and calculate the new coords
	point scaled;
	if( abs(factor) > 1 ) {
		scaled.name = string( "bigger " + rhs.name );
	} else if( abs(factor) < 1 ) {
		scaled.name = string( "smaller" + rhs.name );
	} else {
		// silliness -- its the same point!
		scaled.name = "twin " + rhs.name;
	}
	
	// now scale
	for( int i=0; i<point::COORDS; i++ ) {
		scaled.coords[i] = factor*rhs.coords[i];
	}

	return scaled;
}

point operator*( const point& lhs, double rhs )
{
	// scaling a point is a communitive operation, so we flip
	// the argument order and call the *other* operator*.
	return rhs*lhs;
}



bool operator>( const point& lhs, const point& rhs )
{
	// the point farthest from the origin is the greater
	return lhs.length() > rhs.length();
}


// Are two points within epsilon of each
// other?
bool operator==( const point& lhs, const point& rhs )
{
	// oh my, its just the length of the difference
	return (lhs-rhs).length() < pow(10,point::EPSILON_POWER);
}

// read value from the input stream --
// returns a reference to the istream argument provided
istream& operator>>( istream& is, point& rhs )
{
	// We must be careful here, we don't require
	// that a point have a non-empty name!
	string n;
	double newvalues[point::COORDS];
	char closeb;
	// is >> ws skips all whitespace before getline begins,
	// very handy
	if( !getline( is >> ws, n, point::OPENTUPLE ) ) {
		// strange input failure (perhaps end of file?)
		return is;
	}
	if( !n.length() ) {
		// even unnamed points would have whitespace...
		// this must be an error
		is.setstate( ios::failbit );
		return is;
	}
	// trim out the whitespace before <
	n = n.substr(0,n.length()-1);
	// make sure whitespace is not in name
	n = string_substitute(n, " \n\t", '_');

	/***
	 * Simplification: we don't make sure the brace match
	 * the compiled version constant.
	 */
	for( int i=0; i<point::COORDS; i++ ) {
		is >> newvalues[i];
	}
	// now check for parse error or different braces
	if( !( is >> closeb ) || closeb != point::CLOSETUPLE ) { 
		is.setstate( ios::failbit );
		return is;
	}

	// OK, copy coords
	rhs.init_values( newvalues, point::COORDS );
	// and save the name
	rhs.name = n;

	// all done, whew.
	return is;
}

// print myself to the output stream
// returns a reference to the ostream argument provided
ostream& operator<<( ostream& os, const point& rhs )
{
	// prints Blah blah blah < X Y Z >
	os << rhs.name << " " <<  point::OPENTUPLE;
	for( int i=0; i<point::COORDS; i++ ) {
		os << " " << rhs.coords[i];
	}
	os << " " << point::CLOSETUPLE;
	return os;
}

// helper -- init by array
void point::init_values( const double xi[], const int num )
{
	// either num or COORDS will stop the loop
	for( int i=0; i<num && i<COORDS; i++ ) {
		coords[i] = xi[i];
	}
}

// helper -- init by valuevaluevaluevalue
void point::init_values( double x )
{
	// either num or COORDS will stop the loop
	for( int i=0; i<COORDS; i++ ) {
		coords[i] = x;
	}
}

