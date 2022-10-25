#include <stdio.h>

int matriz_identidade( int matriz[][10], int n ){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j && matriz[i][j]!=1)
                return 0;
            if(i!=j && matriz[i][j]!=0)
                return 0;
        }
        
    }

    return 1;
    
}

int main(){
    int m[][10]={{1,0,0},{1,1,0},{0,0,1}};

    int f=matriz_identidade(m,3);

    printf("%d\n",f);
}