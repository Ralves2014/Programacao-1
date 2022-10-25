#include <stdio.h>

int main(){

    int n1=3, d1=5, n2=1, d2=5, soma, den;

    if(d1==d2){
        soma=n1+n2;
        den=d1;
    }
    else{
        soma=(n1*d2)+(n2*d1);
        den=d1*d2;
    }
    
    
    printf(" %d\n",soma);
    printf("----\n");
    printf(" %d\n",den);

    return 0;
}