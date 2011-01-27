#include <cstdlib>
#include <iostream>
#include <string>

#include "point.h"
using namespace std;

point askUser( const string& name )
{
	point t;
	cout << "Enter point " << name << " ( Name < x y z >): " << flush;
	if( !t.input( cin )) {
		cout << "Error reading a point!" << endl;
		exit(1);
	}
	if( t.getName() != name ) {
		cout << "Changing name from " << t.getName() << " to " << name << endl;
		t.setName( name );
	}
	return t;
}

int main( )
{
	point a;
	point b;
	point c;

	cout << "point a is: " ;
	a.output( cout ) << endl;

	b = askUser( "B" );
	c = askUser( "C" );

	point breflected = b.reflect();
	cout << "The reflection of b: " ;
	breflected.output( cout ) << endl;

	point sum = c.add(b);
	point reflected_sum = c.reflect().add( breflected );
	cout << "sums: " << endl;
	cout << "\t";
	sum.output( cout ) << endl;;
	cout << "\t";
	reflected_sum.output( cout ) << endl;;

	if( sum.equal( reflected_sum ) ) {
		cout << "These are the same location to within " <<
				"1E" << point::EPSILON_POWER << endl;
	} else if( sum.reflect().equal( reflected_sum ) ) {
		cout << "These locations are reflections of " << 
			"each other." << endl;
	} else {
		cout << "These locations differ!" << endl;
	}

	return 0;
}
