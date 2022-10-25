#include<stdio.h>
#include<string.h>

void sub_cadeia(char s[]){
    for (int i = 0; i < strlen(s); i++)
    {
        for (int y = 0; y < strlen(s)-i; y++)
        {
            printf("%c",s[y]);
        }
        printf("\n");
    }
    
}
int main(){
    char string[20]="Aula";
    sub_cadeia(string);

    return 0;
}