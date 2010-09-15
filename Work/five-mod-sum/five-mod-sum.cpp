//
//  Program to find the sum of all the numbers between 1 and n (user defined), not divisible by the first 5 prime numbers (2,3,5,7,11).
//
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    int n;
    int value = 1;
    int sum = 0;
    int counter = 0;
    
    /*  Ask for final value  */
    cout << "-- Find the sum of all the numbers between 1 and n, not divisible by the first 5 prime numbers --" << endl << endl;
    cout << "Enter a final value (n): " << flush;
    cin >> n; 
    cout << endl;
    
    /*  Loop to find all numbers  */
    while (!(value == (n+1))) {
        if (!(0 == value % 2 || 0 == value % 3 || 0 == value % 5 || 0 == value % 7 || 0 == value % 11)) {
            sum += value;
            counter++;
        }
        value++;
    }

    /*  Display Results with guiding text  */
    cout << endl;
    cout << "There are " << counter << " numbers not divisible by the first 5 prime numbers (2, 3, 5, 7, 11).  They all add up to " << sum << ".";
    cout << endl << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}
