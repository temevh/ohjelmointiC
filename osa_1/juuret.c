#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    int dec = atoi(argv[1]);
    int i;
    for (i = 2; i < argc; i++) {
        double num = atof(argv[i]);
        printf("sqrt(%.*f) = %.*f\n", dec, num, dec, sqrt(num));
    }

    return 0;
}