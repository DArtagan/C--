//
//  Block out and array with random integers, free block option
//
#include "WeekSchedule.h"

void blocking( int schedule[], const int hours, const int buildings, const int lectures ) {
    for( int h(0); h < lectures; h++ ) {
        schedule[h] = rand() % buildings;
    }
    for( int h(lectures); h < hours; h++ ) {
        schedule[h] = buildings;
    }
    
    return;
}
