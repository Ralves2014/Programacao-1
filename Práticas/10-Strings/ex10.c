#include<stdio.h>
#include<string.h>
#include <ctype.h>

int ocorrencias3(char letra, char string[],int indice){

    int count=0;
    char new_string[strlen(string)];

    for (int i = 0; i < strlen(string); i++)
        new_string[i]=tolower(string[i]);
        
    for (int j = indice; j < strlen(new_string); j++)
    {
        if (new_string[j]==letra)
        {
            count+=1;
        }
    }
    

    return count;
    
}

int main(){
    char string[20]="Noeon";
    char c='N';
    int f=ocorrencias3(tolower(c),string,0);
    
    printf("%d\n",f);

    return 0;
}