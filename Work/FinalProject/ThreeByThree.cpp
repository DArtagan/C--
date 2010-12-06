//
//	ThreeByThree implementation file
//
#pragma once
#include <cstdlib>
#include <iostream>

#include "ThreeByThree.h"

using namespace std;

/*  ctor declarations  */
    // A default ctor might not be important
	// ThreeByThree::ThreeByThree( ) {
    // ctor for a defined name and array
	ThreeByThree::ThreeByThree( const string theName, const int theArray[][BOUND] ) {
        name = theName;
        for( int i(0); i < BOUND; i++ ) {
            for( int j(0); j < BOUND; j++ ) {
                SudokuBlock[i][j] = theArray[i][j];
                
            }
        }
        solved = false;
        fork = 0;
    }
    // ctor for a defined name and array and solved vale and fork value
    ThreeByThree::ThreeByThree( const string theName, const int theArray[][BOUND], const bool isSolved, const int theFork ) {
        name = theName;
        for( int i(0); i < BOUND; i++ ) {
            for( int j(0); j < BOUND; j++ ) {
                SudokuBlock[i][j] = theArray[i][j];
                
            }
        }
        solved = isSolved;
        fork = theFork;
    }
/*  Operators  */	
	friend ostream& operator<<( ostream& os, ThreeByThree rhs ) {
        
    }
/*  Accessors  */
	int getValue( const int theRow, const int theCol ) {
        
    }
	string getName( ) {
        
    }
	bool getSolved( ) {
        
    }
	int getFork( ) {
        
    }
	void setValue( const int theRow, const int theCol, const int theValue ) {
        
    }
	void setName( const string theName ) {
        
    }
	void setSolved( const bool isSolved ) {
        
    }
	void setFork( const int theFork ) { 
        
    }
	
/*  Functions  */
    // Tests if a 3x3 has two or less unknowns (represented by 0)
	bool ThreeByThree::find( ) {
        
    }
	// Tests the class for repeated numbers
    bool ThreeByThree::test( ) {
        
    }

private:
/*  Helper Functions  */
	bool ThreeByThree::guess( );  // (Might not be a good idea to guess
/*  Data Members  */
	/*int name;  // Name of the 3x3
	int SudokuBlock[BOUND][BOUND];  // Holds the actual values
	bool solved;   // Tells whether the row/column is indisputably solved, so we don't need to re-test
	int fork;  // Keeps track of the forks we make when guessing*/
};
