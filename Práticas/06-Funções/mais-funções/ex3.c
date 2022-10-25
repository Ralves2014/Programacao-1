#include<stdio.h>

int triangulo(int lmax, int l1, int l2){

    int value;

    if(lmax>=l1+l2)
        value=-1;
    if((lmax*lmax)==(l1*l1)+(l2*l2))
        value=0;
    if((lmax*lmax)<(l1*l1)+(l2*l2))
        value=1;
    if((lmax*lmax)>(l1*l1)+(l2*l2))
        value=2;

    return value;
}

int main(){
    int lado_max=5, lado1=4, lado2=3, f;
    f=triangulo(lado_max,lado1,lado2);

    printf("%d\n",f);
}