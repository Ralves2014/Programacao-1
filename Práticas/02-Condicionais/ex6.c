#include <stdio.h>

int main(){

    float num=30;

    if (num<-10 || num>=5 && num<45 || num>120 && num<=245)
        printf("O numero encontra-se nos intervalos.\n");
    else
        printf("O numero nao se encontra nos intervalos.\n");
        
    return 0;
    

    
}