#include <stdio.h>

int acumulado(int vec[], int sz, int index){

    int soma=0;

    for (int  i = 0; i <= index; i++)
    {
        soma+=vec[i];
    }
    
    return soma;
}

int main(){
    int m[4]={1,2,3,4};
    int f=acumulado(m,4,2);

    printf("%d\n",f);

    return 0;
}