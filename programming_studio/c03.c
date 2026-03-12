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
void printInfo(struct st_person* p);
void getInfo(struct st_person* p[], int size);

int main() {
    struct st_person* pdata[20];
    char country[5];
    int count;

    scanf("%d",&count);
    for(int i = 0; i < count; i++) {
        pdata[i] = (struct st_person*)malloc(sizeof(struct st_person));
        scanf("%s %d %s %d",pdata[i]->name,&pdata[i]->gender,country, &pdata[i]->birthyear);
        pdata[i]->country = getCountry(country);
    } 
    for(int i = 0; i < count; i++ ) {
        printf("%d) ",i+1);
        printInfo(pdata[i]);
    }
    getInfo(pdata, count);
    return 0;
}

void printInfo(struct st_person* p) {
    char countrys[6][3] = {"KR","US","JP","CN","FR","--"};
    if(p->gender == 0) {
        printf("%s (Female, age:%d, from %s)\n",p->name,2025 - p->birthyear,countrys[p->country]);
    } else {
        printf("%s (Male, age:%d, from %s)\n",p->name,2025 -p->birthyear,countrys[p->country]);
    }

}
int getCountry(char* str) {
    if(strcmp(str, "KR")==0) return 0;
    if(strcmp(str, "US")==0) return 1;
    if(strcmp(str, "JP")==0) return 2;
    if(strcmp(str, "CN")==0) return 3;
    if(strcmp(str, "FR")==0) return 4;
    else return 5;
}

void getInfo(struct st_person* p[], int size) {
    int genderCnt[6][2] = {0};
    float averageAge[6] = {0.0};
    float ageCnt[6] = {0};
    char countrys[6][3] = {"KR","US","JP","CN","FR","--"};

    for(int i = 0; i < size; i++ ) {
        if(p[i]->country == 0) {
            if(p[i]->gender == 0) genderCnt[0][0] ++;
            else genderCnt[0][1] ++;
            averageAge[0] += 2025 - p[i]->birthyear;
            ageCnt[0] ++;
        } else if(p[i]->country == 1) {
            if(p[i]->gender == 0) genderCnt[1][0] ++;
            else genderCnt[1][1] ++;
            averageAge[1] += 2025 - p[i]->birthyear;
            ageCnt[1] ++;
        } else if(p[i]->country == 2) {
            if(p[i]->gender == 0) genderCnt[2][0] ++;
            else genderCnt[2][1] ++;
            averageAge[2] += 2025 - p[i]->birthyear;
            ageCnt[2] ++;
        } else if(p[i]->country == 3) {
            if(p[i]->gender == 0) genderCnt[3][0] ++;
            else genderCnt[3][1] ++;
            averageAge[3] += 2025 - p[i]->birthyear;
            ageCnt[3] ++;
        } else if(p[i]->country == 4) {
            if(p[i]->gender == 0) genderCnt[4][0] ++;
            else genderCnt[4][1] ++;
            averageAge[4] += 2025 - p[i]->birthyear;
            ageCnt[4] ++;
        } else if(p[i]->country == 5) {
            if(p[i]->gender == 0) genderCnt[5][0] ++;
            else genderCnt[5][1] ++;
            averageAge[5] += 2025 - p[i]->birthyear;
            ageCnt[5] ++;
        }
    }
    
    for(int i = 0; i < 6; i++ ) {
        printf("[%s] Female:%d Male:%d average age:%.1f\n",countrys[i],genderCnt[i][0],genderCnt[i][1],averageAge[i]/ageCnt[i]);
    }
}