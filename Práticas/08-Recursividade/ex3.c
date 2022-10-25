#include<stdio.h>

int soma(int n){

    if (n==1)
    {
        return 1;
    }
    return n+soma(n-1);
}
int main(){

    int f;
    f=soma(3);

    printf("%d\n", f);
    return 0;

}