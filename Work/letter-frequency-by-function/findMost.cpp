//
//  The main routine for a program for finding 
//  the surface area and volume of a square pyramid
//
#include "letter-frequency-by-function.h"

int findMost(const int LetterCounts[], const int range)
{
	/*  Variables  */
	int most(0);
	
	/*  Search for most  */
    for(int i(0); i<range; i++) {
		if(LetterCounts[i] > most) {
            most = i;
        }
	}
		
	return most;
}
