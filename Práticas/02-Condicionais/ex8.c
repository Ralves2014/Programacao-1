#include <stdio.h>

int main(){

    int n1, n2;

    printf("Indique os numeros 1 e 2: ");
    scanf("%d %d", &n1, &n2);

    if (n1%n2==0){
        printf("%d e multiplo de %d\n", n1, n2);
        printf("e multiplo.\n");
    }
    else{
        printf("%d nao e multiplo de %d\n", n1, n2);
        printf("nao e multiplo.\n");
    }
        
    return 0;
    
}