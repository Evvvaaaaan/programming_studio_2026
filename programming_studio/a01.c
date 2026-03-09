#include <stdio.h>


int main() {
    int height, weight;
    float bmi;  
    float height_m;
    scanf("%d %d", &height, &weight);

    height_m = height / 100.0;

    bmi = weight / (height_m * height_m);
    printf("%.1f\n",bmi);
    return 0;
}