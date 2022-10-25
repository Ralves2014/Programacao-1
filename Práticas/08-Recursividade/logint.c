#include<stdio.h>

int logint(int n, int b){

    int res=0;

    if (n/b==0)
    {
        return res;
    }
    else{
        res+=1;
        return res+logint(n/b,b);;
    }
        
    
}

int main(){
    int f;
    f=logint(10,2);

    printf("%d\n",f);
    return 0;
}