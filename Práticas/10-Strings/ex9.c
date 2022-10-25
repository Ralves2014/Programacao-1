#include<stdio.h>
#include<string.h>

int ocorrencias2(char letra, char string[],int indice){

    int count=0;

    for (int i = indice; i < strlen(string); i++)
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
    int f=ocorrencias2(c,string,2);
    
    printf("%d\n",f);

    return 0;
}