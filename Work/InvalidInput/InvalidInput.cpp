//
//  Program to give the total for an investment, over some years at an interest rate.
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
    const double interest_UpperBound = 100;
    const int years_UppperBound = 60;
    const int years_LowerBound = 2;
    const int compoundings = 12;
    
    /*  Prompt for variable value  */
    cout << "-- Output the total for an investment, over some years at an interest rate. --" << endl << endl;
    cout << "Enter the initial dollar amount (it must be greater than 0): " << flush;
    cin >> dollar;
    cout << "Enter the interest rate (between 0 and 100 percent): " << flush;
    cin >> interest;
    cout << "Enter the years to let the program run for (between 2 and 60): " << flush;
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
    } else if (!(interest > 0 && interest < interest_UpperBound)) {
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
    } else if (!(years >= years_LowerBound && years <= years_UppperBound)) {
        cout << "For this program, the years can be any whole number from 2 to 60." << endl;
        cout << "Please, input a valid number of years: " << flush;
        cin >> years;   
        cout << endl;
        if (!(years >= years_LowerBound && years <= years_UppperBound)) {
            cout << "Once again your year was not any of whole nubmer from 2 to 60." << endl;
            cout << "Banking is for the educated classes.  I bid you good day." << endl;
            cout << endl << endl << endl;
            system("PAUSE");
            //  Exit Program
            return 0;
        }
    }
        
    /*  Calculate the amount after time */
    //  The formula for interest compounded monthly is: A = P(1+r/12)^(12*t).  In the context of this program, that is: final = dollar * (1 + (interest / compoundings))^(compoundings * years);
    interest = interest / 100;
    final = dollar * pow((1 + (interest / compoundings)),(compoundings * years));
    
    /*  Output the final dollar amount with other guiding information  */
    cout << endl;
    cout << "After time has passed, " << dollar << " dollars invested at " << 100 * interest << " percent interest for " << years << " years," << endl;
    cout << " gives you " << final << " dollars after that time has passed.";
    cout << endl << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}
