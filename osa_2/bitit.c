#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitit.h"

void kaannaScharBitit(signed char *x) {
    unsigned char result = 0;
    unsigned char value = (unsigned char)*x;

    for (i = 0; i < 8; i++) {
        result <<= 1;
        result |= (value & 1);
        value >>= 1;
    }

    *x = (signed char)result; 
}

void kaannaShortBitit(short *x) {
   short result = 0;
   short value = *x;

    for (i = 0; i < 16; i++) {
        result <<= 1;
        result |= (value & 1);
        value >>= 1;
    }

    *x = result; 
}

void kaannaIntBitit(int *x) {
   int result = 0;
   int value = *x;

    for (i = 0; i < 32; i++) {
        result <<= 1;
        result |= (value & 1);
        value >>= 1;
    }

    *x = result; 
}

void kaannaLongBitit(long *x) {
    long result = 0;
   long value = *x;

    for (i = 0; i < 64; i++) {
        result <<= 1;
        result |= (value & 1);
        value >>= 1;
    }

    *x = result; 
}
