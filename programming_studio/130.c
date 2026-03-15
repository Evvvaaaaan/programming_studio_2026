#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct st_user {
    char name[10];
    char password[10];
};

int checkUser(struct st_user* list[], int size, struct st_user* temp);

int main() {
    struct st_user data_list[10];
    struct st_user* list[10];   
    FILE* fp;
    char buffer[100];
    char nm[10], pw[10];
    int count = 0;
    int num=999;
    fp = fopen("user.txt","r");

    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%s %s", data_list[count].name, data_list[count].password);
        list[count] = &data_list[count];
        count ++;
    }

    printf("%d login informations were read\n", count);
    fclose(fp);

    struct st_user login_input;

    while(1) {
        printf("Please enter the ID and PW you wish to login with. > ");
        scanf("%s %s", login_input.name, login_input.password);
        num = checkUser(list, count, &login_input);
        if(num == 1 ){
            printf("로그인 성공! : 어세오세요 %s님\n",login_input.name);
            break;
        }
        if (num == 2) {
            printf("로그인 실패! : 비밀번호가 틀렸습니다.\n");

        } else if (num == 3) {
            printf("Login failed! : The ID does not exist.\n");

        }   
    }
    return 0;
}

int checkUser(struct st_user* list[], int size, struct st_user* temp) {
    for(int i = 0; i < size; i++ ) {
        if(strcmp(temp->name, list[i]->name) == 0) {
            if (strcmp(temp->password, list[i]->password) == 0) {
                return 1;
            } else {
                return 2;
            }
        } else {
            return 3;
        }

    }
    return 0;
}