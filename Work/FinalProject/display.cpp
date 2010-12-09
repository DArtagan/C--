//
//	Display functions for the checker program
//
#include <cstdlib>
#include <iostream>

#include "checker.h"

using namespace std;

void table( int arrayValues[9][9] ) {
    string letters  ("  a  b  c  d  e  f  g  h  i ");
    string lineout(" ============================");
    string spacerout("| ");
    int linenumber(1);
   
    cout<<letters<<endl;
   
    for( int i = 0; i<9 ;i++ ) {
       cout << lineout << endl;
       cout << linenumber;
       for( int j=0; j<9; j++ ) {
           cout<<spacerout<<arrayValues[i][j];
           if( j==8 ) {
               cout<<spacerout<<endl;
           }
       }
       linenumber++;
    }
    cout << lineout << endl;
}

void givenHeader() {
    system("CLS");
    cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
    cout<<"Please enter the original, given sudoku."<<endl;
    cout<<"Enter all blanks as zeros (0) and separate inputs by a space."<<endl;
    cout << "Enter 10, random values fill the puzzle; enter 11, create a valid puzzle." << endl;
    cout << endl;
}

void solvedHeader() {
    system("CLS");
    cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
    cout<<"Please enter your completed sudoku."<<endl;
    cout<<"Enter all blanks as zeros (0) and separate inputs by a space."<<endl;
    cout << "Enter 10, random values fill the puzzle; enter 11, create a valid puzzle." << endl;
    cout << endl;
}
