#include <stdio.h>

int bmiLevel(int height, int weight);


int main() { 
    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};
    int height, weight;

    scanf("%d %d", &height,&weight);
    

    printf("%s (%d)\n", bmi_string[bmiLevel(height, weight)],bmiLevel(height, weight));

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