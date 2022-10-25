#include<stdio.h>
#include<string.h>

int conta_palavras(char s[]){

    int count=0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i]==' ' && s[i+1]!=',' || s[i]==',' && s[i+1]!=' ' || s[i+1]=='\0')
        {
            count+=1;
        }
        
    }
    
    return count;
}

int main(){
    char string[100]="computador, caderno e caneta amigo";
    int f=conta_palavras(string);
    
    printf("%d\n",f);

    return 0;
}