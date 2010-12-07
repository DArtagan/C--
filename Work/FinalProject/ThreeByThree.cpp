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
	/* ThreeByThree::ThreeByThree( ) {
        name = "1"; *** 3x3s are named starting at the top, always at the left and moving right, down a row then moving right again
        for( int i(0); i < BOUND; i++ ) {
            for( int j(0); j < BOUND; j++ ) {
                SudokuBlock[i][j] = 0;
            }
        }
        solved = false;
        fork = 0;
    }*/
    // ctor for a defined name and array
	ThreeByThree::ThreeByThree( const string& theName, const int theArray[][BOUND] ) {
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
    ThreeByThree::ThreeByThree( const string& theName, const int theArray[][BOUND], const bool isSolved, const int theFork ) {
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
	/*friend ostream& operator<<( ostream& os, ThreeByThree rhs ) {
        
    }*/
/*  Accessors  */
    // Returns the name of the 3x3
	string ThreeByThree::getName( ) const {
        return name;
    }
    // Returns a specific value of the array
    int ThreeByThree::getValue( const int theRow, const int theCol ) const {
        return SudokuBlock[theRow][theCol];
    }
    // Returns whether the 3x3 is solved or not
	bool ThreeByThree::getSolved( ) const {
        return solved;
    }
    // Returns the fork of the 3x3
	int ThreeByThree::getFork( ) const {
        return fork;
    }
    // Sets the name
    void ThreeByThree::setName( const string& theName ) {
        name = theName;
    }
    // Sets the value of a specific index in the array
	void ThreeByThree::setValue( const int theRow, const int theCol, const int theValue ) {
        SudokuBlock[theRow][theCol] = theValue;
    }
    // Sets whether this array is solved or not
	void ThreeByThree::setSolved( const bool isSolved ) {
        solved = isSolved;
    }
    // Sets the fork of this 3x3
	void ThreeByThree::setFork( const int theFork ) { 
        fork = theFork;
    }
	
/*  Functions  */
    // Tests if a 3x3 has two or less unknowns (represented by 0)
	/*bool ThreeByThree::find( ) {
        
    }*/
	// Tests the class for repeated numbers
    bool ThreeByThree::test( ) const {
        // Variables
        bool theTest = true;
        int counter(0);
        int testArray[LIMIT] = {};
        
        // Reduce the 3x3 to a linear array for testing
        for( int i(0); i < BOUND; i++ ) {
            for( int j(0); j < BOUND; j++ ) {
                testArray[counter] = SudokuBlock[i][j];
                counter++;
            }
        }
        
        // Test each value in the array against the values before it, starting at index 1
        for( int i(1); i < LIMIT ; i++ ) {
            for( int j(i - 1); j >= 0 ; j-- ) {
                if( testArray[i] == testArray[j] ) theTest = false;
            }
        }
        return theTest;
    }

/*  Helper Functions  */
	/*bool ThreeByThree::guess( );  // (Might not be a good idea to guess*/
/*  Data Members  
    string name;  // Name of the 3x3
	int SudokuBlock[BOUND][BOUND];  // Holds the actual values
	bool solved;   // Tells whether the row/column is indisputably solved, so we don't need to re-test
	int fork;  // Keeps track of the forks we make when guessing
    */
