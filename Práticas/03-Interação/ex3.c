#include<stdio.h>

int main(){

    int n, x=1;

    printf("Qual o limite da contagem? ");
    scanf("%d", &n);

    while(x<=n){
        printf("%d\n", x);
        x++;
    }

    x=x-1;

    while(x!=0){
        x--;
        printf("%d\n", x);
    }
    
    return 0;
}