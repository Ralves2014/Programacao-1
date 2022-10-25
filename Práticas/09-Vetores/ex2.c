#include <stdio.h>

int existe_elemento( int el, int vec[], int sz ){
    int value=0;
    for (int i = 0; i < sz; i++)
    {
        if (vec[i]==el)
            value=1;
        
    }

    return value;
    
}


int conta_elementos( int v1[], int v2[], int sz1, int sz2 ){
    int count=0;

    for (int i = 0; i < sz1; i++)
    {
        if (existe_elemento(v1[i],v2,sz2))
        {
            count+=1;
        }
        
    }
    return count;
    
}


int main(){

    int a[]={1,2,2};
    int b[]={1,2,6,4,5};
    int f;

    f=conta_elementos(a,b,3,5);

    printf("%d\n",f);

    return 0;


}