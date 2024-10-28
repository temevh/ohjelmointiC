#include <stdio.h>
#include "utf8.h"

void utf8_koodaa(unsigned int merkki, unsigned char utf8[]) {
    if (merkki <= 0x7F) {
        utf8[0] = merkki & 0x7F;
        utf8[1] = '\0';
    } else if (merkki <= 0x7FF) {
        utf8[0] = 0xC0 | ((merkki >> 6) & 0x1F);
        utf8[1] = 0x80 | (merkki & 0x3F);
        utf8[2] = '\0';
    } else if (merkki <= 0xFFFF) {
        utf8[0] = 0xE0 | ((merkki >> 12) & 0x0F);
        utf8[1] = 0x80 | ((merkki >> 6) & 0x3F);
        utf8[2] = 0x80 | (merkki & 0x3F);
        utf8[3] = '\0';
    } else if (merkki <= 0x10FFFF) {
        utf8[0] = 0xF0 | ((merkki >> 18) & 0x07);
        utf8[1] = 0x80 | ((merkki >> 12) & 0x3F);
        utf8[2] = 0x80 | ((merkki >> 6) & 0x3F);
        utf8[3] = 0x80 | (merkki & 0x3F);
        utf8[4] = '\0';
    }
}
int main(void){
    unsigned int koodit[6] = {228, 49340, 49457, 12477, 12491, 12540};
    unsigned char utf8[5];
    int i = 0;
    for(i = 0; i < 6; ++i)
    {
        utf8_koodaa(koodit[i], utf8);
        printf("%s\n", utf8);
    }
    return 0;
}