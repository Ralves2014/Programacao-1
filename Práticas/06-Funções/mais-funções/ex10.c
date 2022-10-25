#include<stdio.h>

int fatorial(int n){
    int res=1;
    for (int i = n; i >=1 ; i--)
    {
        res*=i;
    }

    return res;
    
}

int main(){

    int num=4, f;
    f=fatorial(num);

    printf("%d\n",f);

    return 0;
}