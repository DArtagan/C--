/**
 * Example of cls and textcolor to display a file
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

void randomcolor()
{
	/********************************
	 * FROM Windows XP >color /h
	 ********************************
		Color attributes are specified by TWO hex digits -- the first
		corresponds to the background; the second the foreground.  Each digit
		can be any of the following values:

			0 = Black       8 = Gray
			1 = Blue        9 = Light Blue
			2 = Green       A = Light Green
			3 = Aqua        B = Light Aqua
			4 = Red         C = Light Red
			5 = Purple      D = Light Purple
			6 = Yellow      E = Light Yellow
			7 = White       F = Bright White

		<snip/>

		Example: "COLOR fc" produces light red on bright white
	 ********************************/
	const int COLORS=16;
	char codes[] = {'0','1','2','3','4','5','6','7','8','9',
			'0','A','B','C','D','E','F'};

	string cmd( "color ");
	// foreground
	cmd += char( codes[rand()%COLORS] );
	// background
	cmd += char( codes[rand()%COLORS] );

	// note the use of c_str()
	system( cmd.c_str() );
	cout << "C++ Screen Color Command: system( \"" << cmd << "\" );" << endl;
}

int main()
{
	const int MAXLINES=20;
	string fname;
	cout << "Enter a file name: " << flush;
	cin >> fname;

	// note, the use of c_str() 
	ifstream infile( fname.c_str() );
	if( !infile ) {
		cout << fname << " does not exist!" << endl;
		system("pause");
		exit(1);
	}

	// clear console
	system( "cls" );
	int lines = 0;
	string linedata;
	while( getline( infile, linedata, '\n' ) ) {

		// show pages
		cout.width(5);
		cout << ++lines << " ";
		cout << linedata << endl;
		
		if( lines % MAXLINES == 0 ) { // 
			cout << "c=continue q=quit..." << flush;
			char cmd;
			cin >> cmd;
			if( cmd == 'q' ) break;  // exit
			// clear console
			system( "cls" );
			// change display color
			randomcolor();
		}
	}

	// close file
	infile.close();
	system( "pause" );
	return 0;
}

