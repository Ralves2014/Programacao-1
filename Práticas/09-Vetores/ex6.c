#include<stdio.h>

int media_notas(int array[], int sz){

    int soma=0, media, maior=array[0], menor=array[0];

    for (int i = 0; i < sz; i++)
    {
        soma+=array[i];

        if(maior<array[i])
            maior=array[i];

        if(menor>array[i])
            menor=array[i];
    }
    
    soma=soma-maior-menor;
    media=soma/13;

    return media;
}

int main(){
    int notas[15]={-1, 10, 11, 12, 13, -1, 15, 8, 9, 15, 10, 12, 19, -1, 20};
    int f=media_notas(notas,15);

    printf("%d\n",f);
}