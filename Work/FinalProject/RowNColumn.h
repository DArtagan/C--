//
//	RowNColumn class header file
//
#pragma once

#include <cstdlib>
#include <iostream>

using namespace std;

class RowNColumn {
public:
/*  Constants  */
	static const int LIMIT = 9;
	static const int BOUND = 3;
	static const int ROW = 0;
	static const int COLUMN = 1;
/*  ctor declarations  */
	RowNColumn( );
	RowNColumn( const int theArray[] );
	RowNColumn( const string& theName, const int theArray[], const int theType );
/*  Operators  */
    friend istream& operator>>( istream& is, RowNColumn& rhs );
    friend void operator>>( const int lhs[], RowNColumn& rhs );
    friend ostream& operator<<( ostream& os, const RowNColumn& rhs );
	
/*  Accessors  */
    // Get the 3x3s name
    string getName( ) const;
    // Return a value in the array
	int getValue( const int rowIndex ) const;
	// Return whether the square is solved or not
	bool getSolved( ) const;
	// Return which fork this is on
	int getType( ) const;
	// Sets the RowNColumns name
	void setName( const string& theName );
	// Sets a specific value in the array
	void setValue( const int seriesIndex, const int newValue );
	// Set this RowNColumn as solved or not
	void setSolved( const bool isSolved );
	// Set the fork for this RowNColumn
	void setType( const int theType );
/*  Functions  */
    // Tests the class for repeated numbers
	bool test( ) const;

private:
/*  Helper Functions  */

/*  Data Members  */
	string name;
	int SudokuSequence[LIMIT];
	bool solved;
    int type;  // 0 for Row, 1 for Column
};
