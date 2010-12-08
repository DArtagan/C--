#include <cstdlib>
#include <iostream>
#include <string>

#include "RowNColumn.h"
#include "ThreeByThree.h"

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
   
    cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
    cout<<"Please enter the given values in the sudoku puzzle."<<endl;
    cout<<"Enter all blanks as zeros (0) and separatte inputs by a space."<<endl;
   
   
   
    for(int i=0; i<puzzlesize; i++)
    {
       for(int j=0; j<puzzlesize; j++)
       {
           cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
           cout<<"Please enter the given values in the sudoku puzzle."<<endl;
           cout<<"Enter all blanks as zeros (0) and separate inputs by a space."<<endl;
           input(givenpuzzle);
           cout<<"Please enter "<<coordinates[i][j]<<" "<<flush;
           //  Proofreading the input
           cin>>prompt;
           while(((prompt<0) || (prompt>9)))
           {
               cout<<"Please enter "<<coordinates[i][j]<<" "<<flush;
               cin>>prompt;
           }
           
           givenpuzzle[i][j]=prompt;
           
           system("CLS");
       }       
    }
   
   
    system("PAUSE");
    system("CLS");
   
//      Prompt User for their solved puzzle

       for(int i=0; i<puzzlesize; i++)
    {
       for(int j=0; j<puzzlesize; j++)
       {
           cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
           cout<<"Please enter your completed sudoku."<<endl;
           cout<<"Enter all blanks as zeros (0) and separate inputs by a space."<<endl;
           input(solvedpuzzle);
           cout<<"Please enter "<<coordinates[i][j]<<" "<<flush;
           //  Proofreading the input
           cin>>prompt;
           while(((prompt<0) || (prompt>9)))
           {
               cout<<"Please enter "<<coordinates[i][j]<<" "<<flush;
               cin>>prompt;
           }
           
           solvedpuzzle[i][j]=prompt;
           
           system("CLS");
       }       
    }

//      Transfer the entered values into proper classes to analyze
RowNColumn r1, r2, r3, r4, r5, r6, r7, r8, r9;
RowNColumn c1, c2, c3, c4, c5, c6, c7, c8, c9;
ThreeByThree t1, t2, t3, t4, t5, t6, t7, t8, t9;

cin >> r1;


//      Populate the row classes
/*for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[0][i] >> r1;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[1][i]>>r2;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[2][i]>>r3;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[3][i]>>r4;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[4][i]>>r5;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[5][i]>>r6;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[6][i]>>r7;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[7][i]>>r8;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[8][i]>>r9;
}

//      Populate the column class
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[i][0]>>c1;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[i][1]>>c2;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[i][2]>>c3;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[i][3]>>c4;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[i][4]>>c5;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[i][5]>>c6;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[i][6]>>c7;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[i][7]>>c8;
}
for(int i = 0; i<puzzlesize; i++)
{
    solvedpuzzle[i][8]>>c9;
}

//      Populate the three by three class

for(int i=0; i<3; i++)
{
    for(int j=0;j<3;j++)
    {
       solvedpuzzle[i][j]>>t1;
    }
}
for(int i=3; i<6; i++)
{
    for(int j=0;j<3;j++)
    {
       solvedpuzzle[i][j]>>t2;
    }
}
for(int i=6; i<9; i++)
{
    for(int j=0;j<3;j++)
    {
       solvedpuzzle[i][j]>>t3;
    }
}
for(int i=0; i<3; i++)
{
    for(int j=3;j<6;j++)
    {
       solvedpuzzle[i][j]>>t4;
    }
}
for(int i=3; i<6; i++)
{
    for(int j=3;j<6;j++)
    {
       solvedpuzzle[i][j]>>t5;
    }
}
for(int i=6; i<9; i++)
{
    for(int j=3;j<6;j++)
    {
       solvedpuzzle[i][j]>>t6;
    }
}
for(int i=0; i<3; i++)
{
    for(int j=6;j<9;j++)
    {
       solvedpuzzle[i][j]>>t7;
    }
}
for(int i=3; i<6; i++)
{
    for(int j=6;j<9;j++)
    {
       solvedpuzzle[i][j]>>t8;
    }
}
for(int i=6; i<9; i++)
{
    for(int j=6;j<9;j++)
    {
       solvedpuzzle[i][j]>>t9;
    }
}     */

    system("PAUSE");
    return 0;
}

