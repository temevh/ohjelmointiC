#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int voittorivi[7];
    int lottorivi[7];
    int oikein[7];
    int match_count = 0;

    int i = 0;
    int j = 0;

    // Populate voittorivi and lottorivi arrays
    for (i; i < 7; i++) {
        voittorivi[i] = atoi(argv[i + 1]);
        lottorivi[i] = atoi(argv[i + 8]);
    }

    // Print voittorivi
    printf("Voittorivi: ");
    for (j; j < 7; j++) {
        printf("%d ", voittorivi[j]);
    }
    printf("\n");

    j = 0;
    // Print lottorivi
    printf("Lottorivi: ");
    for (j; j < 7; j++) {
        printf("%d ", lottorivi[j]);
    }
    printf("\n");

    j = 0;
    i = 0;
    // Find matches and store them
    for (j; j < 7; j++) {
        for (i; i < 7; i++) {
            if (voittorivi[i] == lottorivi[j]) {
                oikein[match_count] = voittorivi[i];
                match_count += 1;
                break;  // If a match is found, stop searching for this number
            }
        }
    }
    

    // Print the matching numbers
    if (match_count > 0) {
        printf("oikein: ");
        for (int i = 0; i < match_count; i++) {
            printf("%d ", oikein[i]);
        }
        printf("\n");
    } else {
        printf("No matching numbers.\n");
    }

    return 0;
}
