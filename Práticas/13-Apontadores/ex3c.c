#include <stdio.h>

int main(){
    int var1=5;
    char var2='a';
    int *ptr1;
    ptr1=&var1;
    char *ptr2;
    ptr2=&var2;

    printf("O valor de ptr1 : %d\n",*ptr1);
    printf("O valor de ptr2 : %c\n",*ptr2);

    printf("O valor de ptr1+1 : %d\n",*ptr1+1);
    printf("O valor de ptr2+1 : %c\n",*ptr2+1);

    return 0;
}