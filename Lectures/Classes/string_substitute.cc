/**
 * untility function for substituting chars in a string
 *
 */

#include <iostream>
#include "string_substitute.h"
using namespace std;

/***
 * make sure string s is non-empty (otherwise filled in with "???"),
 * substitute c for all characters in replace for all occurances in s,
 * returns a NEW string object (doesn't change s).
 */
string string_substitute( const string& s, const string& replace, char c )
{
	string r;
	for( int i=0; i<int(s.length()); i++ ) {
		// if the ith char is in replace
		if( int(replace.find(s[i])) >= 0 ) {
			// substitute c --- if c's ASCII code is > 0 
			// (otherwise, we are simply deleting all the chars 
			// in replace from s).
			if( c ) r += c;
		} else {
			// use the char from s
			r += s[i];
		}
	}
	// make sure r contains data
	if( r.length() == 0 ) {
		r = "???";
	}
	return r;
}

