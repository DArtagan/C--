
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "point.h"
using namespace std;

int main( )
{
	const int N = 50000;
	// each point initialized with default ctor as origin
	point path[N];  

	ifstream infile( "point3dpath.dat" );
	if( !infile ) {
		cout << "Error opening 'point3dpath.dat'" << endl;
		exit(1);
	}

	// ignore first line
	string junk;
	getline( infile, junk, '\n' );	

	// read at most N points or until error 
	int n(0);
	while( n<N && path[n].input( infile ) ) {
		n++;
	}
	infile.close();

	// calculate the perimeter of the path, and find
	// the path vertex farthest from the origin
	double perimeter(0), maxdist(-1);  // gauranteed all lengths >-1
	string maxname( "" );
	for( int i=0; i<n; i++ ) {
		/***
		 * add the distance between this point and 
		 * its previous neighbor to the perimeter
		 */
		int prevertex = (i+n-1)%n;
		perimeter += path[i].add( path[prevertex].negate() ).length();
		//                        ^^^^^^^^^^^^^^^^^^^^^^^^
		//                                   -v_{i-1}
		//           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		//                          v_i - v_{i-1}
		//           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		//                          | v_i - v_{i-1} |

		/***
		 * look for the vertex farthest from the origin (length)
		 */
		double l = path[i].length();
		if( l > maxdist ) {
			maxdist = l;
			maxname = path[i].getName();
		}
	}

	cout << "The " << n << " point path is " << 
			perimeter << " units around," << endl;
	cout << "and its point named " << maxname << 
			" is the farthest from the origin (" 
			<< maxdist << " units)." << endl; 

	return 0;
}
