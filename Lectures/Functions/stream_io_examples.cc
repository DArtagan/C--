/***
 * Example of using iostream as function parameters
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

istream& readTwoDoubles( istream& input, double& d1, double& d2 )
{
	input >> d1 >> d2;	
	return input;
}

ostream& writeTwoDoubles( ostream& output, double d1, double d2 )
{
	output << d1 << endl;
	output << d2 << endl;
	return output;
}


int main( )
{
	/***
	 * This application uses read and write TwoDoubles
	 * with both the console and data files as arguments.
	 *
	 * Notice the semantic similarity with how we use the 
	 * getline() function!
	 */
	double x, y;
	cout << "Enter two doubles: " << flush;
	if( !readTwoDoubles( cin, x, y )) {
		cout << "Error reading doubles, good-bye." << endl;
		exit(1);
	}

	ofstream outfile( "TWODOUBLES.DAT" );
	if( !outfile ) {
		cout << "Error opening TWODOUBLES.DAT" << endl;
		exit(1);
	}

	writeTwoDoubles( outfile, x, y );
	// write again
	writeTwoDoubles( outfile, -y, -x );
	outfile.close();

	// now read the data back in from the file,
	// writing it to the console.
	ifstream infile( "TWODOUBLES.DAT" );
	if( !infile ) {
		cout << "Error opening TWODOUBLES.DAT" << endl;
		exit(1);
	}

	const string LABELS[] = {"first", "second"};
	for( int i(0); i<2; i++ ) {
		if( readTwoDoubles( infile, x, y ) ) {
			cout << "The " << LABELS[i] << 
					" set of doubles..." << endl;
			writeTwoDoubles( cout, x, y );
		}
	}
	// all done
	infile.close();
	
	return 0;
}
