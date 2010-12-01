//
//	Row class header file
//
#pragma once
#include <cstdlib>
#include <iostream>

using namespace std;

class Row {
public:
/*  ctor declarations  */
	Row( );
	Row( int theArray[LIMIT] );
/*  Constants  */
	static const int LIMIT = 9;
	static const int BOUND = 3;
/*  Operators  */	
/*  Accessors  */
	int getValue( int rowIndex );
	void setValue( int seriesIndex, int newValue );
/*  Functions  */

private:
/*  Helper Functions  */
/*  Data Members  */
	int name;
	int SudokuRow[LIMIT];
};