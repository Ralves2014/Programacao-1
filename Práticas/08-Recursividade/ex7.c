#include <stdio.h>

int pascal(int l,int c){

    if (c==0 || c==l)
        return 1;
    else{
        return pascal(l-1, c-1) + pascal(l-1, c);
    }

    
}

int main(){

    int f;

    f=pascal(3,2);

    printf("%d\n", f);

    return 0;
}