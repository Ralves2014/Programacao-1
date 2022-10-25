#include <stdio.h>

//funçao dada na aula
int mdc( int u, int v ){
    int tmp;
    while( v!=0 ){
        tmp=u%v;
        u=v;
        v=tmp;
    }

    return u;
}

//outro metodo de resolução
int main(){

    int n1=100, n2=20, limit, mdc;

    if (n1>n2)
        limit=n1;
    else
        limit=n2;

    for (int i = 1; i <= limit; i++)
    {
        if (n1%i==0 && n2%i==0)
            mdc=i;

    }
    
    printf("Maximo divisor comum: %d\n", mdc);

    return 0;
}