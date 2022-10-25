#include <stdio.h>

int main(){

    float celsius;

    printf("Temperatura em graus Celsius: ");
    scanf("%f", &celsius);

    printf("Em Kelvin: %.2f K\n", celsius+273.15);
    
    printf("Em Fahrenheit: %.2f F\n ", (celsius*9)/5+32);

    return 0;
}