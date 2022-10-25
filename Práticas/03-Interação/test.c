#include <stdio.h>

void tabela(int inicio, int fim, int tamanho){
    
    for (int i = inicio; i <= fim; i++)
    {
        if (i%tamanho==0 && i!=inicio)
        {
            printf("\n");
        }
        
        printf("%d ", i);
    }
   
}

int main(){

    int start=10, end=49, linelength=10, f;

    tabela(start,end,linelength);

    return 0;
}