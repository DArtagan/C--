//
//  Header file for the checker program
//
#pragma once

#include <cstdlib>
#include <iostream>
#include "ThreeByThree.h"
#include "RowNColumn.h"

using namespace std;

int main();

// Display Functions
void table( int arrayValues[9][9] );
void givenHeader();
void solvedHeader();

// Manipulation and Checking Functions
void readSeed();
void populate(RowNColumn& roworcolumn, const int solvedpuzzlea[9][9], const int rnumber, const int cnumber);
void populate(ThreeByThree& box, const int array[9][9], const int col, const int row);
