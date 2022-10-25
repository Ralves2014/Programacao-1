#include <stdio.h>

int main(){

    float usd, euros;

    printf("Valor euros:");
    scanf("%f", &euros);

    usd=euros/0.85;

    printf("Em usd: %.2f", usd);

    return 0;
}