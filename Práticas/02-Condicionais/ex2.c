#include <stdio.h>
#include <math.h>

int main(){
    float r;

    printf("Qual o raio? ");
    scanf("%f", &r);

    printf("Perimetro da circunferencia = %f\n", 2*M_PI*r);
    printf("Area do circulo = %f\n", r*r*M_PI);
    printf("Volume da esfera = %f\n", (4*M_PI*r*r*r)/3);

    return 0;

}