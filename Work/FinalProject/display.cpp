//
//	Display functions for the checker program
//
#include <cstdlib>
#include <iostream>

#include "checker.h"

using namespace std;

void givenHeader() {
    system("CLS");
    cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
    cout<<"Please enter your completed sudoku."<<endl;
    cout<<"Enter all blanks as zeros (0) and separate inputs by a space."<<endl;
    cout << "Enter 10, random values fill the puzzle; enter 11, create a valid puzzle." << endl;
    cout << endl;
    input(solvedpuzzle);
}

void solvedHeader() {
    system("CLS");
    cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
    cout<<"Please enter your completed sudoku."<<endl;
    cout<<"Enter all blanks as zeros (0) and separate inputs by a space."<<endl;
    cout << "Enter 10, random values fill the puzzle; enter 11, create a valid puzzle." << endl;
    cout << endl;
    input(solvedpuzzle);
}
