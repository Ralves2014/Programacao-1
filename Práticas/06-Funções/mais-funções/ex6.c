#include<stdio.h>

int mmc(int n1, int n2){

    int mmc=0, i=1;

    while (mmc==0)
    {
        if (i%n1==0 && i%n2==0)
            mmc=i;
        i++;
    }
    return mmc;
}

int main(){

    int f;
    int num1=10, num2=25;
    f=mmc(num1,num2);

    printf("%d\n",f);

    return 0;
}