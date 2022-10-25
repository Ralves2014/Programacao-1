#include <stdio.h>

int simetrica(int mat[][5], int sz){


    for (int i = 0; i < sz; i++)
        for (int j = i+1; j < sz; j++)
            if (mat[i][j]!= mat[j][i])
                return 0;     
    return 1;

}
int main(){

    int array[5][5]={{1,0,0,0,0}, {0,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,0}, {0,0,0,0,1}};
    printf("%d\n", simetrica(array,5));

    return 0;
}