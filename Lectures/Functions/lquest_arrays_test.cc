#include <iostream>
#include <cmath>
using namespace std;

/***
 * Calculate an average
 */
double average( const double data[], const int size );

/***
 * returns the greater of two ints
 * (a utility function for locality)
 */
int intmax( int a, int b );

/***
 * Fill nearest and farthest with the offsets of the 
 * data elements that meet the named criteria.
 */
void locality( const int data[], const int size, int value,
		int& near, int& far );

/***
 * Fibonacci
 */
void fibonacci( int fib[], const int size );

/***
 * sine_terms
 */
void sine_terms( double terms[], const int size, double x );

/***
 * sine_sums
 */
double sine_sums( double terms[], const int size, double x, double sums[] );



int main()
{
	const int SIZE(20);
	double avgdata[SIZE] = { 1 };
	for( int j(1); j<=SIZE; j++ ) {
		cout << "The average of 1 and " << j-1 << " zeros is " << average( avgdata, j ) << endl;
	}

	int fterms[SIZE];
	fibonacci( fterms, SIZE );
	cout << "The first " << SIZE << " Fibonacci terms are " ;
	for( int j(0); j<SIZE; j++ ) { cout << fterms[j] << " " ; };
	cout << endl;

	const int TESTLOCATIONS(100);
	int testLocations[TESTLOCATIONS] = { -1, 10000, 4184, 2585, 6 }; 
	for( int c(0); c<TESTLOCATIONS; c++ )
	{
		if( !testLocations[c] ) break; // zero signals end (do you know how the zeros got there?!)
		int near, far;
		locality( fterms, SIZE, testLocations[c], near, far );
		cout << "Fib term " << fterms[near] << " is closest to " << testLocations[c] << endl;
		cout << "Fib term " << fterms[far] << " is farthest from " << testLocations[c] << endl;
	}

	// test sine_terms and sine_sums
	double terms[SIZE], sums[SIZE];	
	double y = sine_sums( terms, SIZE, acos(-1)*3/2, sums );
	cout << "sin(3/2 * PI) = " << y << " (should be -1)" << endl;
	y = sine_sums( terms, SIZE, 1, sums );
	cout << "sin(1) = " << y << " (should be 0.84147...)" << endl;
}


