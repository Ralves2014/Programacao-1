#include<stdio.h>

int fatorial_interativo(int n){
    int res=1;
    for (int i = 1; i <= n; i++)
        res*=i;
    
    
    return res;
}

int fatorial_recursiva(int n){
    
    if (n==1)
        return 1;
    else
        return n*fatorial_recursiva(n-1);
    
}

int main(){
    int num=4, f1, f2;
    f1=fatorial_interativo(num);
    f2=fatorial_recursiva(num);

    printf("%d\n",f1);
    printf("%d\n",f2);

    return 0;

}