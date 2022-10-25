#include <stdio.h>

int pascal(int l,int c){

    if (c==0 || c==l)
        return 1;
    else{
        return pascal(l-1, c-1) + pascal(l-1, c);
    }    
}

void trianguloPascal(int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d",pascal(i,j));
        }
        printf("\n");
    }
    
}


int main(){

    trianguloPascal(6);
    return 0;
}