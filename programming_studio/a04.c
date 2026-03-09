#include <stdio.h>


int main() {
    int height[10], weight[10];
    float bmi[10];  
    int count = 0;
    float height_m;
    int arr[10] = {0};

    for(int i =0; i < 10; i++ ) {
        scanf("%d %d", &height[i], &weight[i]);
        height_m = height[i] / 100.0;
    
        bmi[i] = weight[i] / (height_m * height_m);
        if(bmi[i] >= 25) {
            count ++;
            arr[i] = 1;
        }
    }
    for(int i =0; i < 10; i++ ) {
        if (arr[i] == 1) {
            printf("%d ",i+1);
        }
    }
    printf("\n%d\n", count);
    return 0;
}