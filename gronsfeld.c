#include <stdio.h>
#include <string.h>

gronsfeld(char* , char*, int);

int main(){
    int i = 0, Key_Size = 0, str_size = 0, select = 1;
    char str[50] = {0, }, key[16] = {0, };

    printf("��ȣ�� �Ǵ� �� �Է�: ");
    scanf("%s", str);
wrong:
    printf("��ȣȭ�� 1��, ��ȣȭ�� 2�� ����: ");
    scanf("%d", &select);
    if(select == 1 || select == 2) ;
    else goto wrong;
    fflush(stdin);
    printf("Ű �� �Է�: ");
    scanf("%s", key);
    
    str_size = strlen(str);
    Key_Size = strlen(key);

    gronsfeld(str, key, select);
}

void gronsfeld(char* str, char* key, int select)