/***
 * Implementation for point
 */
#include <cmath>
#include "point.h"
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

// reflection through origin 
// returns a NEW point object
point point::reflect() const
{
	double reflected_coords[COORDS];
	for( int i=0; i<COORDS; i++ ) {
		reflected_coords[i] = -coords[i];
	}
	// returns an "anonymous" object
	return point( name + " reflected", 
			reflected_coords, COORDS );
}

// Simple operations for points --
// Each returns a NEW point object
point point::add( const point& p ) const
{
	// create a point with appropriate name, and calculate
	// the coordinate sum
	point sum( name + " + " + p.name );
	for( int i=0; i<COORDS; i++ ) {
		sum.coords[i] = coords[i] + p.coords[i];
	}

	return sum;

}

point point::negate( ) const
{
	point neg = reflect(); // same as reflection
	// but we give it a more mathy name
	// NOTE two anonymous string objects in calculation
	neg.name = string( "-(" ) + name + string( ")" );
	return neg;
}

point point::scale( double factor ) const
{
	// create a point with an appropriate name
	// and calculate the new coords
	point scaled;
	if( abs(factor) > 1 ) {
		scaled.name = string( "bigger " + name );
	} else if( abs(factor) < 1 ) {
		scaled.name = string( "smaller" + name );
	} else {
		// silliness -- its the same point!
		scaled.name = "twin " + name;
	}
	
	// now scale
	for( int i=0; i<COORDS; i++ ) {
		scaled.coords[i] = factor*coords[i];
	}

	return scaled;
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

// Are two points within epsilon of each
// other?
bool point::equal( const point& p ) const
{
	// oh my, its just an equation...
	return add( p.negate() ).length() < pow(10,EPSILON_POWER);
}

// read value from the input stream --
// returns a reference to the istream argument provided
istream& point::input( istream& is )
{
	// We must be careful here, we don't require
	// that a point have a non-empty name!
	string n;
	double newvalues[COORDS];
	char closeb;
	// is >> ws skips all whitespace before getline begins,
	// very handy
	if( !getline( is >> ws, n, OPENTUPLE ) ) {
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
	for( int i=0; i<COORDS; i++ ) {
		is >> newvalues[i];
	}
	// now check for parse error or different braces
	if( !( is >> closeb ) || closeb != CLOSETUPLE ) { 
		is.setstate( ios::failbit );
		return is;
	}

	// OK, copy coords
	init_values( newvalues, point::COORDS );
	// and save the name
	name = n;

	// all done, whew.
	return is;
}

// print myself to the output stream
// returns a reference to the ostream argument provided
ostream& point::output( ostream& os ) const
{
	// prints Blah blah blah < X Y Z >
	os << name << " " << OPENTUPLE;
	for( int i=0; i<COORDS; i++ ) {
		os << " " << coords[i];
	}
	os << " " << CLOSETUPLE;
	return os;
}

// helper -- init by array
void point::init_values( const double xi[], const int num )
{
	// either num or COORDS will stop the loop
	int i=0;
	for( ; i<num && i<COORDS; i++ ) {
		coords[i] = xi[i];
	}
	// fill any unspecified elements with zero
	for( ; i<COORDS; i++ ) coords[i] = 0;
}

// helper -- init by value
void point::init_values( double x )
{
	// either num or COORDS will stop the loop
	for( int i=0; i<COORDS; i++ ) {
		coords[i] = x;
	}
}

