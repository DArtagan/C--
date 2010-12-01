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
	ThreeByThree( int theArray[][BOUND] );
/*  Constants  */
	static const int LIMIT = 9;
	static const int BOUND = 3;
/*  Operators  */	
	friend ostream& operator<<( ostream& os, ThreeByThree rhs );
/*  Accessors  */
	int getValue( int theRow, int theCol );
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

//////////////////////

//
//	Sudoku Program
//

bool testSudoku();

int main () {
	// All things done through functions that come from another header file.
}

bool testSudoku () {

}