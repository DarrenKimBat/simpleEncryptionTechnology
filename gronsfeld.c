#include <stdio.h>
#include <string.h>

void gronsfeld(char* , char*, int, int, int);

int main(){
    int Key_Size = 0, str_size = 0, select = 1;
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

    gronsfeld(str, key, str_size, Key_Size, select);

    if(select == 1) printf("��ȣȭ�� Ű: %s", str);
    if(select == 2) printf("��ȣȭ�� Ű: %s", str);
    
    return 0;
}

void gronsfeld(char* str, char* key, int str_size, int Key_Size, int select){
    int i, j, temp;

    for(i = 0,j = 0; i < str_size; i++, j++){
        j = i % Key_Size;

        if(select == 1){
            if((str[i] >= 'a') && (str[i] <= 'z')){
                str[i] -= 'a'; temp = key[j] - '0';
                if(str[i] + temp < 0) str[i] += 26;
                str[i] = (str[i] + temp) % 26;
                str[i] += 'a';
            }
            else if((str[i] >= 'A') && (str[i] <= 'Z')){
                str[i] -= 'A'; temp = key[j] - '0';
                if(str[i] + temp < 0) str[i] += 26;
                str[i] = (str[i] + temp) % 26;
                str[i] += 'A';
            }  
        }

        else if(select == 2){
            if((str[i] >= 'a') && (str[i] <= 'z')){
                str[i] -= 'a'; temp = key[j] - '0';
                if(str[i] - temp < 0) str[i] += 26;
                str[i] = (str[i] - temp) % 26;
                str[i] += 'a';
            }
            else if((str[i] >= 'A') && (str[i] <= 'Z')){
                str[i] -= 'A'; temp = key[j] - '0';
                if(str[i] - temp < 0) str[i] += 26;
                str[i] = (str[i] - temp) % 26;
                str[i] += 'A';
            }  
        }
        else ;
    }
}