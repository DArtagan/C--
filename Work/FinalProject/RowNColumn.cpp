//
//	RowNColumn class implementation file
//
#include <cstdlib>
#include <iostream>

#include "RowNColumn.h"

using namespace std;

/*  ctor implementations  */
    // default ctor
	RowNColumn::RowNColumn( ) {
        name = "1A";  // Rows will be numbered off starting at the top of the board
                      // Columns will be lettered off starting at the left of the board
        for( int i(0); i < LIMIT; i++ ) {
            SudokuSequence[i] = 0;
        }
        solved = false;
        fork = 0;
    }
    // RowNColumn with only the array values given
	RowNColumn::RowNColumn( const int theArray[] ) {
        name = "1A";
        for( int i(0); i < LIMIT; i++ ) {
            SudokuSequence[i] = 0;
        }
        solved = false;
        fork = 0;
    }
    // RowNColumn with both a name and the array values given
    // *** We should probably just have this ctor, the others probably aren't necessary
    RowNColumn::RowNColumn( const string& theName, const int theArray[] ) {
        name = theName;
        for( int i(0); i < LIMIT; i++ ) {
            SudokuSequence[i] = theArray[i];
        }
        solved = false;
        fork = 0;
    }
/*  Operators  */	
    istream& operator>>( ostream& is, RowNColumn rhs ) {
        {
        double tempValue;
        for( int i(0); i < RowNColumn::LIMIT; i++ ) {
            if( !( is >> tempValue )) {
                is.setstate( ios::failbit );
                return is;
            } else {
                rhs.SudokuSequence[i] = tempValue;
            }
        }
        return is;
    }
    ostream& operator<<( ostream& os, const RowNColumn rhs ) {
        os << rhs.name;
        for( int i(0); i < RowNColumn::LIMIT; i++) {
            os << rhs.SudokuSequence[i];
        }
        return os;
    }
    
/*  Accessors  */
    // Gets the name
    string RowNColumn::getName( ) const {
        return name;
    }
	// Get value from the RowNColumn
	int RowNColumn::getValue( const int rowIndex ) const {
        return SudokuSequence[rowIndex];   
    }
	// Return whether the square is solved or not
	bool RowNColumn::getSolved( ) const {
        return solved;
    }
	// Return which fork this is on
	int RowNColumn::getFork( ) const {
        return fork;
    }
	// Sets the RowNColumns name
	void RowNColumn::setName( const string& theName ) {
        name = theName;
    }
	// Set value to the RowNColumn
	void RowNColumn::setValue( const int seriesIndex, const int newValue ) {
        SudokuSequence[seriesIndex] = newValue;
    }
	// Set this RowNColumn as solved or not
	void RowNColumn::setSolved( const bool isSolved ) {
        solved = isSolved;
    }
	// Set the fork for this RowNColumn
	void RowNColumn::setFork( const bool theFork ) {
        fork = theFork;
    }
    
/*  Functions  */
    // Tests the class for repeated numbers
	bool RowNColumn::test( ) const {
        // Variables
        bool theTest = true;
        
        // Test each value in the array against the values before it, starting at index 1
        for( int i(1); i < LIMIT ; i++ ) {
            for( int j(i - 1); j >= 0 ; j-- ) {
                if( SudokuSequence[i] == SudokuSequence[j] ) {
                    theTest = false;
                }
            }
        }
        
        return theTest;
    }

/*  Helper Functions  */

/*  Data Members  
	string name;
	int SudokuSequence[LIMIT];
	bool solved;
	int fork;
    */
