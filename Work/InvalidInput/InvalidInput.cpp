//
//  Program to output an ASCII code for a given character, and state what kind of character it is.
//
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    double dollar;
    double interest;
    int years;
    double final;
    
    /*  Prompt for variable value  */
    cout << "-- Display the ASCII code for a character --" << endl << endl;
    cout << "Enter a character: " << flush;
    cin >> dollar;
    cin >> interest;
    cin >> years;
    cout << endl;
    
    /*  Validate Variable Inputs  */
    if (dollar  <= 0) {
        cout << "The dollar value input must be greater than 0." << endl;
        cout << "Input a dollar amount greater than zero: " << flush;
        cin >> dollar;   
        cout << endl;
        if (dollar <= 0) {
            cout << "Once again your dollar amount was not greater than zero." << endl;
            cout << "If you can't follow directions, I can't help you.  Good day." << endl;
            cout << endl << endl << endl;
            system("PAUSE");
            //  Exit Program
            return 0;
        }
    } else if (!(interest > 0 && interest < 100)) {
        cout << "The given interest rate must be greater than 0% and less than 100%." << endl;
        cout << "Please, input a valid interest rate: " << flush;
        cin >> interest;   
        cout << endl;
        if (!(interest > 0 && interest < 100)) {
            cout << "Again your interest rate was not between 0% and 100%." << endl;
            cout << "If you can't follow simple instructions, this is not the program for you.";
            cout << endl <<  "Adieu." << endl;
            cout << endl << endl << endl;
            system("PAUSE");
            //  Exit Program
            return 0;
        }
    } else if (!(years >= 2 && years <= 60)) {
        cout << "For this program, the years can be any whole number from 2 to 60." << endl;
        cout << "Please, input a valid number of years: " << flush;
        cin >> dollar;   
        cout << endl;
        if (!(years >= 2 && years <= 60)) {
            cout << "Once again your year was not any of whole nubmer from 2 to 60." << endl;
            cout << "Banking is for the educated classes.  I bid you good day." << endl;
            cout << endl << endl << endl;
            system("PAUSE");
            //  Exit Program
            return 0;
        }
    }
        
    /*  Calculate the amount after time */
    // A= P(1+r/n)^(nt)
    
    /*  Output ASCII code with character, and state what kind of character it is.  */
    cout << endl << endl;
    cout << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}
