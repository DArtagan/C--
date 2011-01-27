/***
 * Read in at most 8 percentiles from cin and print 
 * them back out converted to fractional equivalents.
 */
#include <iostream>
using namespace std;

int main()
{
	const int MAXPOINTS( 8 );
	double percents[MAXPOINTS];  // values will be read from cin

	// prompt and read 
	cout << "Enter percents at the keyboard (with percent sign);" << endl;
	cout << "Maximum " << MAXPOINTS << " points, or 'end' to stop: " << endl;

	// read, count with p
	int p = 0; 
	while( p < MAXPOINTS ) {
		char percent_sign;
		if( !( cin >> percents[p] >> percent_sign )) {
			// read failure
			break;
		}
		// otherwise, inc p
		p++;
	}

	// change the value to fractional equivalents
	// i goes to <p, NOT <MAXPOINTS
	for( int i=0; i<p; i++ ) percents[i] /= 100;
	
	// print fractional values back out...
	const int WIDTH(12);			// width of columns
	const int COLUMNS( 3 );      	// columns of output
	cout.setf( ios::fixed );
	cout.precision(5);
	for( int i=0; i<p; i++ ) {
		cout << cout.width(WIDTH) << percents[i];
		if( !((i+1)%COLUMNS) ) {  // newline every three 
			cout << endl;
		}
	}
	if( p%COLUMNS ) {  // the last loop didn't print an endl, do so now
		cout << endl;
	}

	// fini 
	// system("PAUSE"); /** uncomment for windows */
	return 0;
}


