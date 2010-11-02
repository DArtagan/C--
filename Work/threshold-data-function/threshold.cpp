//
//  Function to find the threshold values,
//  compare the data to those, and replace 
//  the data points with their threshold classification
//
#include "threshold-data-function.h"

void threshold( int data[], const int size, double high, double low )
{
    /*  Variables and Constants  */
    int max;
    double upper;
    double lower;
    
    /*  Get the maximum data value  */
    max = findMax( data, size );
    
    /*  Find the threshold Values  */
    upper = max * high;
    lower = max * low;
    
    /*  Convert the data array to the threshold version  */
    for( int i(1); i < size; i++ ) {
        if( data[i] > upper ) {
            data[i] = 2;
        } else if( data[i] < lower ) {
            data[i] = 0;
        } else {
            data[i] = 1;
        }
    }
    
    return;
}
