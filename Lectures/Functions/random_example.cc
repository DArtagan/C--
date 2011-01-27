// Example of the srand and rand command

#include <time.h>
#include <cstdlib>

#include <iostream>
#include <string>
using namespace std;

int main( )
{
	int seed = 0;
	int modder = 2;
	while( true ) {
		cout << "*** seed=" << seed << "  modder=" << modder << endl;
		if( seed == 0 ) {
			// wallclock
			srand( unsigned( time(0) ));
		} else {
			srand( seed );
		}

		// column labels
		for( int i(0); i<3; i++ ) {
			cout.unsetf( ios::left);
			cout.setf( ios::right );
			cout.width(12); cout << "rand()";
			cout.unsetf( ios::right );
			cout.setf( ios::left);
			cout << " ";
			cout.width(5); cout << "mod";
		}
		// i==0 generates an endl in the for loop below

		for( int i(0); i<9; i++ ) {
			if( !(i%3) ) cout << endl;
			int r = rand();  // new random value
			cout.unsetf( ios::left);
			cout.setf( ios::right );
			cout.width(12); cout << r;  // print rand()
			cout.unsetf( ios::right );
			cout.setf( ios::left);
			cout << " ";     // spacing
			cout.width(5); cout << r%modder;  // print mod
		}
		cout << endl << endl;
			
		cout << "Enter a seed and a modulus argument\n(seed=0 -> uses wallclock): " << flush;
		if( !( cin >> seed >> modder ) ) break;
	}

    //  Exit program.
    return 0;
}

