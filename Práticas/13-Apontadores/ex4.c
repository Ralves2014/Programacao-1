#include <stdio.h>
int main(){
    int i, j, *p1, *p2, **pp1, **pp2;
    i=4;
    j=5;
    p1 = &i;
    p2 = &j;
    pp1 = &p2;
    pp2 = &p1;

    printf("*pp1: %p\n", *pp1);
    printf("&p2: %p\n", &p2);

    printf("\n");
    
    printf("*(&p1): %p\n", *(&p1));     //
    printf("&(*p1): %p\n", &(*p1));     // iguais
    printf("&i: %p\n", &i);             //


    return 0;
}