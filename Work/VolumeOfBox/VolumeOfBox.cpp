//
//  This program computes the volume of a box
//
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    /*  Declare and initialize objects */
    double length(20.75), width(11.5);
    double height = 9.5;
    double volume;
    
    /*  Calculate volume as length times width times height. */
    volume = length * width * height;
    /*  Print the volume. */
    cout << "The volume is  " <<  volume ;
    cout << " units cubed." << endl;
    
    system("PAUSE");
    //  Exit program.
    return 0;
}
