#include <stdio.h>

int main(){

    float alt=1.7;

    if (alt<1.3)
        printf("Essa pessoa e baixissima.\n");
    else if (alt>=1.3 && alt<1.6)
        printf("Essa pessoa e baixa.\n");
    else if (alt>=1.6 && alt<1.75)
        printf("Essa pessoa e mediana.\n");
    else if (alt>=1.75 && alt<1.9)
        printf("Essa pessoa e alta.\n");
    else 
        printf("Essa pessoa e altissima.\n");
    
    return 0;
    

    
}