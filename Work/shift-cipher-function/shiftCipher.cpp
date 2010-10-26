//
//  Shifts the entire text from beginning to end
//
#include "shift-cipher-function.h"

void shiftCipher(string& text, const int shift) {
    for(int i(0); i < text.length(); i++) {
// Calls the individual character shift function
        text[i] = shiftBlock(text[i], shift);
    }
    return;
}
