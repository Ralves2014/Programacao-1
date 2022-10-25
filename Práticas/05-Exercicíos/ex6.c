#include <stdio.h>

int main(){

    int n1=30, n2=60, limit, mmc=0, i=1;

    while (mmc==0)
    {
        if (i%n1==0 && i%n2==0)
            mmc=i;

        i++;
    }
    
    
    printf("Minimo multiplo comum: %d\n", mmc);

    return 0;
}