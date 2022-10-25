#include<stdio.h>

int maximo(int array[], int sz){
    int max=array[0];
    for (int i = 1; i < sz; i++)
    {
        if(max<array[i])
            max=array[i];
    }
    
    return max;
}

int main(){

    int f;
    int a[3]={10,60,89};
    f=maximo(a,3);

    printf("%d\n",f);

    return 0;
}