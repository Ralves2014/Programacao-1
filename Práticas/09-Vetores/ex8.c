#include <stdio.h>

int contaRepetidos(int v[], int sz, int num){

    int count=0; 

    for (int i = 0; i < sz; i++)
    {
        if (num==v[i])
        {
            count+=1;
        }
        
    }

    return count;
    
}

int main(){

    int array[20];
    int num=1, i=0, f;
    
    while (num>0 && i!=20)
    {
        printf("insira um numero: ");
        scanf("%d", &num);

        array[i]=num;
        i++;
    }
    
    f=contaRepetidos(array,20,1);

    printf("%d\n", f);

    return 0;
}