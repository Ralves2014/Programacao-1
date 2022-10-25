#include<stdio.h>

int mdc(int n1, int n2){

    int max_div;

    if (n1>n2)
    {
        for (int i = 1; i < n1; i++)
        {
            if (n1%i==0 && n2%i==0)
            {
                max_div=i;
            }
            
        }
        
    }
    else
    {
        for (int i = 1; i < n2; i++)
        {
            if (n1%i==0 && n2%i==0)
            {
                max_div=i;
            }
            
        }
    }

    return max_div;
    
}

/*
int mdc( int u, int v ){
    int tmp;
    while( v!=0 ){
        tmp=u%v;
        u=v;
        v=tmp;
    }
    return u;
*/

int main(){

    int f;
    int num1=10, num2=25;
    f=mdc(num1,num2);

    printf("%d\n",f);

    return 0;
}