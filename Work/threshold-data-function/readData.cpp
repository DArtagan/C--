//
//
//
#include "threshold-data-function.h"

istream& readData( istream& inputf, int data[], int& size, int MAX )
{
    /*  Variables and Constants  */
    
    inputf >> size;
    
    if( size > MAX ) {
        cout << "There are too many data points for this program." << endl;
        system("PAUSE");
        exit(1);
    }
        
    for(int i(0); i < size; i++) {
        if( !(inputf >> data[i])) {
            break;
        }
    }

    
    return inputf;
}
