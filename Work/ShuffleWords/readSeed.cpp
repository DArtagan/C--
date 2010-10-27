//
//  File to reade the user input for the rand() seed
//
#include "ShuffleWords.h"

int readSeed() {
    /*  Variables  */
    int n;

    /*  Seed Prompt  */
    cout << "What would you like the seed for this shuffle to be (the seed should be greater than 16)?" << endl;
    cin >> n;
    cout << endl << "The seed you picked is " << n << "." << endl;
    
    return n;
}
