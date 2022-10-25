#include<stdio.h>

int fibonacci(int n){
    int f;
    if (n<2)
    {
        return 1;
    }
    else
    {
        f=fibonacci(n-1) + fibonacci(n-2);
        return f;

    }

}
int main(){

    int f;
    f=fibonacci(10);

    printf("%d\n", f);
    return 0;

}