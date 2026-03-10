#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_person{
    char name[20]; 	// Name (single word, no duplicates)
    int gender;  	// 0 - Female, 1 - Male
    int country;	// Country code (index of COUNTRY_NAME 0~5)
    int birthyear; 	// Birthyear
};

int getCountry(char* str);
void printInfo(struct st_person* p);


int main() {
    struct st_person* one;
    char country[5];
    
    one = (struct st_person*)malloc(sizeof(struct st_person));
    scanf("%s %d %s %d", one->name, &one->gender,country, &one->birthyear);
    one->country = getCountry(country);

    printInfo(one);

    free(one);
    return 0;
}

void printInfo(struct st_person* p) {
    char genders[2][10] = {"Female", "Male"};
    char country[6][3] = {"KR","US","JP","CN","FR","-"};

    printf("%s (%s, age:%d, from %s)\n",p->name, genders[p->gender], 2025- p->birthyear, country[p->country]);
}


int getCountry(char* str) {
    if(strcmp(str, "KR") == 0) return 0;
    else if(strcmp(str,"US") == 0) return 1;
    else if(strcmp(str,"JP") == 0) return 2;
    else if(strcmp(str,"CN") == 0) return 3;
    else if(strcmp(str,"FR") == 0) return 4;
    else if(strcmp(str,"-") == 0) return 5;
    return -1;
}