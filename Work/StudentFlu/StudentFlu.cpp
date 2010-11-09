//
//  The main routine for a flu stage simulation program
//
#include <iostream>
#include <cstdlib>

#include "Student.h"

//using namespace std;

int readSeed();

int main()
{
    /*  Header  */
    cout << " -- Simulator for the flu stages of two students --";
    cout << endl << endl;
    
    /*  rand() seed  */
    srand( readSeed() );
    cout << endl << endl << endl;

    /*  Variables  */
    int countdown( 1 + rand() % 20 );
    Student fluStudent( countdown );
    Student wellStudent( 0 );
    int sickHours(0);
    int iterations(160);
    
    
    /*  Simulation Loop  */
    for( int i(0); i < iterations; i++) {
        // fluStudent
        if( fluStudent.getStatus() == 'S' || fluStudent.getStatus() == 'H' ) sickHours++;
        if( fluStudent.nextHour() == true ) {
            cout << "fluStudent change: ";
            fluStudent.output( cout );
        }
        // wellStudent
        if( wellStudent.getStatus() == 'S' || wellStudent.getStatus() == 'H' ) sickHours++;
        if( wellStudent.nextHour() == true ) {
            cout << "wellStudent change: ";
            wellStudent.output( cout );
        }
        // Handles the chances the well student becomes sick
        if( fluStudent.getStatus() == 'I' && wellStudent.getStatus() == 'U' ) {
            if( wellStudent.catchFlu() ) {
                cout << "wellStudent change: ";
             wellStudent.output( cout );
            }
        }
    }
    
    cout << endl << endl << "Amount of sick time: " << sickHours << " hours" << endl << endl << endl << endl;
    
    system("PAUSE");
    return 0;
}

int readSeed() {
    /*  Variables  */
    int n;

    /*  Seed Prompt  */
    cout << "What would you like the seed for rand() to be? (If 0, use wall clock)" << endl;
    cin >> n;
    if( n == 0 ) {
        n = unsigned(time(0));
    }
    
    return n;
}
