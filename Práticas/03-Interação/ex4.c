#include<stdio.h>

int main(){

    int soma=0, n=1;

    while(n!=0){

        printf("Qual o valor? ");
        scanf("%d", &n);

        soma+=n;
    }

    printf("A soma é %d\n", soma);

    return 0;
}