//
//  Implementation file for Student class
//
#include <iostream>
#include <cstdlib>

#include "Student.h"

using namespace std;

//  Student ctor implementation
Student::Student( )
{
    status = UNINFECTED;
    status_hours = getDuration();
    for( int d=0; d<DAYS; d++ ) {
        block_schedule(d);
    shuffle_schedule(d);
    }
    location = BUILDINGS + COMMONS;  //  Bogus value
}

//  nextHour function, advances status hours and status
bool Student::nextHour( ) 
{
    if( getDuration() == 0 ) return false;
    if( --status_hours == 0 ) {
        status++;
        status_hours = getDuration();
        return true;
    }
    return false;
}

//  catchFlu function, handles the chances a 'U' gets the flu
bool Student::catchFlu( )
{
    /*  Variables  */
    const int RESOLUTION = 10000;
    const int INFECTIOUS_HOURS = 52;
    
    if( status = 'U' ) {
        if( rand() % RESOLUTION / double(RESOLUTION) < 0.05 ) {
            status_hours = INFECTIOUS_HOURS; // Default infectious time
            status = 'I';
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

//  ouptut function, outputs the status_hours and status using a method give
ostream& Student::output( ostream& os ) const
{
    string statusNames[STAGES] = {"Infectious", "Symptomatic", "Home", "Cured", "Uninfected"};
    os << status << " - " << statusNames[status] << endl;
    return os;
}
//  status accessor function
int Student::getStatus( ) const 
{
    return status;
}

// status_hours accessor function
int Student::getStatus_Hours(  ) const 
{
    return status_hours;
}

void Student::setStatus( const int theStatus )
{
    status = theStatus;
    status_hours = getDuration();
}

//
void Student::block_schedule( const int dayIndex )
{
    for( int h(0); h < LECTURES; h++ ) {
        schedule[dayIndex][h] = rand() % BUILDINGS;
    }
    for( int h(LECTURES); h < HOURS; h++ ) {
        schedule[dayIndex][h] = BUILDINGS;
    }
}

//
void Student::shuffle_schedule( const int dayIndex )
{
    /*  Variables  */
    int hold;
    int chosen;
    int counter(HOURS);

    /*  Shuffle using FisherYates method  */
    for( int i(0); i < counter; i++ ) {
        chosen = rand() % (HOURS - i);
        hold = schedule[dayIndex][counter - 1 - i];
        schedule[dayIndex][counter - 1 - i] = schedule[dayIndex][chosen];
        schedule[dayIndex][chosen] = hold;
    }
}

//
void updateLocation( const int dayIndex, const int hour )
{
    if( schedule[dayIndex][hour] < BUILDINGS ) 
    {
        location = schedule[dayIndex][hour];
    } else {
        location = BUILDINGS + rand() % COMMONS;
    }
}

// 
int Student::getDuration() const
{
    // duration (in hours) of each flu stage --- 0 means the 
    // the flu stage is exited due to an event, not a passage of time
    const int DURATIONS[] = { 52, 32, 48, 0, 0 };
    return DURATIONS[status];
}

