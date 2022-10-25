#include<stdio.h>

int somacubos(int n){
    int c, d, u;

    c=n/100;
    d=(n-c*100)/10;
    u=n-c*100-d*10;

    if (n==(c*c*c)+(d*d*d)+(u*u*u))
        return 1;
    else    
        return 0;
    
}

int main(){

    int num=153, f;
    f=somacubos(num);

    printf("%d\n",f);

    return 0;
}