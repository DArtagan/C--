//
//  The actual shift function for each character
//
#include "shift-cipher-function.h"

char shiftBlock(char& text, int shift) {
// Numbers
    if( text >= '0' && text <= '9' ) {
        text = text - '0';
        text += 10 + shift;
        text %= 10;
        text += '0';
// Lowercase Letters
    } else if( text >= 'a' && text <= 'z' ) {
        text = text - 'a';
        text += 26 + shift;
        text %= 26;
        text += 'a';
// Capital Letters
    } else if ( text >= 'A' && text <= 'Z' ) {
        text = text - 'A';
        text += 26 + shift;
        text %= 26;
        text += 'A';
// All other characters are kept unshifted
    } else {
        text = text;
    }
    return text;
}
