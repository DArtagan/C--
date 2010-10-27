//
//  Function that handles shuffling the words
//
#include "ShuffleWords.h"

void shuffleWords(string words[], int counter) 
{
    /*  Variables  */
    string hold;
    int chosen;

    /*  Shuffle using FisherYates method  */
    for(int i(1); i <= counter; i++) {
       chosen = rand() % (counter - i);
       hold = words[counter - i];
       words[counter - i] = words[chosen];
       words[chosen] = hold;
       counter--;
    }   
}
