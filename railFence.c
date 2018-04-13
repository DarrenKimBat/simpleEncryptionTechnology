#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void railFence(char*, char*, char*, char**);
int row_num = 0, col_num = 0, size = 0, select = 0, cnt = 0, rail = 0;

int main(){
    char text[64], c_text[64], d_text[64];
    char **tmp_text;

wrong:
    printf("Encryption - 1, Decryption - 2 : ");
    scanf("%d", &select);

    if(select == 1) 
        printf("Enter plain text : ");
    else if(select == 2) 
        printf("Enter cipher text : ");
    else goto wrong;

    scanf("%s", text);
    size = strlen(text);
    
    printf("Number of rails : ");
    scanf("%d", &rail);
    tmp_text = (char**)malloc(sizeof(char*) * rail);
    for(int i = 0; i < rail; i++)
		tmp_text[i] = (char*)malloc(sizeof(char) * size + 1);

	railFence(text, c_text, d_text, tmp_text);
    return 0;
}

void railFence(char* text, char* c_text, char* d_text, char** tmp_text){
	const int r = size % rail, q = size / rail;
    if(select == 1){
        for(col_num  = 0; col_num < size; col_num++)
            tmp_text[col_num % rail][col_num / rail] = text[col_num]; 
        
		int adder, loc = 0;
        for(col_num = 0; col_num < (size / rail); col_num++){
			c_text[col_num] = tmp_text[0][col_num];
			loc = col_num;
			int temp = r;
            for(int j = 1; j < rail; j++){
				if((temp > 0)) adder = 1;
				else adder = 0;
                c_text[loc = loc + (size / rail) + adder] = tmp_text[j][col_num];
				--temp;
            }
		}
		loc = 0;
		for(int j = 0; j < size % rail; j++){
			c_text[loc = loc  + q] = tmp_text[j][col_num]; loc++;
		}
		c_text[size] = '\0';
		printf("Cipher : %s\n", c_text);
    }

	else if(select == 2){
		int adder, loc = 0;
        for(col_num  = 0; col_num < size / rail; col_num++){
                tmp_text[0][col_num] = text[col_num];
				loc = col_num;
				int temp = r;
				for(int j = 1; j < rail; j++){
					if((temp > 0)) adder = 1;
					else adder = 0;
					tmp_text[j][col_num] = text[loc = loc + (size / rail) + adder];
					--temp;
				}
		}		
		loc = 0;
		for(int j = 0; j < size % rail; j++){
			tmp_text[j][col_num] = text[loc = loc  + q]; loc++;
		}

		for(col_num = 0; col_num < size; col_num++)
			d_text[col_num] = tmp_text[col_num % rail][col_num / rail];

		d_text[size] = '\0';
		printf("Decipher : %s\n", d_text);
	}
}