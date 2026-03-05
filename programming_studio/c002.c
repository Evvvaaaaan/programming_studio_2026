#include <stdio.h>

int main() {

    int person[4][3]; // 4 3
    int sum[3] = {0}; // ( , , )
    float ratio[3]; // ( , , )
    int i, j;


    for(int i =0; i< 4; i++ ) {
        if( i == 0 ) {
                printf("Check room (Men)\n");
            }
            if (i == 2 ) {
                printf("Check room (Women)\n");
            }
        for (int j =0; j < 3; j++ ) {
            
            printf("Room #%d0%d > ",i+1, j+1);
            scanf("%d",&person[i][j]);
        }
    }
    printf("Check Result\n");

    for(int i = 0; i < 2; i++ ) {
        for (int j = 0 ; j < 3; j++ ) {
            sum[0] += person[i][j];
        }
    }
    for(int i = 2; i < 4; i++ ) {
        for(int j = 0; j < 3; j++ ) {
            sum[1] += person[i][j];
        }
    }

    for(int i = 0; i < 4; i++ ) {
        for (int j = 0; j < 3; j++ ) {
            sum[2] += person[i][j];
        }
    }


    ratio[0] = sum[0] / 24.0 * 100;
    ratio[1] = sum[1] / 24.0 * 100;
    ratio[2] = sum[2] / 48.0 * 100;

    printf("Men: %d/%d (%.1f%%)\n", sum[0], 24, ratio[0]);
    printf("Women: %d/%d (%.1f%%)\n", sum[1], 24, ratio[1]);
    printf("Total: %d/%d (%.1f%%)\n", sum[2], 48, ratio[2]);

    return 0;
}