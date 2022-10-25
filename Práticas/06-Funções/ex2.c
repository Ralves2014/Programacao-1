#include <stdio.h>

int quadradoDoSucessor(int num){
    int n=num+=1;

    return n*n;
}

int main(){
    int n=2, f;
    f=quadradoDoSucessor(n);

    printf("%d\n",f);

    return 0;
}