#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int divisible;
    int i;
    int divisor;
    int printed = 0;

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    for (a; a <= b; a++) {
        divisible = 0; 
        for (i = 3; i < argc; i++) {
            divisor = atoi(argv[i]);
            if (a % divisor == 0) {
                divisible = 1;
                break;
            }
        }
        if (!divisible) {
            if (printed) {
                printf(" ");
            }
            printf("%d", a);
            printed = 1; 
        }
    }

    if (printed == 1){
    printf("\n");
    }
    return 0;
}
