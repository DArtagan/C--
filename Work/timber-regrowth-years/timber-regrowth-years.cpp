//
//  Program to find how many prime numbers there are from 3 to a user defined 'n', and what the largest prime number therein is.
//
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    double forested = 2500;
    const double rate = .02;
    int years;
    
    /*  Ask for final value  */
    cout << "--  --" << endl << endl;
    cout << "Number of years to make table for: " << flush;
    cin >> years;
    cout << endl;
    
    /*  Loop to find all prime numbers  */
    for (int i = 1; i <= years; i++) {
        forested = (forested + forested * rate);
        cout << "Year = " << i << " Acres = " << forested << endl;
    }

    /*  Display Results with Guiding Text  */
    cout << endl;
    cout << endl;
    cout << endl << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}
