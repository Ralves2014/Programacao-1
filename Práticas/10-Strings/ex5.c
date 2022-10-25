#include<stdio.h>
#include<string.h>

void espelho(char s[]){
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c",s[i]);
    }
    
    for (int j = strlen(s); j >= 0 ; j--)
    {
        printf("%c",s[j]);
    }
    
}

int main(){
    char string[20]="Aula";
    espelho(string);

    return 0;
}