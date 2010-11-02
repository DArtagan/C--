//
//  A function to find the maximum value in a data array
//
#include "threshold-data-function.h"

int findMax( const int data[], const int size )
{
    /*  Variables and Constants  */
    int max(0);
    
    /*  Find the maximum data value  */
    for( int i(1); i < size; i++ ) {
        if( data[i] > max ) max = data[i];
    }
    
    return max;
}
