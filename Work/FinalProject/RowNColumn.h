//
//	RowNColumn class header file
//
#pragma once
#include <cstdlib>
#include <iostream>

using namespace std;

class RowNColumn {
public:
/*  ctor declarations  */
	RowNColumn( );
	RowNColumn( const int theArray[] );
	RowNColumn( const int theArray[], const string theName );
/*  Constants  */
	static const int LIMIT = 9;
	static const int BOUND = 3;
/*  Operators  */	
/*  Accessors  */
	int getValue( const int rowIndex );
	void setValue( const int seriesIndex, const int newValue );
/*  Functions  */

private:
/*  Helper Functions  */
/*  Data Members  */
	int name;
	int SudokuSequence[LIMIT];
};
