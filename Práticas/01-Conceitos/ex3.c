#include <stdio.h>

int main(){

    float usd, euros;

    printf("Valor usd:");
    scanf("%f", &usd);

    euros=usd*0.85;

    printf("Em euros: %.2f", euros);

    return 0;
}