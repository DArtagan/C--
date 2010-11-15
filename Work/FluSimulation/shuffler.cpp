//
//  Shuffle a int array
//
#include "WeekSchedule.h"

void shuffler( int schedule[], const int hours ) 
{
    /*  Variables  */
    int hold;
    int chosen;
    int counter(hours);

    /*  Shuffle using FisherYates method  */
    for( int i(0); i < counter; i++ ) {
        int chosen = rand() % (hours - i);
        hold = schedule[counter - 1 - i];
        schedule[counter - 1 - i] = schedule[chosen];
        schedule[chosen] = hold;
    }   
    
    return;
}
