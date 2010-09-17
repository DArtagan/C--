//
//  Program to find how many prime numbers there are from 3 to a user defined 'n', and what the largest prime number therein is.
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    int n;
    int counter(0);
    int largest;
    bool valid = true;
    
    /*  Ask for final value  */
    cout << "-- How Many Prime Numbers are There from 3 to 'n', and What is the Largest? --" << endl << endl;
    cout << "Enter a final value (n): " << flush;
    cin >> n; 
    cout << endl;
    
    /*  Loop to find all prime numbers  */
    for (int p(3); p <= n; p++) {
        for (int f(2); f < p; f++) {
            if (0 == (p % f)) {
                valid = false;
                break;
            }
        }
        if (valid == true) {
            counter++;
            largest = p;
        }
        valid = true;
    }   

    /*  Display Results with Guiding Text  */
    cout << endl;
    cout << "There are " << counter << " prime numbers between 3 and " << n << endl;
    cout << "The largest prime number was " << largest;
    cout << endl << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}
