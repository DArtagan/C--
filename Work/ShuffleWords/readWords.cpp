#include "ShuffleWords.h"

int readWords(string words[], const int SIZE) {
    /*  Variables  */
    int counter(0);
    
    /*  Friendly Text  */
    cout << "Enter the words you would like shuffled," << \
    "up to " << SIZE << ". Seperate the words with spaces or returns. " << \
    "If you enter the same word twice the program will cease to store words." << \
    endl << endl;

    /*  Prompt for and store words  */
    for(int i(0); i < SIZE; i++) {
        cin >> words[i];
        counter++;
        if(i != 0 && words[i] == words[(i - 1)]) break;
    }
    cout << endl << endl;
    
    return counter;
}
