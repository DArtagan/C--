//
//	Manipulation and checking functions for the checker program
//
#include <cstdlib>
#include <iostream>

#include "ThreeByThree.h"
#include "RowNColumn.h"
#include "checker.h"

using namespace std;

// 
void readSeed() {
    /*  Variables  */
    int n;

    /*  Seed Prompt  */
    cout << "What would you like the seed for rand() to be? (If 0, use wall clock)" << endl;
    cin >> n;
    cout << endl << endl;
    if( n == 0 ) {
        n = unsigned(time(0));  // Wallclock
    }
    srand(n);
}

//  Function for populating the RowNColumn classes
void populate(RowNColumn& roworcolumn, const int solvedpuzzlea[9][9], const int rnumber, const int cnumber) {
    int tarray[9] = {};
    
    if(cnumber == 10) {
        for(int i = 0; i<9; i++) {
            tarray[i] = solvedpuzzlea[rnumber][i];
        }
        tarray >> roworcolumn;
    } else {
        for(int i = 0; i<9; i++) {
            tarray[i] = solvedpuzzlea[i][cnumber];
        }
        tarray >> roworcolumn;
    }      
}

//  Populate the Three by Three class
void populate(ThreeByThree& box, const int array[9][9], const int col, const int row) {
    int tempArray[3][3]={};
    
    for( int i(0); i < ThreeByThree::BOUND; i++ ) {
        for( int j(0); j < ThreeByThree::BOUND; j++ ) {
            tempArray[i][j] = array[i + row][j + col];
        }
    }
    tempArray >> box;
}
