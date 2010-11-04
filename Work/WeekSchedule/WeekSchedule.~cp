//
//  Simulator of a student's schedule, the locations they'd be in
//
#include "WeekSchedule.h"

int main()
{
    /*  Repeat Loop Head  */
    char repeater('0');
    while( repeater == '0') {

    /*  Constants  */
    // Locations
    const int BUILDINGS(6), CTLM(0), MEYER_HALL(1), COOLBAUGH_HALL(2), GREEN_CENTER(3), BERTHOUD_HALL(4), BROWN_HALL(5);
    const string BNAMES[] = { "CTLM", "Meyer Hall", "Coolbaugh Hall", "Green Center", "Berthoud Hall", "Brown Hall", "Free Time" };
    const string LNAMES[] = { "CTLM", "Meyer Hall", "Coolbaugh Hall", "Green Center", "Berthoud Hall", "Brown Hall", "Kafadar", "Library", "Student Center", "Rec Center" };
    // Commons
    const int COMMONS(4), KAFADAR(0), LIBRARY(1), STUDENT_CENTER(2), REC_CENTER(3);
    // Time Specifications
    const int DAYS(2);
    const int HOURS(8);
    const int SIMWEEKS = 2;
    const int DAYS_IN_WEEK = 7;
    const int SATURDAY = 5;
    const string DNAMES[] = { "Monday, Wednesday, Friday", "Tues, Thursday" };
    //  Other Details
    const int LECTURES(5);
    const int FREE_BLOCK(BUILDINGS);

    /*  Variables  */
    int schedule[DAYS][HOURS];
    int locationCount[BUILDINGS + COMMONS] = {};
    
    /*  Header  */
    cout << "-- Schedule Simulator and Such --" << endl << endl;
    srand(readSeed());
    
    /*  Schedule Generator  */
    for(int i(0); i < DAYS; i++) {
        blocking( schedule[i], HOURS, BUILDINGS, LECTURES );
        shuffler( schedule[i], HOURS );
    }
    
    /*  Simulate Multiple Weeks  */
    for( int d(0); d < SIMWEEKS * DAYS_IN_WEEK; d++ ) {
        if( d % DAYS_IN_WEEK < SATURDAY ) { // not the weekend
            for( int h(0); h < HOURS; h++ ) {
                int b = schedule[d % DAYS_IN_WEEK % DAYS][h]; // reduce d to either 0 or 1 (MWF or TR)
                if( b == FREE_BLOCK ) {
                    // Pick a random common area
                    int c = rand() % COMMONS;  // choose one at random
                    // add it to the count
                    locationCount[BUILDINGS + c]++;
                } else {
                    // in a building
                    locationCount[b]++;
                }
            }
        }
    }

    /*  Footer  */
    cout << endl;
    for( int d(0); d < DAYS; d++ ) {
        cout << DNAMES[d] << ": " << endl;
        for( int h(0); h < HOURS; h++ ) {
            cout << BNAMES[ schedule[d][h] ] << endl;
        }
        cout << endl << endl;
    }
    cout << endl << endl;
    for( int i(0); i < COMMONS + BUILDINGS; i++ ) {
        cout << LNAMES[i] << ": " << locationCount[i] << endl;
    }
    cout << endl << endl << endl << endl;
    
    /*  Repeat Loop Foot  */
    repeater = '2';
    while( repeater != '0' && repeater != '1') {
    cout << "0 to continue, 1 to quit." << endl;
    cin >> repeater;
    }
    cout << endl << endl;
    }

    system("PAUSE");
    return 0;
}
