//
//  Driver file for testing the Month class
//
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Month.h"
using namespace std;

void displayTestResult( const Month& test, const string& description )
{
	test.output( cout ) << " " << description << " (month number ";
	test.outputMonthNumber( cout ) << "==" << test.getMonthNumber() << ").";
	cout << " Make sure this is correct." << endl;
	cout << "THE ABOVE TEST SHOULD HAVE BEEN PRINTED ON ONE CONSOLE LINE." << endl;
	cout << endl;
}

int main( )
{
	cout << "***************************" << endl;
	cout << "* Driver for Month testing" << endl;
	cout << "***************************" << endl;

	/***
	 * Test default ctor
	 */
	Month defaultMonth;
	defaultMonth.output( cout << "This should be January: " ) << endl;

	/***
	 * Test string param ctor
	 */
	while( true ) {
		const string QUIT("QUIT");
		string mname;
		cout << "Enter the first three letters of a month," << endl;
		cout << "properly capitalized (" << QUIT << " to finish): " << flush;
		if( !(cin >> mname) ) {
			cout << "Error reading name, good-bye" << endl;
			break;
		}
		if( mname == QUIT ) {
			break;
		}

		Month test( mname );
		displayTestResult( test, "Month object was created." );
	}
	cout << endl;

	/***
	 * Test int param ctor
	 */
	while( true ) {
		const int QUIT(-1);
		int mnum;
		cout << "Enter the number of a month (" << QUIT << " to finish): " << flush;
		if( !( cin >> mnum )) {
			cout << "Error reading number, good-bye" << endl;
			break;
		}
		if( mnum == QUIT ) {
			break;
		}

		Month test( mnum );
		displayTestResult( test, "Month object was created." );
	}
	cout << endl;

	/***
	 * Test input stream of name
	 */
	cout << "How many input stream tests? " << flush;
	int tests;
	if( cin >> tests ) {
		for( int i=0; i<tests; i++ ) {
			cout << "Enter the first three letters of a month," << endl;
			cout << "properly capitalized (any invalid month to finish): " << flush;
			Month test;
			if( !test.input( cin )) {
				cout << "Error reading name, good-bye" << endl;
				break;
			}

			displayTestResult( test, "Month object was created." );
		}
	}
	cout << endl;

	cout << "***************************" << endl;
	cout << "* All ctors and i/o functions, and getMonthNumber() has now been tested!" << endl;
	cout << "***************************" << endl;

	/***
	 * Test const member functions for offset based months
	 */
	const int MONTHS=12;
	const Month YEAR[] = { Month(1), Month(2), Month(3), Month(4), Month(5), Month(6),
		Month(7), Month(8), Month(9), Month(10), Month(11), Month(12) };
	
	cout << "Testing .previous()..." << endl;
	for( int i=0; i<MONTHS; i++ ) {
		if( YEAR[i].previous().getMonthNumber() != (i+MONTHS-1)%MONTHS+1 ) {
			YEAR[i].previous().output( cout ) << " is not before ";
			YEAR[i].output( cout );
			cout << endl << "TERMINATE with failure." << endl;
			system("pause");
			exit(1);
		} else {
			// assure that output, outputMonthNumber, and getMonthNumber 
			// are const member functions.
			displayTestResult( YEAR[i], "const Month object tested" );
		}
	}
	cout << "Testing .previous()...";
	cout << " OK!" << endl;

	cout << "Testing .next()...";
	for( int i=0; i<MONTHS; i++ ) {
		if( YEAR[i].next().getMonthNumber() != (i+1)%MONTHS+1 ) {
			YEAR[i].next().output( cout ) << " is not after ";
			YEAR[i].output( cout );
			cout << endl << "TERMINATE with failure." << endl;
			system("pause");
			exit(1);
		}
	}
	cout << " OK!" << endl;

	cout << "Testing .next( count )...";	
	const int COUNTS = 3;
	const int COUNT[COUNTS] = { 24, 512, 83749 };
	for( int i=0; i<MONTHS; i++ ) {
		for( int c=0; c<COUNTS; c++ ) {
			if( YEAR[i].next(COUNT[c]).getMonthNumber() != (i+COUNT[c])%MONTHS+1 ) {
				YEAR[i].next(COUNT[c]).output( cout ) << " is not the " << COUNT[c] << " month after ";
				YEAR[i].output( cout );
				cout << endl << "TERMINATE with failure." << endl;
				system("pause");
				exit(1);
			/* else {
				YEAR[i].next(COUNT[c]).output(cout) << " is the " << COUNT[c] << "th month after ";
				YEAR[i].output( cout ) << endl;
			*/
			}
		}
	}
	cout << " OK!" << endl << endl;

	cout << "***************************" << endl;
	cout << "* All required interfaces for Month pass." << endl;
	cout << "* Go take a nap." << endl;
	cout << "***************************" << endl;

	system("pause");
	return 0;
}
