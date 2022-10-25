#include<stdio.h>
#include<string.h>

int vogal(char c){
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        return 1;
    else 
        return 0;
}

int conta_vogais(char s[]){

    int count=0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (vogal(s[i]))
        {
            count+=1;
        }
        
    }

    return count;
    
}

int main(){
    char string[20]="noeon";
    int f=conta_vogais(string);
    
    printf("%d\n",f);

    return 0;
}