//
//  The main routine for flu simulation program
//
#include <iostream>
#include <cstdlib>


#include "Student.h"

//using namespace std;

int readSeed();

int main()
{
    srand( readSeed() );

    /*  Variables  */
    int countdown( 1 + rand() % 20 );
    Student fluStudent( countdown );
    Student wellStudent( 0 );
    int sickHours(0);
    int iterations(160);
    
    /*    */
    for( int i(0); i < iterations; i++) {
        fluStudent.output( ostream& os );
    }
    
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
