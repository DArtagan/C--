//
//  Compute the volume of an ellipsoid does this program
//
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    /*  Declare dimensions */
    double pi = acos(-1);
    double length = 4;
    double width = 8;
    double height = 12;
    double volume;
    
    /*  Calculates volume using: (4/3)pi(length/2*width/2*height/2) */
    volume = (4.0/3) * pi * length / 2 * width / 2 * height / 2;
    /*  Prints the volume */
    cout << "The volume is  " <<  volume ;
    cout << " units cubed." << endl;
    
    system("PAUSE");
    //  Exit program.
    return 0;
}
