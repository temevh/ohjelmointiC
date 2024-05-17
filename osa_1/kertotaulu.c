#include <stdio.h>

int main() {
    int size = 15;
    int a;
    int i;
    int j;

    printf("   x");

    for (a = 1; a <= size; a++) {
        printf("%4d", a);
    }
    printf("\n");

    for (i = 1; i <= size; i++) {
        printf("%4d", i); 
        
        for (j = 1; j <= size; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    return 0;
}
