#include <stdio.h>

int bmiLevel(int height, int weight);


int main() { 
    int height[10], weight[10];
    int bmi_level[10];
    int count = 0;
    int arr[10] = {0};

    for(int i =0; i < 10; i++ ) {
        scanf("%d %d", &height[i], &weight[i]);
    }
    

    for(int i =0; i < 10; i++ ) {
        if(bmiLevel(height[i], weight[i]) >= 3) {
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

int bmiLevel(int height, int weight) {
    float bmi;
    float height_m;

    height_m = height / 100.0;
    bmi = weight / (height_m * height_m);
    
    if(bmi < 18.5) {
        return 0;
    } else if (bmi < 23) {
        return 1;
    } else if (bmi < 25) {
        return 2;
    } else if (bmi < 30) {
        return 3;
    } else {
        return 4;   
    }
}