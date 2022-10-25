#include <stdio.h>

int main(){
    int var1=5;
    char var2='a';
    int *ptr1;
    ptr1=&var1;
    char *ptr2;
    ptr2=&var2;

    printf("var1 tem tamnaho igual a %ld e *ptr1 tem tamanho igual a %ld\n", sizeof(var1), sizeof(*ptr1));
    printf("var2 tem tamnaho igual a %ld e *ptr2 tem tamanho igual a %ld\n", sizeof(var2), sizeof(*ptr2));

    return 0;
    
}