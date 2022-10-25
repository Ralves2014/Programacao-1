#include <stdio.h>

int main(){

    float x, y;

    printf("Indique as coordenadas x e y: ");
    scanf("%f %f", &x, &y);

    if(x>0 && y>0)
        printf("O ponto encontra-se no quadrante 1.\n");
    else if(x<0 && y>0)
        printf("O ponto encontra-se no quadrante 2.\n");
    else if(x<0 && y<0)
        printf("O ponto encontra-se no quadrante 3.\n");
    else if(x>0 && y<0)
        printf("O ponto encontra-se no quadrante 4.\n");

        
    return 0;
       
}