#include <stdio.h>
#include <math.h>

int main() {
    double c1 , c2, h;
    
    printf("Qual o comprimento do cateto 1: ");
    scanf("%lf" , &c1);
    printf("Qual o comprimento do cateto 2: ");
    scanf("%lf" , &c2);
    
    h = sqrt((c1*c1) + (c2*c2));
    
    printf("%.2lf\n" , h);
    return 0;
}