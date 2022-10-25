#include <stdio.h>

void ver_triangulo(float t1, float t2, float t3){

    if (t1+t2 > t3 && t2+t3> t1 && t1+t3 >t2)
        printf("É um triangulo\n");
    else
        printf("Não é um triangulo\n");
    
}

int main(){
    
    float l1=1, l2=3, l3=3;
    ver_triangulo(l1,l2,l3);

    return 0;
}