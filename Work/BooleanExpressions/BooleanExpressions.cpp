//
//  Program to compare 3 boolean variables and determine if the value of the following condition is true of false: ! (a&&b&&c) && !(a||b||c)
//
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    bool a;
    bool b;
    bool c;
    bool R;
    
    /*  Prompt for variables  */
    cout << "-- Determine if !(a&&b&&c) && !(a||b||c) is True or False --" << endl << endl;
    cout << "Enter boolean values (0 or 1) for:" << endl;
    cout << "a: " << flush;
    cin >> a;
    cout << "b: " << flush;
    cin >> b;
    cout << "c: " << flush;
    cin >> c;
    
    /*  Evaluation  */
    R = !(a&&b&&c) && !(a||b||c);
        
    /*  Output result with guiding text  */
    cout << endl << endl;
    if (R == 1) {
        cout << "!(a && b && c) && !(a || b || c) for a=" << a << " b=" << b << " c=" << c << " is " << R <<".  The condition is true.";
    } else {
        cout << "!(a && b && c) && !(a || b || c) for a=" << a << " b=" << b << " c=" << c << " is " << R <<".  The condition is false.";
    }
    cout << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}
