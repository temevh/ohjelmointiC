#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EXPONENT_BITS 8
#define MANTISSA_BITS 23
#define BIAS 127

/* Function prototypes */
int get_exponent(const char *binary_str);
double get_mantissa(const char *binary_str);
double calculate_value(double mantissa, int exponent, int sign);

int get_exponent(const char *binary_str) {
    int exponent;
    int i;
    
    exponent = 0;
    for (i = 1; i <= EXPONENT_BITS; i++) {
        exponent = (exponent << 1) | (binary_str[i] - '0');
    }
    return exponent - BIAS;
}

double get_mantissa(const char *binary_str) {
    double mantissa;
    double weight;
    int i;
    
    mantissa = 1.0; /* The implicit leading 1 */
    weight = 2.0;
    
    for (i = 0; i < MANTISSA_BITS; i++) {
        if (binary_str[1 + EXPONENT_BITS + i] == '1') {
            mantissa += 1.0 / weight;
        }
        weight *= 2.0;
    }
    
    return mantissa;
}

double calculate_value(double mantissa, int exponent, int sign) {
    return sign * mantissa * pow(2, exponent);
}

int main(int argc, char *argv[]) {
    int i;
    int sign;
    int exponent;
    double mantissa;
    double value;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <32-bit binary strings>\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc; i++) {
        const char *binary_str = argv[i];
        
        if (strlen(binary_str) != 32) {
            fprintf(stderr, "Error: Each input must be a 32-bit binary string.\n");
            return 1;
        }

        sign = (binary_str[0] == '0') ? 1 : -1;
        exponent = get_exponent(binary_str);
        mantissa = get_mantissa(binary_str);
        value = calculate_value(mantissa, exponent, sign);

        printf("%.15f\n", mantissa);
        printf("%d\n", exponent);
        printf("%c\n", sign == 1 ? '+' : '-');
        printf("%.15f\n", value);
    }

    return 0;
}