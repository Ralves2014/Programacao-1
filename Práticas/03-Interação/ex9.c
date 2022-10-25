#include<stdio.h>

int main(){

    int a, b, numero=1;

    printf("Valor a: ");
    scanf("%d", &a);

    printf("Valor b: ");
    scanf("%d", &b);

    while(numero<=50){

        if(numero%a==0)
            printf("%d\n", numero);

        else if(numero%b==0)
            printf("%d\n", numero);

        numero++;
    }
    return 0;
}