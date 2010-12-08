#include <cstdlib>
#include <iostream>
#include "RowNColumn.h"
#include "ThreeByThree.h"
#include <string>

using namespace std;
//      Input interface
void input(int counter, RowNColumn& inputrow)
{
    RowNColumn tempinput;
    string lineout("============================");
    string spacerout("|  |  |  |  |  |  |  |  |  |");
    
    for(int i = 0; i<9;i++)
    {
        cout<<lineout<<endl;
        cout<<spacerout<<endl;
        
        if(i==counter)
        {
            /*cin>>tempinput;
            
            if(!tempinput)
            {
                cout<<"Error reading input. Make sure to enter integer values"<<endl;
                cout<<"separated by spaces."<<endl;
                break;
            }
            else
            {
                inputrow=tempinput;
            }
            */
        }

    }
}

//      Sudoku Checker main routine

int main()
{
    //  Initialize variables
    const int puzzlesize(9);
    RowNColumn ArrayOfRowsGiven[puzzlesize];
    RowNColumn ArrayOfRowsSolved[puzzlesize];
    int counter(0);
    int threshold(9);

    //  Prompt the user for input of the known numbers
    
    cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
    cout<<"Please enter the given values in the sudoku puzzle."<<endl;
    cout<<"Enter all blanks as zeros (0) and separatte inputs by a space."<<endl;
    
    for(int i =0; i<threshold;i++)
    {
        input(counter,ArrayOfRowsGiven[i]);
        counter++;
    }
    
    counter  =0;
    
    system("CLS");
    
    cout<<"++++++++++++Sudoku Checker+++++++++++++"<<endl<<endl;
    cout<<"Please enter your completed sudoku."<<endl;
    cout<<"Enter all blanks as zeros (0) and separate inputs by a space."<<endl;
    
    for(int i =0; i<threshold;i++)
    {
        input(counter,ArrayOfRowsSolved[i]);
        counter++;
    }
        

    
    
    
    
    system("PAUSE");
    return 0;
}
