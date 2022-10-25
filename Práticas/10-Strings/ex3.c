#include<stdio.h>
#include<string.h>

void letras(char s[]){

    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c\n",s[strlen(s)-i-1]);
    }

    printf("\n");
    int j=0;


    while (s[j]!='\0')
    {
        printf("%c\n",s[strlen(s)-j-1]);
        j++;
    }
    
}
int main(){
    char string[20]="Aula";
    letras(string);

    return 0;
}