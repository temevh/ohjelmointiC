#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "kuukaudet.h"

const char *KK_NIMET[KK_LKM] = {
    "tammikuu", "helmikuu", "maaliskuu", "huhtikuu",
    "toukokuu", "kesäkuu", "heinäkuu", "elokuu",
    "syyskuu", "lokakuu", "marraskuu", "joulukuu"
};

const char KK_PAIVAT[2][KK_LKM] = {
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, 
    { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } 
};

int karkausvuosi(int vuosiluku) {
    if (vuosiluku % 400 == 0) {
        return 1;
    }
    if (vuosiluku % 4 == 0 && vuosiluku % 100 != 0) {
        return 1;
    }
    return 0;
}

char kkPituus(const char *kkNimi, int vuosiluku) {
    int i;
    for (i = 0; i < KK_LKM; i++) {
        const char *nimiPtr = kkNimi;
        const char *tauluPtr = KK_NIMET[i];
        int match = 1;

        while (*nimiPtr && *tauluPtr) {
            if (tolower((unsigned char)*nimiPtr) != tolower((unsigned char)*tauluPtr)) {
                match = 0;
                break;
            }
            nimiPtr++;
            tauluPtr++;
        }

        if (match && *nimiPtr == '\0' && *tauluPtr == '\0') {
            return KK_PAIVAT[karkausvuosi(vuosiluku)][i];
        }
    }
    return -1;
}