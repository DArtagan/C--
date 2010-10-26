//
//  Program to find the second largest number in an array
//
#include "letter-frequency-by-function.h"

int findNextMost(const int LetterCounts[], const int range)
{
	/*  Variables  */
	int most(0);
	int nextMost(0);
	
	/*  Find the largest  */
    for(int i(0); i<range; i++) {
		if(LetterCounts[i] > LetterCounts[most]) {
            most = i;
        }
	}
	
	/*  Find the second largest  */
	for(int j(0); j < 2; j++) {
	   for(int i(0); i < range; i++) {
	   	   if(LetterCounts[i] > LetterCounts[nextMost] && LetterCounts[i] % LetterCounts[most] != 0) {
                nextMost = i;
            }
        }
	}
			
	return nextMost;
}
