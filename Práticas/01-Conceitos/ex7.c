#include <stdio.h>

int main(){

    float n;
    char c;
    int num;

    printf("real: ");
    scanf("%f",&n);
    printf("caracter: ");
    scanf(" %c", &c);
    printf("inteiro: ");
    scanf("%d",&num);

    //printf("%d %c %f\n", num, c, n);
    printf("%d ", num);
    printf("%c ", c);
    printf("%.2f\n", n);


    return 0;
}