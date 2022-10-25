#include<stdio.h>

void hello(int n){

    if (n==0)
    {

    }
    else {
        printf("hello\n");
        hello(n-1);
    }
}
int main(){
    
    hello(3);

    return 0;
}