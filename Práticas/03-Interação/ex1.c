#include<stdio.h>


int main(){

    // com ciclo while
    int n=1, x, y;

    while(n!=3){

        x=y;

        printf("Insira o número %d: ", n);
        scanf("%d", &y);

        n++;


    }

    //printf("X:%d\n", x);
    //printf("Y:%d\n", y);

    if  (x>y)
        printf("1\n");

    else if  (x<y)
        printf("-1\n");

    else if  (x==y)
        printf("0\n");





    // sem ciclo while

    /*
    int x, y;

    printf("Insira o numero 1:");
    scanf("%d", &x);

    printf("Insira o numero 2:");
    scanf("%d", &y);

    if (x>y)
    {
        printf("1\n");
    }
    else if (x==y)
    {
        printf("0\n");
    }
    else //if (x<y)
    {
        printf("-1\n");
    }
    */


    return 0;
}