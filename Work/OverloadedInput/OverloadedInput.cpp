//
//  Program to give the total for an investment, over some years at an interest rate.
//
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

//  Validator for doubles
void inputValidator( const string& instructions, double min, double max, double& input ){
    /*  Variables  */
    double temp;
    
    cout << instructions;
    cin >> temp;
    while( !( temp > min && temp < max)) {
        cout << "Try Again!:";
        cin >> temp;
    }
    input = temp;
    
    return;
}

//  Validator for integers
void inputValidator( const string& instructions, int min, int max, int& input ){
    /*  Variables  */
    int temp;
    
    cout << instructions;
    cin >> temp;
    while( !( temp > min && temp < max)) {
        cout << "Try Again!:";
        cin >> temp;
    }
    input = temp;
    
    return;
}

//  Interest Function
double compoundInterest( double dollars, double interestRate, int years, int compoundings ){
    return dollars * pow((1 + (interestRate / 100 / compoundings)),(compoundings * years));
//  The formula for interest compounded monthly is: A = P(1+r/12)^(12*t).  In the context of this program, that is: final = dollar * (1 + (interest / compoundings))^(compoundings * years);
}

int main()
{
    /*  Variables  */
    double dollars;
    double interest;
    int years;
    const double dollars_LowerBound(0);
    const double dollars_UpperBound(2147483646);
    const double interest_LowerBound(0);
    const double interest_UpperBound(100);
    const int years_UpperBound(60);
    const int years_LowerBound(2);
    const int compoundings(12);
    
    /*  Header  */
    cout << "-- Output the total for an investment, over some years at an interest rate --" << endl << endl;
    
    /*  Prompts and Calculations  */
    inputValidator( "Enter the principal amount (example: 1000.34 dollars) ", dollars_LowerBound, dollars_UpperBound, dollars );
    inputValidator( "Enter the yearly interest rate (example: 7.275%) ", interest_LowerBound, interest_UpperBound, interest );
    inputValidator( "Enter the number of years (example: 10) ", years_LowerBound, years_UpperBound, years );
    double final = compoundInterest( dollars, interest, years, compoundings );
    
    /*  Output  */
    cout << endl << endl;
    cout.precision(2);
    cout.setf(ios::fixed,ios::floatfield); 
    cout << "After " << years << " years have passed, " << dollars << " dollars invested at " << interest << "% interest," << endl;
    cout << "gives you " << final << " dollars." << endl << endl << endl << endl;

    system("PAUSE");
    return 0;
}
