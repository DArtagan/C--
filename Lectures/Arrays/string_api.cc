/***
 * This application demonstrates the C++ string api
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main( )
{
	const string theString( "Ramblin' wreck from Golden Tech," );

	// string objects support a member function length() and array (like)
	// access to char values!
	for( int i(0); i<theString.length(); /* empty */ ) {
		cout << i << ":" << theString[i] << "\t";
		if( !(++i%5) ) cout << endl; 
	}
	cout << endl;

	// the member function find(...) returns the index of a searched for string,
	// or -1 if the string cannot be found.
	cout << "wreck is at index " << theString.find( "wreck" ) << endl;
	if( theString.find( "CSU student" ) == -1 ) {
		cout << "there is no CSU student here!" << endl;
	} 
	cout << endl;

	int golden_index = theString.find( "Golden" );
	// the substr() member function may be called with ONE OR TWO PARAMETERS:
	// two parameters takes a number of characters as the second argument
	string goldenString = theString.substr( golden_index, 6 );
	// with just an index provided, the remainder of the string is returned
	string goldenTechComma = theString.substr( golden_index );	
	// notice that the original string has not changed (it cannot, it is const!)
	cout << theString << endl;
	cout << goldenString << endl;
	cout << goldenTechComma << endl;
	cout << endl;

	// strings may be +'d together (string concatenation)
	const string anotherString( "A helluva engineer!" );

	string fightStanza = theString + " " + anotherString;

	cout << fightStanza << endl;
	cout << endl;

	string CSUStanza = fightStanza;
	// the replace() member function can be used to modify a range of characters in
	// a string.
	// argument 1=beginning offset.
	// argument 2=length of characters to replace
	// argument 3=replacement text
	CSUStanza.replace( 0, 8, "CSU" );
	int comma_index = CSUStanza.find( "," );
	// UPDATE!  Golden's location is changed after the replace()!
	golden_index = CSUStanza.find( "Golden" ); 
	CSUStanza.replace( golden_index, comma_index-golden_index, "Fort Collins" );
	// UPDATE! the comma is in a different location now...
	comma_index = CSUStanza.find( "," );
	// judicious use of replace allows portions of a string to be replaced
	CSUStanza.replace( comma_index, CSUStanza.length()-comma_index, "" );

	cout << fightStanza << endl;
	cout << CSUStanza << endl;

	// Finally, < > <= >= may all be used to compare strings based on alphabetical order
	// (technically, off of the order of ASCII codes, so digits, then capitals,
	// then lowercase)
	if( CSUStanza < theString ) {
		cout << "As expected, CSU is less than Mines :^)." << endl;
	}

	return 0;
}
