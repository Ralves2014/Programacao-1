#include <stdio.h>

int main(){

    int num, max=0, p=0, pc=0;
    printf("Insira um numero:");
    scanf("%d",&num);
    
    if(num==0)
        printf("A sequencia nao tem maximo\n");

    while(num!=0){
        pc++;

        if (max<num){
            max=num;
            p=pc;
        }
        printf("Insira um numero:");
        scanf("%d",&num);
    }

    printf("O maximo desta sequencia ocorreu na posicao nº %d: %d\n", p, max);

    return 0;
}