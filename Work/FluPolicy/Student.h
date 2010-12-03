//
//  Student class header file
//
#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

class Student {
public:
/*  Class Type Declaration  */
    Student( );
    Student( int contagious_countdown );
/*  Constants  */
//  Sickness Status Constants
    static const int INFECTIOUS=0;
    static const int SYMPTOMATIC=1;
    static const int HOME=2;
    static const int CURED=3;
    static const int UNINFECTED=4;
    static const int VACCINATED=5;
    static const int STAGES=6;
//  Schedule Constants
    //  Time
    static const int DAYS=2;
    static const int HOURS=8;
    static const int LECTURES=5;
    //  Location, Classes
    static const int CTLM = 0;
    static const int MEYER_HALL = 1;
    static const int COOLBAUGH_HALL = 2;
    static const int GREEN_CENTER = 3;
    static const int BERTHOUD_HALL = 4;
    static const int BROWN_HALL = 5 ;
    static const int BUILDINGS = 6;
    //  Location, Off
    static const int KAFADAR = 0;
    static const int LIBRARY = 1;
    static const int STUDENT_CENTER = 2;
    static const int REC_CENTER = 3;
    static const int COMMONS = 4;

/*  Functions  */
    //  Advances status_hours and status
    bool nextHour( );
    //  Handles the possibility of a 'U' becoming an 'I'
    bool catchFlu( const int locationCounts[], const int filterLocation );
    ostream& output( ostream& os ) const;
    //  accessor function to get the status
    int getStatus( ) const;
    //  accessor function to get the status_hours
    int getStatus_Hours(  ) const;
    //  accessor function to set the status
    void setStatus( const int theStatus );
    //  Update the Location
    void updateLocation( const int dayIndex, const int hour );
    //  accessor to return the location
    int getLocation( ) const;
    //  accessor to return whether their infectious
    bool isInfectious() const;
    //  function for vaccinating students
    bool vaccinate();
private:
/*  Helper Functions  */
    //  Create a random schedule
	void block_schedule( const int dayIndex );
	//  Shuffle the schedule using FisherYates
    void shuffle_schedule( const int dayIndex );
    //  get the duration for the current status
    int getDuration() const;

/*  Data Members  */
    int status;
    int status_hours;
    int schedule[DAYS][HOURS];
    int location;
};
