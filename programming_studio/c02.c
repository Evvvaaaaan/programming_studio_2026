#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st_person{
    char name[20]; 	// Name (single word, no duplicates)
    int gender;  	// 0 - Female, 1 - Male
    int country;	// Country code (index of COUNTRY_NAME 0~5)
    int birthyear; 	// Birthyear
};

int getCountry(char* str);
int printInfo(struct st_person* p);
int countGender(struct st_person* data[], int size, int gender);

int main() {
    struct st_person* pdata[20];
    char country[5];
    char count_gender[2];
    int count;

    scanf("%d", &count);
    // 메모리 할당, 정보 입력받기.
    for(int i = 0; i < count; i++ ) {
        pdata[i] = (struct st_person*)malloc(sizeof(struct st_person));
        scanf("%s %d %s %d",pdata[i]->name, &pdata[i]->gender, country, &pdata[i]->birthyear);
        pdata[i]->country = getCountry(country);
    }
    for(int i = 0; i < count; i++ ) {
        printf("%d) ",i+1);
        printInfo(pdata[i]);
    }
    count_gender[0] = countGender(pdata, count, 0);
    count_gender[1] = countGender(pdata, count, 1);

    printf("Female:%d Male:%d\n",count_gender[0],count_gender[1]);

    return 0;
}

int countGender(struct st_person* data[], int size, int gender) {
    int count = 0;
    for(int i = 0; i < size; i++ ) {
        if(data[i]->gender == gender) {
            count ++;
        }
    }
    return count;
}

int printInfo(struct st_person* p) {
    char countrys[6][3] = {"KR","US","JP","CN","FR","--"};

    if ( p->gender == 1) {
        printf("%s (Male, age:%d, from %s)\n",p->name, 2025-p->birthyear,countrys[p->country]);
    } else {
        printf("%s (Female, age:%d, from %s)\n",p->name, 2025-p->birthyear,countrys[p->country]);
    }
    return 0;
}

int getCountry(char* str) {
    if(strcmp(str, "KR")==0) return 0;
    else if(strcmp(str, "US")==0) return 1;
    else if(strcmp(str, "JP")==0) return 2;
    else if(strcmp(str, "CN")==0) return 3;
    else if(strcmp(str, "FR")==0) return 4;
    else return 5;

}