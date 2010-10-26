//
//  Function to find the largest number in an array
//
#include "letter-frequency-by-function.h"

int findMost(const int LetterCounts[], const int range)
{
	/*  Variables  */
	int most(0);
	
	/*  Find the largest  */
    for(int i(0); i < range; i++) {
		if(LetterCounts[i] > LetterCounts[most]) {
            most = i;
        }
	}
		
	return most;
}
