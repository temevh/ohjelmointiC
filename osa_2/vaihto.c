#include "vaihto.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int x = 4;
    int y = 9;
    int z = 3;
    printf("%d %d %d\n", x, y, z);
    vaihda(&x, &y);
    printf("%d %d %d\n", x, y, z);
    jarjesta(&x, &y, &z);
    printf("%d %d %d\n", x, y, z);


    return 0;
}

void vaihda(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void jarjesta(int *a , int *b, int *c){
    if (*a > *c){
        vaihda(a, c);
    }

    if(*a > *b){
        vaihda(a, b);
    }

    if(*b > *c){
        vaihda(b, c);
    }


}