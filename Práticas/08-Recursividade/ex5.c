#include<stdio.h>

int mdc(int m,int n){
    if (m==n)
    {
        return m;
    }
    else if (m>n)
    {
        return mdc(m-n,n);
    }
    else
        return mdc(m,n-m);
    
}
int main(){
    int num1=5,num2=20,f;
    f=mdc(num1,num2);
    printf("%d\n",f);

    return 0;
}