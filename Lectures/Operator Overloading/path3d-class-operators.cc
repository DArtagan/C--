
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "point-class-operators.h"
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
	while( n<N && (infile >> path[n]) ) {
		n++;
	}
	infile.close();

	// calculate the perimeter of the path, and find
	// the path vertex farthest from the origin
	double perimeter(0);
	point farthest; // default ctor is at origin
	for( int i=0; i<n; i++ ) {
		/***
		 * add the distance between this point and 
		 * its previous neighbor to the perimeter
		 */
		int prevertex = (i+n-1)%n;
		point i_minus_prev = path[i] - path[prevertex]; 

		perimeter += i_minus_prev.length();

		/***
		 * look for the vertex closest to the origin (length)
		 */
		if( path[i] > farthest ) {
			// a new point farthest from the origin
			farthest = path[i];
		}
	}

	cout << "The " << n << " point path is " << 
			perimeter << " units around," << endl;
	cout << "and its point named " << farthest.getName() << 
			" is the farthest from the origin (" 
			<< farthest.length() << " units)." << endl; 

	return 0;
}
