/***
 * Read in at most an N x N integer array and determine if
 * it is symmetrical or not.
 */
#include <iostream>
#include <cstdlib> // exit
using namespace std;

int main()
{
	const int N( 8 );
	int A[N][N];  // Matrix of max size NxN
	int n; // user specified matrix size

	// prompt and read 
	cout << "Enter the matrix dimension: " << flush;
	if( !( ( cin >> n ) && n >= 1 && n <= N )) {
		cout << "Error: n is invalid (" << n << ")" << endl;
		// system("PAUSE"); // uncomment for windoze */
		exit(1);
	}
	cout << "Enter the matrix (" << n << 'x' << n << "): " << flush;
	for( int i(0); i<n; i++ ) {
		for( int j(0); j<n; j++ ) {
			if( !( cin >> A[i][j] ) ) break; // read error
		}
	}
	if( cin ) { // if matrix was read in successfully
		bool is_symmetric( true ); // assume it is
		for( int i(0); i<n; i++ ) {
			for( int j(0); j<n; j++ ) {
				if( A[i][j] != A[j][i] ) {
					// NOT!
					is_symmetric = false;
					break;
				}
			}
		}
		cout.setf( ios::boolalpha );
		cout << "Matrix is symmetric: " << is_symmetric << endl;
	} else {
		cout << "Error reading matrix data" << endl;
	}

	// fini 
	// system("PAUSE"); /** uncomment for windows */
	return 0;
}


