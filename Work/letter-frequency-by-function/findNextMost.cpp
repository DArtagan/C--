//
//  The main routine for a program for finding 
//  the surface area and volume of a square pyramid
//
#include "letter-frequency-by-function.h"

void findNextMost(const array LetterCounts, const int range, int& nextMost)
{
	/*  Variables  */
	int most(0);
	int nextMost(0);
	
	/*  Find the most  */
    for(int i(0); i<range; i++) {
		if(LetterCounts[i] > most) {
            most = i;
        }
	}
	
	/*  Find the second most  */
	for(int j(0); j < 2; j++) {
	   for(int i(0); i < range; i++) {
	   	   if(LetterCounts[i] > nextMost && LetterCounts[i] % most != 0) {
                nextMost = i;
            }
        }
	}
			
	return nextMost;
}
