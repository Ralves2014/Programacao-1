#include<stdio.h>

int multiplo(int n, int i){

    if (i==1)
    {
        return n;
    }
    return i*multiplo(n-1,i);
}
int main(){

    int f;
    f=multiplo(3,3);

    printf("%d\n", f);
    return 0;

}