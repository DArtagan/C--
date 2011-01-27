#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/***
 * prompts for and reads an int, checks the input value to be sure it 
 * is within [minval,maxval], and returns the value if all is well.
 *
 * use maxval<=minval to disable range checking.
 *
 * this function recovers the input stream from typos.
 */
istream& getInteger( istream& is, const string& prompt, 
		int minval, int maxval, int& input )
{
	// as long as cin is readable
	while( is ) {
		cout << prompt << ": " << flush;
		if( is >> input ) {
			// check against range
			if( minval<maxval && (input<minval || input>maxval) ) {
				cout << "error:  value must be within [" <<
					minval << "," << maxval << "]." << endl;
			} else {
				// all is well, return to the calling function
				return is;
			}
		} else {
			// there was an error parsing an int, 
			// clear out the rest of the line with getline
			string dummy;
			cin.clear(); // required!
			getline( is, dummy, '\n' );
			// error message
			cout << "error parsing an integer from input." << endl;
		}
	}
	return is;
}

int main()
{
	int x, y, z;
	if( getInteger( cin, "Enter a positive integer less than 1000", 1, 999, x ) ) {
		cout << "Read in " << x << endl;
	}
	if( getInteger( cin, "Enter a negative integer greater than -1000", -999, -1, y ) ) {
		cout << "Read in " << y << endl;
	}
	if( getInteger( cin, "Enter an integer", 0, 0, z ) ) {
		cout << "Read in " << z << endl;
	}
	return 0;
}
