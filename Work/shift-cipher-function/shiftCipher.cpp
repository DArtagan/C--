//
//
//
#include "shift-cipher-function.h"

void shiftCipher(string& text, int shift) {
    for(int i(0); i < text.length(); i++) {
        text[i] = shiftBlock(char(text[i]), shift);
    }
    return;
}
