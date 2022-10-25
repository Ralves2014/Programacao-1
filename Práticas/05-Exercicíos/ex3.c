#include <stdio.h>

int main(){

    int num, max=0;
    printf("Insira um numero:");
    scanf("%d",&num);

    if(num==0)
        printf("A sequencia nao tem maximo\n");

    while(num!=0){
        if (max<num)
            max=num;
        
        printf("Insira um numero:");
        scanf("%d",&num);
        
    }

    printf("O maximo desta sequencia: %d\n", max);

    return 0;
}