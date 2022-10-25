#include<stdio.h>

int main(){

    int n, fat=1;

    printf("Qual o número? ");
    scanf("%d", &n);

    if(n>0){

        while(n!=0){

            fat*=n;
            n--;
        }
        
        printf("O fatorial é %d\n", fat);

    }
    else if(n<0)
        printf("Valor Negativo\n");

    else 
        printf("O fatorial é 0\n");

    return 0;
}