//
//	ThreeByThree class header file
//
#pragma once

#include <cstdlib>
#include <iostream>

using namespace std;

class ThreeByThree {
public:
/*  Constants  */
	static const int LIMIT = 9;
	static const int BOUND = 3;
/*  ctor declarations  */
	// ThreeByThree( ); *** Probably not necessary
	ThreeByThree( const string& theName, const int theArray[][BOUND] );
	ThreeByThree( const string& theName, const int theArray[][BOUND], const bool isSolved, const int theFork );
/*  Operators  */	
    friend istream& operator>>( ostream& is, ThreeByThree rhs );
    friend ostream& operator<<( ostream& os, const ThreeByThree rhs );
/*  Accessors  */
	// Returns the name of the 3x3
	string getName( ) const;
    // Returns a specific value of the array
    int getValue( const int theRow, const int theCol ) const;
    // Returns whether the 3x3 is solved or not
	bool getSolved( ) const;
    // Returns the fork of the 3x3
	int getFork( ) const;
    // Sets the name
    void setName( const string& theName );
    // Sets the value of a specific index in the array
	void setValue( const int theRow, const int theCol, const int theValue );
    // Sets whether this array is solved or not
	void setSolved( const bool isSolved );
    // Sets the fork of this 3x3
	void setFork( const int theFork );

/*  Functions  */
    /*// Tests if a 3x3 has two or less unknowns (represented by 0)  *** Probably not necessary for this version of our project
	bool find( );*/
	// Tests the class for repeated numbers
	bool test( ) const ;

private:
/*  Helper Functions  */
	//bool guess( );  // (Might not be a good idea to guess)   *** Probably not necessary for this version of our project 

/*  Data Members  */
	string name;  // Name of the 3x3
	int SudokuBlock[BOUND][BOUND];  // Holds the actual values
	bool solved;   // Tells whether the row/column is indisputably solved, so we don't need to re-test
	int fork;  // Keeps track of the forks we make when guessing
};
