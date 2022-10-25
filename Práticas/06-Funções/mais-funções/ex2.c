#include<stdio.h>

int minimo(int array[], int sz){
    int min=array[0];
    for (int i = 1; i < sz; i++)
    {
        if(min>array[i])
            min=array[i];
    }
    
    return min;
}

int main(){

    int f;
    int a[3]={10,60,89};
    f=minimo(a,3);

    printf("%d\n",f);

    return 0;
}