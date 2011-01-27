/**
 * untility function for substituting chars in a string
 */

#pragma once
#include <string>
using namespace std;

/***
 * make sure string s is non-empty (otherwise filled in with "???"),
 * substitute c for all characters in replace for all occurances in s,
 * returns a NEW string object (doesn't change s).
 */
string string_substitute( const string& s, const string& replace, char c );

