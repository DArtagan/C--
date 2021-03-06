//
//  Timber regrowth by year table for a user defined number of years
//
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    double forested = 2500;
    const double rate = .02;
    int years;
    
    /*  Ask for final year  */
    cout << "-- Timber Regrowth Rates --" << endl << endl;
    cout << "Number of years to make table for: " << flush;
    cin >> years;
    cout << endl;
    
    /*  Loop to form table  */
    //  Acres Forested = Prior number of forested acres + Prior number of forested acres * reforestation rate.
    for (int i = 1; i <= years; i++) {
        forested = (forested + forested * rate);
        cout << "Year = " << i << " Acres = " << forested << endl;
    }

    /*  Closing  */
    cout << endl << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}
