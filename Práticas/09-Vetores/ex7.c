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
    int notas[15];
    int n=0,num,count=0;

    while (n!=15)
    {
        printf("Insira uma nota: ");
        scanf("%d", &num);
        if (num==-1 && count!=3)
        {
            count++;
            printf("Para nao prejudicar a sua media nao contamos ate 3 trabalhos nao entregues: nº de trabalhos nao entregues (%d)\n", count);
        }else{
            notas[n]=num;
            n++;
        }
        
    }
    
    int f=media_notas(notas,15);

    printf("%d\n",f);
}