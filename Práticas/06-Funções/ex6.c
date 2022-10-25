#include <stdio.h>

#define n1 3
#define preco_kg 0.2

float custosEncomenda(int n, float preco, float peso){

    return preco*n+n1+(n-1)*peso*preco_kg;

}

int main(){
    int nl=2;
    float price=10, peso=5, f;
    f=custosEncomenda(nl,price,peso);

    printf("%.2f\n",f);

    return 0;
}