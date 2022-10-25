#include <stdio.h>

/*  Enunciado
int main(){
    int var1=5;
    char var2='a';
    int *ptr1= &var1;           int *ptr1;
                                ptr1=&var1;
    char *ptr2;
    *ptr2='b';                  ptr2=&var2;
    printf("var1 tem o endereço %p e o valor %d\n", ptr1, var1 );   printf("var1 tem o endereço %p e o valor %d\n", ptr1, *ptr1 );
    printf("var2 tem o endereço %p e o valor %c\n", ptr2, *ptr2 );  printf("var2 tem o endereço %p e o valor %c\n", ptr2, *ptr2 );
}
*/

int main(){
    int var1=5;
    char var2='a';
    int *ptr1;
    ptr1=&var1;
    char *ptr2;
    ptr2=&var2;
    printf("var1 tem o endereço %p e o valor %d\n", ptr1, *ptr1 );
    printf("var2 tem o endereço %p e o valor %c\n", ptr2, *ptr2 );

    return 0;
}