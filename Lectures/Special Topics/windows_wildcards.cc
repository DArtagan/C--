/**
 * Example of scanning a directory for files, and opening 
 * each with .open() and .c_str()
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	// where the file list will be written to
	const string FILELISTNAME( "FILELIST" );

	// user-specified extension
	string ext;
	cout << "What extension to search for? " << flush;
	cin >> ext;

	// build the command
	string cmd( "dir /b *." );
	cmd += ext;
	cmd += " > ";
	cmd += FILELISTNAME;
	cout << "cmd=" << cmd << endl;

	// note the use of c_str() 
	system( cmd.c_str() );

	/***
	 * now, FILELIST contains a list of all the files
	 * with extension ext
	 */
	// again, the use of c_str() 
	ifstream infile( FILELISTNAME.c_str() );
	if( !infile ) {
		cout << FILELISTNAME << " does not exist!" << endl;
		system("pause");
		exit(1);
	}

	string fname_from_list;
	while( getline( infile, fname_from_list, '\n' ) ) {
		/***
		 * for each file name in the list...
		 */
		ifstream f( fname_from_list.c_str() );
		if( !f ) {
			cout << "Strange:  " << fname_from_list << 
					" could not be opened." << endl;
			// close is not required after an open error
		} else {
			// reading to '\0' retreives the entire contents
			string filedata;
			getline( f, filedata, '\0' );

			// generates a table of bytes per file
			cout.width(12);
			cout << filedata.length() << " " <<
				fname_from_list << ": " << 
				filedata.substr(0,32) << endl;

			// close
			f.close();
		}
	}

	// close file
	infile.close();

	system("pause");
	return 0;
}

