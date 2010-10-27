//
//  Function that reads user input for words
//
#include "ShuffleWords.h"

int readWords(string words[], const int SIZE) {
    /*  Variables  */
    int counter(0);
    string temporary;
    
    /*  Friendly Text  */
    cout << "Enter the words you would like shuffled," << \
    "up to " << SIZE << ". Seperate the words with spaces or returns. " << \
    "If you enter the same word twice the program will cease to store words." << \
    endl << endl;

    /*  Prompt for and store words  */
    for(int i(0); i < SIZE; i++) {
        cin >> temporary;
        if(i != 0 && temporary == words[(i - 1)]) break;
        words[i] = temporary;
        counter++;
    }
    cout << endl << endl;
    
    return counter;
}
