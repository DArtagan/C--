//
//
//
#include "shift-cipher-function.h"

char shiftBlock(char text&, int shift) {
    if( inChar >= '0' && inChar <= '9' ) {
        outChar = inChar - '0';
        outChar += 10 + shift;
        outChar %= 10;
        outChar += '0';
    } else if( inChar >= 'a' && inChar <= 'z' ) {
        outChar = inChar - 'a';
        outChar += 26 + shift;
        outChar %= 26;
        outChar += 'a';
    } else if ( inChar >= 'A' && inChar <= 'Z' ) {
        outChar = inChar - 'A';
        outChar += 26 + shift;
        outChar %= 26;
        outChar += 'A';
    } else {
        outChar = inChar;
    }
}
