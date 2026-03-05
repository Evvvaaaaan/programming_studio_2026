#include <stdio.h>

int main() {
    int size;
    int stars, blank1, blank2;
    int i, j;

    scanf("%d", &size);

    int width = 2 * size;

    for(int i = 0; i < size; i++ ) {
        // i = 0
        for (int j = 0; j < width; j++ ) {
            // j = 0123456789
            if(j == i || j == width - i - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i =0; i < size; i++ ) {
        for(int j =0; j < width; j++ ) {
            printf("*");
        }
        printf("\n");
    }

    for(int i =0; i< size; i++ ) {
        for(int j =0; j < width; j++ ) {
            if(j > i -1 && j <= width - 1 - i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for(int i = 0; i < width; i++) {
        printf("*");
    }
    printf("\n");
    return 0;
}


