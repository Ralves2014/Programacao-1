#include <stdio.h>

int sucessor(int num){
    return num+=1;
}

int main(){
    int n=2, f;
    f=sucessor(n);

    printf("%d\n",f);

    return 0;
}