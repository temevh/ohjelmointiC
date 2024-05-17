#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] ){
    int iterator;
    int min = atoi(argv[1]);
    int max = atoi(argv[2]);

    for (iterator = min; iterator <= max; iterator++){
        printf("%d: %c\n", iterator, iterator);
    }


    return 0;
}