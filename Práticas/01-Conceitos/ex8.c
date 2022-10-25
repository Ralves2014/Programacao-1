#include <stdio.h>

int main(){

    int n, c, d, u;

    printf("Numero: ");
    scanf("%d", &n);

    c=n/100;
    d=(n-c*100)/10;
    u=n-c*100-d*10;

    printf("%d\n", c);
    printf("%d\n", d);
    printf("%d\n", u);



    return 0;
}