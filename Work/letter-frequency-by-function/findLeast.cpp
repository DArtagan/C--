//
//  Program to find the smallest number in an array
//
#include "letter-frequency-by-function.h"

int findLeast(const int LetterCounts[], const int range)
{
	/*  Variables  */
    int least(0);
	
	/*  Fint the least used character  */
	for(int j(0); j < 2; j++) {
	   for(int i(0); i < range; i++) {
	   	   if(LetterCounts[i] < LetterCounts[least]) {
                least = i;
            }
        }
	}
			
	return least;
}
