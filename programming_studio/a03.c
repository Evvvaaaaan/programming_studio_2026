#include <stdio.h>


int main() {
    int height, weight, num;
    float bmi;  
    float height_m;
    int overweight_cnt = 0;
    scanf("%d",&num);
    for(int i =0; i < num; i++ ) {
        scanf("%d %d", &height, &weight);
        height_m = height / 100.0;
    
        bmi = weight / (height_m * height_m);
        if(bmi >= 25) {
            overweight_cnt++;
        }
    }

    printf("%d\n", overweight_cnt);
    return 0;
}