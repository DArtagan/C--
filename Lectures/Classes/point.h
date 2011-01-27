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
	
	// reflection through origin 
	// returns a NEW point object
	point reflect() const;

	// Simple operations for points --
	// Each returns a NEW point object
	point add( const point& p ) const;	
	point negate( ) const;	
	point scale( double factor ) const;
	double length( ) const;	

	// Are two points within epsilon of each
	// other?
	static const int EPSILON_POWER = -6;
	bool equal( const point& p ) const;

	// read value from the input stream --
	// returns a reference to the istream argument provided
	istream& input( istream& is );
	// print myself to the output stream
	// returns a reference to the ostream argument provided
	ostream& output( ostream& os ) const;
private:
	// helper functions
	void init_values( double x );
	void init_values( const double xi[], const int num );
	// data members
	string name;
	double coords[COORDS];
};
