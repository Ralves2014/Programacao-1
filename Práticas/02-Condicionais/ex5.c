#include <stdio.h>

int main(){

    int n1, n2, n3;

    printf("numero 1: ");
    scanf("%d", &n1);
    printf("numero 2: ");
    scanf("%d", &n2);
    printf("numero 3: ");
    scanf("%d", &n3);

    if (n1>n2 && n1<n3 || n1>n3 && n1<n2)
    {
        printf("É o numero %d.\n", n1);
    }
    else if (n2>n1 && n2<n3 || n2>n3 && n2<n1)
    {
        printf("É o numero %d.\n", n2);
    }
    else if (n3>n2 && n3<n1 || n3>n1 && n3<n2)
    {
        printf("É o numero %d.\n", n3);
    }
    
    return 0;

    
}