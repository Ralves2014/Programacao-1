#include <stdio.h>

//O endereço do maior valor
int *vmaior(int *v1,int *v2){

    if (*v1<*v2)
        return v2;
    
    else if (*v1>*v2)
        return v1;
    
}
//O maior valor
int nmaior(int *v1,int *v2){

    if (*v1<*v2)
        return *v2;
    
    else if (*v1>*v2)
        return *v1;
    
}

int main(){
    int n1=2, n2=3, *p1, *p2, *func, numax;
    p1=&n1;
    p2=&n2;

    func=vmaior(p1,p2);
    numax=nmaior(p1,p2);

    printf("O endereço do maior valor: %p\n", func);
    printf("O maior valor: %d\n", numax);

    return 0;
}