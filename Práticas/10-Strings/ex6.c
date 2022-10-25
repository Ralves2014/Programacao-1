#include<stdio.h>
#include<string.h>

int palindromo(char s[]){
    for (int i = 0; i < strlen(s)/2; i++)
    {
        if (s[i]!=s[strlen(s)-i-1])
        {
            return 0;
        }
        
    }

    return 1;
    
}

int main(){
    char string[20]="noon";
    int f=palindromo(string);
    
    printf("%d\n",f);

    return 0;
}