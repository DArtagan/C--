//
//	RowNColumn class implementation file
//
#pragma once
#include <cstdlib>
#include <iostream>

#include "RowNColumn.h

using namespace std;

/*  ctor implementations  */
    // RowNColumn with no input, default ctor
	RowNColumn::RowNColumn( ) {
        name = "1A";  // Rows will be numbered off starting at the top of the board
                     // Columns will be lettered off starting at the left of the board
        for( int i(0); i < LIMIT; i++ ) {
            [i] = 0;
        }
    // RowNColumn with only the array values given
	RowNColumn::RowNColumn( const int theArray[] );
        name = "1A";
        for( int i(0); i < LIMIT; i++ ) {
            SudokuSequence[i] = theArray[i];
        }
    // RowNColumn with both a name and the array values given
    // ***We should probably just have this ctor
    RowNColumn::RowNColumn( const int theArray[], const string theName );
        name = theName;
        for( int i(0); i < LIMIT; i++ ) {
            SudokuSequence[i] = theArray[i];
        }
/*  Operators  */	
/*  Accessors  */
    // Get value from the RowNColumn
	int RowNColumn::getValue( const int rowIndex ) {
        return SudokuSequence[rowIndex];   
    }
    // Set value to the RowNColumn
	void setValue( const int seriesIndex, const int newValue ) {
        SudokuSequence[seriesIndex] = newVale;
    }
/*  Functions  */


/*  Helper Functions  */

