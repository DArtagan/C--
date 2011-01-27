// Example of the Sleep() command on windows machines
// (note the CAPITAL S, distingiushing this version of sleeping
// from the usual POSIX standard (thank you, M$).

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main( )
{
	const int MOUNTAIN(11);
	char mountain[MOUNTAIN] = { '.', ',', ':', ';', '|', 'I', 
		'|', ';', ':', ',', '.' };

	const int LINEDATA(60);
	// a string with LINEDATA space characters
	string linedata( LINEDATA, ' ' );

	const int LAG(MOUNTAIN*3/2);

	const int SLEEPFACTOR(150);

	// format the full line 300 times
	for( int i(0), j(-LAG); i<LINEDATA*300; i++, j++ ) {
		// next mountain part
		linedata[i%LINEDATA] = mountain[i%MOUNTAIN];
		if( j>=0 ) {
			// lag logic
			linedata[j%LINEDATA] = ' ';
		}
		// hmm, what is this '\r' beast?
		cout << linedata << '\r' << flush;

		// sleep longer "on the way up"
		//   void Sleep( unsigned int milliseconds );
		if( i%MOUNTAIN < 4 ) {
			Sleep( 2*SLEEPFACTOR );
		} else {
			Sleep( 1*SLEEPFACTOR );
		}
	}

    //  Exit program.
    return 0;
}

