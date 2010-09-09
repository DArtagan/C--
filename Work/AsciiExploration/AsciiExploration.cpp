//
//  Program to compare 3 boolean variables and determine if the value of the following condition is true of false: ! (a&&b&&c) && !(a||b||c)
//
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    char charVar;
    
    /*  Prompt for variable value  */
    cout << "-- Display the ASCII code for a character --" << endl << endl;
    cout << "Enter a character: " << flush;
    cin >> charVar;
        
    /*  Out put code with character and state what kind of character it is.  */
    cout << endl << endl;
    cout << "The ASCII code of " << charVar << " is " << int(charVar) << ".  ";
    if (charVar >= '0' && charVar <= '9') {
        cout << charVar << " is a digit." << endl;
    } else if (charVar >= 'A' && charVar <= 'Z') {
        cout << charVar << " is an upper-case letter." << endl;
    } else if (charVar >= 'a' && charVar <= 'z') {
        cout << charVar << " is a lower-case letter." << endl;
    } else {
        cout << charVar << " is not an upper-case, lower-case, or digit." << endl;
    }
    cout << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}
