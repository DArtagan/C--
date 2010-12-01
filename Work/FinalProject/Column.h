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
	RowNColumn( int theArray[LIMIT] );
/*  Constants  */
	static const int LIMIT = 9;
	static const int BOUND = 3;
/*  Operators  */	
/*  Accessors  */
	int getValue( int seriesIndex );
	void setValue( int seriesIndex, int newValue );
/*  Functions  */
	bool find( );  // Tests if a row/column has two or less unknowns (represented by 0), when it finds that row/column it runs the guess helper function
	bool test( );   // Tests the class for repeated number
	
	
private:
/*  Helper Functions  */
	bool guess( );  // 
/*  Data Members  */
	int name;
	int SudokuSeries[LIMIT];
	bool solved;  // Tells whether the row/column is indisputably solved, so we don't need to re-test
	int fork;  // Keeps track of the forks we make when guessing
};

//	It is a very good idea to condense the column and row classes into one because our columns act like rows, all the same functions would apply
//  Identification would be taken care of using nameing conventions