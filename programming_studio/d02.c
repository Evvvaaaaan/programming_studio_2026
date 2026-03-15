#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct st_movie{
    char title[100];
    int year, genre, playtime, viewers;
    char description[255];
} MOVIE;

const char* genre_name[] = {
    "Sci-Fi",
    "Thriller",
    "Action",
    "Romance",
    "Musical",
    "Drama",
    "Animation",
    "War"
};

int loadRecords(MOVIE* list[]);
void printMovie(MOVIE* p);
void printReport(MOVIE* list[], int size);
int indexGenre(char* name);
void printGenreCount(MOVIE* list[], int size);
int maxPlaytime(MOVIE* list[], int size);
int maxViewers(MOVIE* list[], int size);

int main() {
    MOVIE* mlist[50];
    int count;

    count = loadRecords(mlist);	
    printf("%d records loaded\n",count);
    for(int i=0; i<count; i++){
        printf("%d) ", i+1);
        printMovie(mlist[i]);
    }
    printReport(mlist, count);
}

int loadRecords(MOVIE* list[]) {
    int count;
    char title[100], desc[200], genre[50];
    int year,time,viewers;
    scanf("%d",&count);
    getchar();

    for(int i = 0; i < count; i++ ) {
        list[i] = (MOVIE*)malloc(sizeof(MOVIE));
        fgets(title, 100, stdin);
        fgets(desc, 200, stdin);
        title[strcspn(title, "\n")] = '\0';
        desc[strcspn(desc, "\n")] = '\0';
        scanf("%d %s %d %d",&year, genre, &time, &viewers);
        getchar();
        strcpy(list[i]->description, desc);
        strcpy(list[i]->title, title);
        list[i]->year = year;
        list[i]->playtime = time;
        list[i]->viewers = viewers;
        list[i]->genre = indexGenre(genre);
    }

    return count;
}


int indexGenre(char* name) {
    for(int i =0; i < 8; i++ ){
        if(strcmp(name, genre_name[i]) == 0) {
            return i;
        }
    }
    return 0;
}

void printMovie(MOVIE* p) {
    printf("%s [%d, %s, %dmin, %d viewers]\n",p->title, p->year, genre_name[p->genre],p->playtime,p->viewers);
}


void printReport(MOVIE* list[], int size) {
    printf("\n");
    printGenreCount(list, size);
    int idx = maxPlaytime(list, size);
    int idx2 = maxViewers(list, size);
    printf("\n");
    printf("2. Longest\n");
    printf("%s [%d, %s, %dmin, %d viewers]\n%s\n",list[idx]->title, list[idx]->year, genre_name[list[idx]->genre],list[idx]->playtime, list[idx]->viewers, list[idx]->description);
    printf("\n");
    printf("3. Most Popular\n");
    printf("%s [%d, %s, %dmin, %d viewers]\n%s\n",list[idx2]->title, list[idx2]->year, genre_name[list[idx2]->genre],list[idx2]->playtime, list[idx2]->viewers, list[idx2]->description);
}

void printGenreCount(MOVIE* list[], int size) {
    int genCnt[8] = {0};
    for(int i =0; i < size; i++ ) {
        int genIdx = list[i]->genre;
        genCnt[genIdx]++;
    }
    for(int i =0; i < 8; i++) {
        printf("[%d] %-10s %d movies\n",i+1, genre_name[i], genCnt[i]);
    }
}

int maxPlaytime(MOVIE* list[], int size) {
    int max = 0;
    int idx;
    for(int i =0; i < size; i++ ) {
        if(max < list[i]->playtime) {
            max = list[i]->playtime;
            idx = i;
        }
    }
    return idx;
}

int maxViewers(MOVIE* list[], int size) {
    int max =0;
    int idx;
    for(int i =0; i < size; i++ ){
        if(max < list[i]->viewers) {
            max = list[i]->viewers;
            idx = i;
        }
    }
    return idx;
}