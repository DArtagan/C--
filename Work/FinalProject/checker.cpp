#include <cstdlib>
#include <iostream>
#include <string>

#include "RowNColumn.h"
#include "ThreeByThree.h"
#include "checker.h"

using namespace std;
/*      Proofreading function
istream& getInteger( istream& is, const string& prompt,
       int minval, int maxval, int& input )
{
   // as long as cin is readable
   while( is ) {
       cout << prompt << ": " << flush;
       if( is >> input ) {
           // check against range
           if( minval<maxval && (input<minval || input>maxval) ) {
               cout << "error:  value must be within [" <<
                   minval << "," << maxval << "]." << endl;
           } else {
               // all is well, return to the calling function
               return is;
           }
       } else {
           // there was an error parsing an int,
           // clear out the rest of the line with getline
           string dummy;
           cin.clear(); // required!
           getline( is, dummy, '\n' );
           // error message
           cout << "error parsing an integer from input." << endl;
       }
   }
   return is;
}
*/
//      Input interface

void input(int arrayValues[9][9])
{
   
    string letters  ("  a  b  c  d  e  f  g  h  i ");
    string lineout(" ============================");
    string spacerout("| ");
    int linenumber(1);
   
    cout<<letters<<endl;
   
    for(int i = 0; i<9;i++)
    {
       cout<<lineout<<endl;
       cout<<linenumber;
       for(int j=0; j<9;j++)
       {
           cout<<spacerout<<arrayValues[i][j];
           
           if(j==8)
           {
               cout<<spacerout<<endl;
           }
       }
       linenumber++;

    }
   
    cout<<lineout<<endl;
}

void readSeed() 
{
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


//      Function for populating the class variables


void populate(RowNColumn& roworcolumn, const int solvedpuzzlea[9][9], const int rnumber, const int cnumber)
{
    int tarray[9]={};
    
    if(cnumber==10) {
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


//      Populate the Three by Three class

void populate(ThreeByThree& box, const int array[9][9], const int col, const int row)
{
    int temparray[3][3]={};
    
    for(int i=row; i<(row+3); i++)
    {
        for(int j=col;j<(col+3);j++)
        {
        temparray[i][j]=array[i][j];
        }
    }
    temparray>>box;
}

    

//      Sudoku Checker main routine

int main()
{
    //  Initialize variables
    const int puzzlesize(9);
    int givenpuzzle[puzzlesize][puzzlesize]={};
    int solvedpuzzle[puzzlesize][puzzlesize]={};
    string coordinates[puzzlesize][puzzlesize];
    int prompt;
    string temp("");
    int temparray[puzzlesize];
   
   
    for(int i =0;i<puzzlesize;i++)
    {
       for(int j=0; j<puzzlesize;j++)
       {
           temp+=(char('a'+j));
           temp+=char('1'+i);
           coordinates[i][j] += temp;
           temp.clear();
       }
    }
       
        
       
  

    //  Prompt the user for input of the known numbers
   
    bool dobreak = false;
    for(int i=0; i<puzzlesize && !dobreak; i++)
    {
       for(int j=0; j<puzzlesize; j++)
       {
           cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
           cout<<"Please enter the given values in the sudoku puzzle."<<endl;
           cout<<"Enter all blanks as zeros (0) and separate inputs by a space."<<endl;
           cout << "Enter 10, random values fill the puzzle; enter 11, create a valid puzzle." << endl;
           cout << endl;
           input(givenpuzzle);
           cout<<"Please enter "<<coordinates[i][j]<<" "<<flush;
           //  Proofreading the input
           cin>>prompt;
           while(((prompt<0) || (prompt>11)))
           {
               cout<<"Please enter "<<coordinates[i][j]<<" "<<flush;
               cin>>prompt;
           }
            if( prompt == 10 ) {
                readSeed();
                for( int k(0); k < puzzlesize; k++ ) {
                    for( int l(0); l < puzzlesize; l++ ) {
                        givenpuzzle[k][l] = rand() % puzzlesize + 1;
                    }
                }
                system("CLS");
                cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
                cout<<"Please enter the given values in the sudoku puzzle."<<endl;
                cout<<"Enter all blanks as zeros (0) and separate inputs by a space."<<endl;
                cout << "Enter 10, random values fill the puzzle; enter 11, create a valid puzzle." << endl;
                cout << endl;
                input(givenpuzzle);
                dobreak = true;
                break;
            } else if( prompt == 11 ) {
                int counter(0);
                for( int k(0); k < puzzlesize; k++ ) {
                    counter += 3;
                    for( int l(0); l < puzzlesize; l++ ) {
                        if( counter % 39 == 0 ) counter = 2;
                        if( counter % 38 == 0 ) counter = 1;
                        counter++;
                        givenpuzzle[k][l] = counter % 9 + 1;
                    }
                }
                system("CLS");
                cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
                cout<<"Please enter the given values in the sudoku puzzle."<<endl;
                cout<<"Enter all blanks as zeros (0) and separate inputs by a space."<<endl;
                cout << "Enter 10, random values fill the puzzle; enter 11, create a valid puzzle." << endl;
                cout << endl;
                input(givenpuzzle);
                dobreak = true;
                break;
            } else {
           givenpuzzle[i][j]=prompt;
            }
           
           system("CLS");
    
       }       
    }
   
   
    system("PAUSE");
    system("CLS");
   
//      Prompt User for their solved puzzle

    dobreak = false;
    for(int i=0; i<puzzlesize && !dobreak; i++) {
       for(int j=0; j<puzzlesize; j++) {
           cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
           cout<<"Please enter your completed sudoku."<<endl;
           cout<<"Enter all blanks as zeros (0) and separate inputs by a space."<<endl;
           input(solvedpuzzle);
           cout<<"Please enter "<<coordinates[i][j]<<" "<<flush;
           //  Proofreading the input
           cin>>prompt;
           while(((prompt<0) || (prompt>11)))
           {
               cout<<"Please enter "<<coordinates[i][j]<<" "<<flush;
               cin>>prompt;
           }
           if( prompt == 10 ) {
                readSeed();
                for( int k(0); k < puzzlesize; k++ ) {
                    for( int l(0); l < puzzlesize; l++ ) {
                        solvedpuzzle[k][l] = rand() % puzzlesize + 1;
                    }
                }
                system("CLS");
                cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
                cout<<"Please enter your completed sudoku."<<endl;
                cout<<"Enter all blanks as zeros (0) and separate inputs by a space."<<endl;
                cout << "Enter 10, random values fill the puzzle; enter 11, create a valid puzzle." << endl;
                cout << endl;
                input(solvedpuzzle);
                dobreak = true;
                break;
            } else if( prompt == 11 ) {
                int counter(0);
                for( int k(0); k < puzzlesize; k++ ) {
                    counter += 3;
                    for( int l(0); l < puzzlesize; l++ ) {
                        if( counter % 39 == 0 ) counter = 2;
                        if( counter % 38 == 0 ) counter = 1;
                        counter++;
                        solvedpuzzle[k][l] = counter % 9 + 1;
                    }
                }
                system("CLS");
                cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
                cout<<"Please enter the given values in the sudoku puzzle."<<endl;
                cout<<"Enter all blanks as zeros (0) and separate inputs by a space."<<endl;
                cout << "Enter 10, random values fill the puzzle; enter 11, create a valid puzzle." << endl;
                cout << endl;
                input(solvedpuzzle);
                dobreak = true;
                break;
            } else {
                solvedpuzzle[i][j]=prompt;
            }
           
           system("CLS");
       }       
    }

//      Transfer the entered values into proper classes to analyze
RowNColumn r1, r2, r3, r4, r5, r6, r7, r8, r9;
RowNColumn c1, c2, c3, c4, c5, c6, c7, c8, c9;
ThreeByThree t1, t2, t3, t4, t5, t6, t7, t8, t9;

//      Populate the row class

populate(r1, solvedpuzzle, 0, 10);
populate(r2, solvedpuzzle, 1, 10);
populate(r3, solvedpuzzle, 2, 10);
populate(r4, solvedpuzzle, 3, 10);
populate(r5, solvedpuzzle, 4, 10);
populate(r6, solvedpuzzle, 5, 10);
populate(r7, solvedpuzzle, 6, 10);
populate(r8, solvedpuzzle, 7, 10);
populate(r9, solvedpuzzle, 8, 10);

//      Populate the Column class

populate(c1, solvedpuzzle, 0, 0);
populate(c2, solvedpuzzle, 0, 1);
populate(c3, solvedpuzzle, 0, 2);
populate(c4, solvedpuzzle, 0, 3);
populate(c5, solvedpuzzle, 0, 4);
populate(c6, solvedpuzzle, 0, 5);
populate(c7, solvedpuzzle, 0, 6);
populate(c8, solvedpuzzle, 0, 7);
populate(c9, solvedpuzzle, 0, 8);

//      Populate the three by three class
populate(t1, solvedpuzzle, 0, 0);
populate(t2, solvedpuzzle, 3, 0);
populate(t3, solvedpuzzle, 6, 0);
populate(t4, solvedpuzzle, 0, 3);
populate(t5, solvedpuzzle, 3, 3);
populate(t6, solvedpuzzle, 6, 0);
populate(t7, solvedpuzzle, 0, 6);
populate(t8, solvedpuzzle, 3, 6);
populate(t9, solvedpuzzle, 6, 6);

//  Test variables
bool rowstest;
bool columnstest;
bool squarestest;

//  Test if Sudoku entered is correct
if(r1.test() && (r2.test()) && r3.test() && r4.test() && r5.test() && r6.test() && r7.test() && r8.test() && r9.test())
{
    rowstest=true;
}
else
{
    rowstest=false;
}

if(c1.test() && c2.test() && c3.test() && c4.test() && c5.test() && c6.test() && c7.test() && c8.test() && c9.test())
{
    columnstest=true;
}
else
{
    columnstest=false;
}

if(t1.test() && t2.test() && t3.test() && t4.test() && t5.test() && t6.test() && t7.test() && t8.test() && t9.test())
{
    squarestest=true;
}
else
{
    squarestest=false;
}

//  Final Result
if(rowstest && columnstest && squarestest)
{
    cout<<"Congratulations! You have solved the puzzle!"<<endl;
    //  Maybe retrieve their solution from file here
}
else
{
    cout<<"You DEFINETLY have an error in your solution!"<<endl;
    //  Maybe this is where you could use my intermediate variables to narro it down to where it is
}

    system("PAUSE");
    return 0;
}

