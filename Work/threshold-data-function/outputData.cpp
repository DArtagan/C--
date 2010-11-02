//
//  Function to output characters to a file depending
//  on one of three input values in an array
//
#include "threshold-data-function.h"

ostream& outputData( ostream& outputf, const int data[], const int size )
{
    /*  Variables and Constants  */
    const char OutputChars[] = { '8', '/', ' ' };
    
    for( int i(0); i < size; i++) {
        outputf << OutputChars[data[i]];
    }
    outputf << endl;

    return outputf;
}
