#include <stdio.h>

int verifica_ordem(int vec[], int sz){
    int value=1;
    for (int i = 0; i < sz; i++)
    {
        if(vec[i]>vec[i+1])
            value=0;
        
    }

    return value;
    
}

int main(){

    int a[]={1,2,6,4,5,6};
    int f;

    f=verifica_ordem(a,3);

    printf("%d\n",f);

    return 0;


}