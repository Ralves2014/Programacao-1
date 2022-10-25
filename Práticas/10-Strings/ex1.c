#include<stdio.h>
#include<string.h>

int tamanho(char s[]){
    return strlen(s);
}

int main(){
    char string[20]="Bomdiaalegria";
    int f=tamanho(string);

    printf("%d\n",f);

    return 0;
}