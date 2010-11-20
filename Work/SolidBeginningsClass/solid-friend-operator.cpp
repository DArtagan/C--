//
//  The main routine for a program that tests the solid class and its operators
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <iomanip>

#include "Solid.h"

using namespace std;

int main()
{
    //  Header
    cout << " -- SolidBeginningsClass Tester --" << endl << endl << endl;
    
    //  Creates a unit solid
    Solid onesolid;
    if( onesolid.getHeight() == 1 && onesolid.getSideLength() == 1) {  // test that the unit solid is a unit solid
        cout << "onesolid is indeed a unit solid" << endl;
    } else {
        cout << "onesolid is not a unit solid" << endl;
    }
    cout << endl;
    
    //  Attempts to create a invalid solid, 
    Solid twosolid( 0, -500 );
    if( twosolid.getHeight() == 1 && twosolid.getSideLength() == 1) {
        cout << "twosolid is now a unit solid" << endl;
    } else {
        cout << "twosolid is not a unit solid" << endl;
    }
    cout << endl;
    
    //  Create to specific Solids
    Solid threesolid( 100, 100 );
    Solid foursolid( 100, 100 );
    
    // counter for how many times the loop runs
    int counter(0);
    
    while( threesolid <= foursolid && !((foursolid <= onesolid))) {
        counter++;
        threesolid = threesolid * .5;  // Cut the dimensions of threesolid in half
        foursolid = foursolid - onesolid;  // Decrease foursolid by one
        cout.setf( ios::left );
        cout.precision(4);
        cout.setf( ios::fixed ); 
        cout << "Volumes:  threesolid= " <<threesolid.volume() << "  ";  // Output each solid
        cout << "foursolid= " << foursolid.volume() << "  ";
        cout << "onesolid= " << onesolid.volume();
        cout << endl;
    }
    
    // Output how many times the loop ran
    cout << endl << "The loop ran " << counter << " times." << endl;

    system("PAUSE");
    //  Exit program.
    return 0;
}
