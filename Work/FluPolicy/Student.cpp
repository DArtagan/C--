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
    status = UNINFECTED;  // Students are UNINFECTED naturally
    status_hours = Student::getDuration();  // Get the number of hours for this status by using the status as a parameter
    for( int d=0; d < DAYS; d++ ) {  // For each day 
        block_schedule(d);  // Create a random schedule
        shuffle_schedule(d);  // and Shuffle that schedule
    }
    location = BUILDINGS + COMMONS;  //  Bogus value
}

//  nextHour function, advances status hours and status
bool Student::nextHour( ) 
{
    if( Student::getDuration() == 0 ) return false;  // If the status does not depend on the hour, return false
    if( --status_hours == 0 ) {  // If after subtracting one the hour counter is zero
        status++;  // Add one to the status
        status_hours = Student::getDuration();  // Get the status_hours counter using the status
        return true;  // This function did something
    }
    return false;  // Though status_hours detracted one, nothing else happened
}

//  catchFlu function, handles the chances an UNINFECTED student gets the flu
bool Student::catchFlu( const int locationCounts[], int filterLocation )
{
    const int RESOLUTION = RAND_MAX;  // Resolution of the probability function
    const double infectionProb = .0005;  // Inection Probability
    double buildingFactor[] = {2.6, 1, 2.5, 1, 1, 1, .1, 1.1, 1, 1.5};

    // The air filter factor
    if( filterLocation != ( Student::BUILDINGS + Student::KAFADAR ) ) {
        buildingFactor[filterLocation] = buildingFactor[filterLocation] * .85;
    }
        
    
    if( status != UNINFECTED ) return false;  // If there not uninfected, they can't catch the flu
    
    double sigma_p = locationCounts[Student::getLocation()] * buildingFactor[Student::getLocation()] * infectionProb;  // Chance of someone being infected increases the more infectious people are in that area
    //cout << sigma_p << " ";
    if( status == UNINFECTED ) {  // If their uninfected
        if( rand()%RESOLUTION/double(RESOLUTION) < sigma_p ) {  // If a random number, modded, is less then the probability
            status = INFECTIOUS;  // The person becomes infectious
            status_hours = Student::getDuration();  // Set their status_hours according to their new status
            return true;  // Return true because someone caught the flu
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
    const string statusNames[STAGES] = {"Infectious", "Symptomatic", "Home", "Cured", "Uninfected", "Vaccinated"};  // The names of the flu stages
    const string LOCATIONS[] = {"CTLM", "MEYER_HALL", "COOLBAUGH_HALL", "GREEN_CENTER", "BERTHOUD_HALL", "BROWN_HALL", "KAFADAR", "LIBRARY", "STUDENT_CENTER", "REC_CENTER" };  // The names of the locations
    os << statusNames[status] << " - " << status_hours << " in " << LOCATIONS[location] << endl;  // Output structure
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

// Set the status according to input, accessor
void Student::setStatus( const int theStatus )
{
    status = theStatus;
    status_hours = Student::getDuration();
}

//  Invent a random schedule
void Student::block_schedule( const int dayIndex )  // Fill that day's schedule
{
    for( int h(0); h < LECTURES; h++ ) {  // Up until all the lecture blocks are filled
        schedule[dayIndex][h] = rand() % BUILDINGS;  // For each hour generate a random lecture location
    }
    for( int h(LECTURES); h < HOURS; h++ ) {  // For the remaining hours in the day
        schedule[dayIndex][h] = BUILDINGS;  // Generate a random common location (leisure)
    }
}

//
void Student::shuffle_schedule( const int dayIndex )
{
    /*  Shuffle using FisherYates method  */
	for(int i(0); i < HOURS; i++){  // For each hour
		int chosen = rand() % (HOURS - i);   // Pick a random schedule location
        int hold = schedule[dayIndex][HOURS - 1 - i];  // Store the last changeable location location
        schedule[dayIndex][HOURS - 1 - i] = schedule[dayIndex][chosen];  // Overwrite the last location with the new chosen location
        schedule[dayIndex][chosen] = hold;  // The chosen location gets the last location's old value
    }   
}

//  Update the Location
void Student::updateLocation( const int dayIndex, const int hour ) 
{
    if( schedule[dayIndex % DAYS][hour] < BUILDINGS ) 
    {
        location = schedule[dayIndex % DAYS][hour];
    } else {
        location = BUILDINGS + rand() % COMMONS;
    }
}

//  Duration for that status
int Student::getDuration() const
{
    // duration (in hours) of each flu stage --- 0 means the 
    // the flu stage is exited due to an event, not a passage of time
    const int DURATIONS[] = { 52, 32, 48, 0, 0, 0 };  // Duration for each flu stage
    return DURATIONS[status];
}

//  Location getter
int Student::getLocation( ) const
{
    return location;
}

//  If their status is infectious, return true
bool Student::isInfectious() const
{
    if( status == INFECTIOUS ) {
        return true;
    } else {
        return false;
    }
}

//  function for vaccinating students
bool Student::vaccinate()
{
  // students already vaccinated will know this, and medical professionals would
  // not vaccinate someone that has already caught the bug.
  // In this case, the flu shot has not been used...
    if( status == Student::VACCINATED || 
        (status>=Student::SYMPTOMATIC && status<=Student::CURED) ) {
        return false;
    }

    // an INFECTIOUS student can be vaccinated, but it doesn't work (the student will
    // continue to infect other students and will go through the usual stages of flu 
    // progression.
    if( status == Student::UNINFECTED ) {
        setStatus( Student::VACCINATED );
    }

  // but the vaccine would have been used
  return true;
}
