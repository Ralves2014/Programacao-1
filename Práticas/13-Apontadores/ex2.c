#include <stdio.h>

void ordena( int *a, int *b, int *c){
    if (*a>*b && *b>*c && *a>*c)
        printf("%d < %d < %d", *c,*b,*a);

    else if (*a>*b && *b<*c && *a>*c)
        printf("%d < %d < %d", *b,*c,*a);

    else if (*b>*a && *a>*c && *b>*c)
        printf("%d < %d < %d", *c,*a,*b);

    else if (*b>*a && *a<*c && *b>*c)
        printf("%d < %d < %d", *a,*c,*b);

    else if (*c>*a && *a>*b && *c>*b)
        printf("%d < %d < %d", *b,*a,*c);

    else if (*c>*a && *a<*b && *c>*b)
        printf("%d < %d < %d", *a,*b,*c);
    
}

int main(){
    int n1=33, n2=2, n3=91, *p1, *p2, *p3;

    p1=&n1;
    p2=&n2;
    p3=&n3;

    ordena(p3,p2,p1);

    return 0;
}
