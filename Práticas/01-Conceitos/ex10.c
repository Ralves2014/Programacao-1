#include <stdio.h>

int main(){

    float num, y;
    int n;

    printf("Insira um numero: ");
    scanf("%f", &num);

    y=num*1000;
    n=  (int) y;
    y=n/1000.0;

    printf("y=%.3f\n", y);

    return 0;
}