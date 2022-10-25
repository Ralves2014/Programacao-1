#include <stdio.h>

int main(){
    int num;
    printf("Insira um numero:");
    scanf("%d",&num);
    if (num%3==0 && num%2!=0)
        printf("O numero é impar e multiplo de 3\n");
    else if (num%3==0 && num%2==0)
        printf("O numero é multiplo de 3\n");
    else if (num%3!=0 && num%2!=0)
        printf("O numero é impar\n");
    else if (num%3!=0 && num%2==0)
        printf("O numero nao é impar nem multiplo de 3\n");
    
    
    return 0;

}
