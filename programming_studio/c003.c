#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int person[5]);
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc);

int main() {
    srand(time(NULL));
    char man_name[10][20];
    char woman_name[10][20];
    int man_cnt = 0;
    int woman_cnt = 0;
    int man_room[10];
    int woman_room[10];
    int menu;
    int mans_room[5] = {0};
    int womans_room[5] = {0};
    printf("===========================================\n");
    printf("생활관 호실 배정 프로그램\n");
    printf("===========================================\n");
    while(1) {
        printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
        scanf("%d",&menu);
        if (menu == 0) {
            break;
        }
        if(menu == 1) {
            if (man_cnt >= 10 ) {
                printf("\nError\n");
                break;

            } else {
                printf("학생 이름은? > ");
                scanf("%s",man_name[man_cnt]);
                int r = findRoom(mans_room);
                man_room[man_cnt] = r;
                mans_room[r-1]++;
                man_cnt++;
                printf("%s 학생 10%d호실 배정되었습니다.\n",man_name[man_cnt-1],r);
            }
        } else if (menu == 2) {
            if(woman_cnt >= 10) {
                printf("Error");
            } else {
                printf("학생 이름은? > ");
                scanf("%s",woman_name[woman_cnt]);
                int r = findRoom(womans_room);
                woman_room[woman_cnt] = r;
                womans_room[r-1]++;
                woman_cnt++;
                printf("%s 학생 20%d호실 배정되었습니다.\n",woman_name[woman_cnt-1],r);
            }
        }
    }
    printReport(man_name, man_room, man_cnt,woman_name,woman_room,woman_cnt);

    return 0;
}

// 랜덤으로 방 배정
int findRoom(int person[5]) {
    int room_idx;
    while(1) {
        room_idx = rand() % 5;
        if(person[room_idx] < 2) {
            return room_idx + 1;
        }
    }
}
// 배정된 방 출력
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc) {
    printf("===========================================\n");
    printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
    printf("===========================================\n");
    printf("남학생 명단 (%d명)",mc);
    for(int i = 0; i < mc; i++) {
        printf("\n%d. %s [10%d호]",i+1, mn[i],mr[i]);
    }
    printf("\n");
    printf("\n여학생 명단 (%d명)",wc);
    for(int i = 0; i < wc; i++) {
        printf("\n%d. %s [20%d호]",i+1, wn[i],wr[i]);
    }
    
    printf("\n");
    printf("\n호실별 배정 명단");
    for(int i =0; i < 5; i++) {
        printf("\n10%d호 : ",i+1);
        for(int j = 0; j < mc; j++) {
            if(mr[j] == i+1) {
                printf("%s ",mn[j]);
            }
        }
    }
    for(int i =0; i < 5; i++){
        printf("\n10%d호 : ",i+1);
        for(int j =0; j < wc; j++ ) {
            if(wr[j] == i+1){
                printf("%s ",wn[j]);
            }
        }
    }
    printf("\n");

}