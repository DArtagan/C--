//
//  Main function of the shuffle words program.  Handles most I/O
//
#include "ShuffleWords.h"

int main() {
    /*  Declare/Identify Variables  */
    const int SIZE(16);
    string words[SIZE] = {};
    int counter;
    
    /*  Ask for seed value  */
    cout << "-- Shuffle Words --" << endl << endl;
    srand(readSeed());
    cout << endl;
    
    /*  Read Words from the User  */
    counter = readWords(words, SIZE);
    for(int i(0); i < counter; i++) {
        cout << words[i] << " ";
    }
    cout << endl << endl;
    
    /*  Shuffle Words  */
    cout << "Shuffled:" << endl;
    shuffleWords(words, counter);
    for(int i(0); i < counter; i++) {
        cout << words[i] << " ";
    }
    
    system("PAUSE");
    //  Exit program.
    return 0;
}
