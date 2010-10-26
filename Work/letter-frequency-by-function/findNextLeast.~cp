//
//  The main routine for a program for finding 
//  the surface area and volume of a square pyramid
//
#include "letter-frequency-by-function.h"

void findNextLeast(const array LetterCounts, const int range, int& nextLeast)
{
	/*  Variables  */
    int most;
	int least(LetterCounts[0]);
	int nextLeast;
	
	/*  Find the most letters  */
	for(int i(0); i<range; i++) {
		if(LetterCounts[i] > most) {
            most = i;
        }
	}
	
	/*  Find the least letters  */
	for(int j(0); j < 2; j++) {
	   for(int i(0); i < range; i++) {
	   	   if(LetterCounts[i] < least) {
                least = i;
            }
        }
	}
	
	/*  Find the next least letters  */
	nextLeast = most;
	for(int i(0); i < range; i++) {
		if(LetterCounts[i] < nextLeast && LetterCounts[i] > least) {
			nextLeast = i;
		}
	}

	return nextLeast;
}
