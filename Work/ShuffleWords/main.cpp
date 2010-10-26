#include "ShuffleWords.h"

int main() {
    /*  Declare/Identify Variables  */
    const int SIZE(16);
    string words[SIZE] = {};
    
    /*  Ask for seed value  */
    cout << "-- Shuffle Words --" << endl << endl;
    readSeed();
    cout << endl;
    
    /*  Read Words from the User  */
    cout << "You entered " << readWords(words, SIZE) << " words." << endl;
    
    /*  Shuffle Words  */
    
    
    system("PAUSE");
    //  Exit program.
    return 0;
}
