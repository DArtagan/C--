//
//  The main routine for a program for finding 
//  the surface area and volume of a square pyramid
//
#include "letter-frequency-by-function.h"

void findLeast(const array LetterCounts, const int range, int& least)
{
	/*  Variables  */
	int least(LetterCounts[0]);
	
	for(int j(0); j < 2; j++) {
	   for(int i(0); i < range; i++) {
	   	   if(LetterCounts[i] < least) {
                least = i;
            }
        }
	}
			
	return least;
}
