#include<stdio.h>

int main(){

    float soma=0, n=1, f=0;

    while(n!=0){

        printf("Qual o valor? ");
        scanf("%f", &n);

        soma+=n;
        f++;
    }

    f=f-1;

    printf("Valores introduzido: %.0f\n", f);
    printf("Média: %.1f\n", soma/f);

    return 0;
}