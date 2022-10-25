#include <stdio.h>

int main(){

    int n1, c, d, u;

    printf("Indique um numero de 3 algarismos: ");
    scanf("%d", &n1);

    c=n1/100;
    d=(n1-c*100)/10;
    u=n1-c*100-d*10;

    if (c==u)
        printf("%d e capicua.\n", n1);
    else
        printf("%d nao e capicua.\n", n1);
    
    return 0;
       
}