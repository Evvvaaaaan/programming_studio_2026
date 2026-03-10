#include <stdio.h>



int bmiLevel(int height, int weight);


int main() {
    int height[20], weight[20]; // 최대 20명의 신장(cm), 체중(kg)
    int bmi_level[20]; // 최대 20명의 비만등급(0~4)
    int count=0, all=0; // 비만인 사람의 숫자, 총 인원수
    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};

    scanf("%d",&all);
    for(int i = 0; i < all; i++ ) {
        scanf("%d %d",&height[i], &weight[i]);
        bmi_level[i] = bmiLevel(height[i], weight[i]);

    }
    for(int i = 0; i < all; i++ ) {
        if (bmi_level[i] >= 3) {
            count ++;
            printf("%d %s\n",i+1,bmi_string[bmi_level[i]]);
        }
    }
    return 0;
}

int bmiLevel(int height, int weight) {
    float bmi;
    float height_m;

    height_m = height / 100.0;

    bmi = weight / (height_m * height_m);

    if (bmi < 18.5) {
        return 0;
    } else if (bmi < 23) {
        return 1;
    } else if (bmi < 25) {
        return 2;
    }  else if (bmi < 30) {
        return 3;
    } else {
        return 4;
    }
}