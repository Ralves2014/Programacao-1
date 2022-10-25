#include <stdio.h>

int main(){

    int num=153, c, d, u, soma;

    c=num/100;
    d=(num-c*100)/10;
    u=num-c*100-d*10;

    soma=(c*c*c)+(d*d*d)+(u*u*u);

    //printf("%d\n", c);
    //printf("%d\n", d);
    //printf("%d\n", u);

    if (soma==num)
        printf("A soma do cubo dos algarismos e igual ao numero\n");
    else
        printf("A soma do cubo dos algarismos nao e igual ao numero\n");

    return 0;
}