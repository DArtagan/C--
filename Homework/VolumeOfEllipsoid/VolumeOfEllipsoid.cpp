//
//  Compute the volume of an ellipsoid does this program
//
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

/* (4/3)pi(abc) */

int main()
{
    /*  Declare and initialize objects */
    double pi = acos(-1);
    double length = 2;
    double width = 2;
    double height = 2;
    double volume;
    
    /*  Calculates volume using: (4/3)pi(length*width*height)/2 */
    volume = (4/3) * pi * length * width * height / 2;
    /*  Print the volume. */
    cout << "The volume is  " <<  volume ;
    cout << " units cubed." << endl;
    
    system("PAUSE");
    //  Exit program.
    return 0;
}
