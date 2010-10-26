//
//  Program to find the second smallest number in an array
//
#include "letter-frequency-by-function.h"

int findNextLeast(const int LetterCounts[], const int range)
{
	/*  Variables  */
    int most;
	int least(0);
	int nextLeast;
	
	/*  Find the largest  */
	for(int i(0); i<range; i++) {
		if(LetterCounts[i] > LetterCounts[most]) {
            most = i;
        }
	}
	
	/*  Find the smallest  */
	for(int j(0); j < 2; j++) {
	   for(int i(0); i < range; i++) {
	   	   if(LetterCounts[i] < LetterCounts[least]) {
                least = i;
            }
        }
	}
	
	/*  Find the second smallest  */
	nextLeast = most;
	for(int i(0); i < range; i++) {
		if(LetterCounts[i] < LetterCounts[nextLeast] && LetterCounts[i] > LetterCounts[least]) {
			nextLeast = i;
		}
	}

	return nextLeast;
}
