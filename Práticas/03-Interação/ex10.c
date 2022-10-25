#include<stdio.h>

int main(){

    int a, b, numero=1;

    printf("Valor a: ");
    scanf("%d", &a);

    printf("Valor b: ");
    scanf("%d", &b);

    while(numero<=50){

        if(numero%a==0 && numero%b==0)
            printf("%d: %d %d\n", numero,a,b);

        else if(numero%a==0)
            printf("%d: %d\n", numero,a);

        else if(numero%b==0)
            printf("%d: %d\n", numero,b);

        numero++;
    }
    return 0;
}