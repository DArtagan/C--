//
//  Main routine for a program that retrieves and saves player details using classes
//
#include <cstdlib>
#include <iostream>

#include "Player.h"

using namespace std;

int main()
{
    /*  Variables  */
    Player test;
    char i = 'n';
    string temp;
    int otherTemp;
    
    /*  Header  */
    cout << "  -- Player Information Holder --";
    cout << endl << endl;
    
    while( i == 'n' ) {
        //  Output current status
        cout << "The current player's details are:" << endl;
        cout << "First name: " << test.getFirstName() << endl;  // Get firstName
        cout << "Last name: " << test.getLastName() << endl;  // Get lastName
        cout << "Age: " << test.getAge() << endl;  // Get age
        cout << "Hometown: " << test.getHometown() << endl << endl;  // get hometown
        //  Verify accuracy
        cout << "Is all of this information correct (y/n)? " << flush;
        cin >> i;
        cout << endl << endl;
        //  If inaccurate, prompt for new values
        if( i == 'n' ) {
            cout << "Input the player's new details:" << endl;
            cout << "First name: " << flush;
            cin >> temp; 
            test.setFirstName( temp );  // set firstName
            cout << "Last name: " << flush;
            cin >> temp; 
            test.setLastName( temp );  // set lastName
            cout << "Age: " << flush;
            cin >> otherTemp; 
            test.setAge( otherTemp );  // set age
            cout << "Hometown: " << flush;
            getline(cin, temp, '\n');
            getline(cin, temp, '\n');
            test.setHometown( temp );  // set hometown
            cout << endl << endl << endl;
        }
    }
    
    system("PAUSE");
    return 0;
}
