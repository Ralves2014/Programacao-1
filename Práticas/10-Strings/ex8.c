#include<stdio.h>
#include<string.h>

int ocorrencias(char letra, char string[]){

    int count=0;

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i]==letra)
        {
            count+=1;
        }
        
    }

    return count;
    
}

int main(){
    char string[20]="noeon";
    char c='o';
    int f=ocorrencias(c,string);
    
    printf("%d\n",f);

    return 0;
}