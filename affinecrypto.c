#include <stdio.h>
#include <string.h>

void affine_Cipher(char *str, int size, int key1, int key2, int choice){
    int i;
    
    for(int i = 0; i < size; i++){
        if((str[i] >= 'A') && (str[i] <= 'Z')){
            str[i] -= 'A';
            if(choice == 1){
                if((str[i]*key1 + key2) < 0)
                    str[i] += 26;           
                str[i] = (str[i]*key1 + key2) % 26;
            }
            else if(choice == 2){
                if((str[i] - key2) / key1 < 0)
                    str[i] += 26;
                str[i] = ((str[i] - key2) / key1) % 26;
            }
            str[i] += 'A';
        }
        else if((str[i] >= 'a') && (str[i] <= 'z')){
            str[i] -= 'a';
            if(choice == 1){
                if((str[i]*key1 + key2) < 0)
                    str[i] += 26;           
                str[i] = (str[i]*key1 + key2) % 26;
            }
            else if(choice == 2){
                if((str[i] - key2) / key1 < 0)
                    str[i] += 26;
                str[i] = ((str[i] - key2) / key1) % 26;
            }
            str[i] += 'a';
        }
        else ;
    }
}

int main(){
    int i = 0, key1 = 0, key2 = 0, str_size = 0, choice = 0;
    char str[50] = {0, };

    printf("�� �Ǵ� ��ȣ���� �Է��Ͻÿ�: ");
    scanf("%s", str);

wrong:
    printf("��ȣ�� 1��, ��ȣ�� 2��: ");
    scanf("%d", &choice);
    if(choice == 1 || choice == 2) ;
    else goto wrong;

    printf("Ű1 ���� �Է��Ͻÿ�: ");
    scanf("%d", &key1);

    printf("Ű2 ���� �Է��Ͻÿ�: ");
    scanf("%d", &key2);

    str_size = strlen(str);

    affine_Cipher(str, str_size, key1, key2, choice);

    printf("\n��ȣȭ �Ǵ� ��ȣȭ�� ��� ���: ");
    puts(str);

    return 0;
}