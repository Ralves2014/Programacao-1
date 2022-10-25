#include<stdio.h>

int perfeito(int n){

    int soma=0;
     
    for (int i = 1; i < n; i++)
    {
        if (n%i==0)
            soma+=i;
        
    }

    if (soma==n)
        return 1;
    else
        return 0;
    
}

int main(){

    int num=8, f;
    f=perfeito(num);

    printf("%d\n",f);

    return 0;
}