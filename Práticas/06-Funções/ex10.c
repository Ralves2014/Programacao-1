#include <stdio.h>


float ver_triangulo(float t1, float t2, float t3){

    if (t1+t2 > t3 && t2+t3> t1 && t1+t3 >t2)
        return 1;
    else
        return 0;
    
}

void triangulo(float t1, float t2, float t3){

    if (t1==t2 && t2==t3)
        printf("É um triangulo equilatero\n");
    else if (t1!=t2 && t2!=t3 && t1==t3 || t1!=t3 && t2!=t3 && t1==t2 || t1!=t3 && t2!=t1 && t3==t2)
        printf("É um triangulo isósceles\n");
    else 
        printf("É um triangulo escaleno\n");
    
}

int main(){
    
    float l1=0, l2=1, l3=3, f;
    f= ver_triangulo(l1,l2,l3);
    //printf("%f\n",f);
    if (f)
        triangulo(l1,l2,l3);
    else
        printf("Nao e um triangulo\n");
    
    return 0;
}