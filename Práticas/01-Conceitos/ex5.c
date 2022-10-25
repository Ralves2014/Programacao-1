#include <stdio.h>

int main(){

    int n1, n2;

    printf("numero 1:");
    scanf("%d", &n1);
    printf("numero 2:");
    scanf("%d", &n2);

    printf("Soma = %d\n", n1+n2);
    printf("Diferença = %d\n", n1-n2);
    printf("Produto = %d\n", n1*n2);
    printf("Divisão = %d\n", n1/n2);
    printf("Resto da Divisão = %d\n", n1%n2);

    return 0;
}