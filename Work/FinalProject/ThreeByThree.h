//
//	ThreeByThree class header file
//
#pragma once
#include <cstdlib>
#include <iostream>

using namespace std;

class ThreeByThree {
public:
/*  ctor declarations  */
	ThreeByThree( );
	ThreeByThree( const string theName, const int theArray[][BOUND] );
	ThreeByThree( const string theName, const int theArray[][BOUND], const bool isSolved, const int theFork );
/*  Constants  */
	static const int LIMIT = 9;
	static const int BOUND = 3;
/*  Operators  */	
	friend ostream& operator<<( ostream& os, ThreeByThree rhs );
/*  Accessors  */
	int getValue( const int theRow, const int theCol );
	string getName( );
	bool getSolved( );
	int getFork( );
	void setValue( const int theRow, const int theCol, const int theValue );
	void setName( const string theName );
	void setSolved( const bool isSolved );
	void setFork( const int theFork );
/*  Functions  */
	bool find( );  // Tests if a 3x3 has two or less unknowns (represented by 0)
	bool test( );   // Tests the class for repeated numbers

private:
/*  Helper Functions  */
	bool guess( );  // (Might not be a good idea to guess
/*  Data Members  */
	int name;  // Name of the 3x3
	int SudokuBlock[BOUND][BOUND];  // Holds the actual values
	bool solved;   // Tells whether the row/column is indisputably solved, so we don't need to re-test
	int fork;  // Keeps track of the forks we make when guessing
};
