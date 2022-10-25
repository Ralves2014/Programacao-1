#include<stdio.h>

int A(int m,int n){
    if(m==0)
        return n+1;

    else if (m>0 && n==0)
        return A(m-1,1);

    else if (m>0 && n>0)
        return A(m-1,A(m,n-1));
    
}

int main(){
    int num1=5,num2=20,f;
    f=A(num1,num2);
    printf("%d\n",f);

    return 0;
}