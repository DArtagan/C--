//
//  File to read user input for the rand() seed, has wallclock option
//
#include "WeekSchedule.h"

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
