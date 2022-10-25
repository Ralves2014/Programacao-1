#include <stdio.h>

void imprimir_vetor(float v[], int n){

    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", v[i]);
    }
    
}

float media(float v[]){

    float soma=0;
    float m;

    for (int i = 0; i < 10; i++)
    {
        soma+=v[i];
    }

    m=soma/10;

    return m;
    
}

float minimo(float v[]){
    float min=v[0];

    for (int i = 1; i < 10; i++)
    {
        if (v[i]<min)
        {
            min=v[i];
        }
        
    }

    return min;
    
}

float maximo(float v[]){
    float max=v[0];

    for (int i = 1; i < 10; i++)
    {
        if (v[i]>max)
        {
            max=v[i];
        }
        
    }

    return max;
    
}

int main(){
    
    float array[10];
    int i=0;
    float f1, f2, f3, num;


    while (10!=i)
    {
        printf("numero %d: ", i+1);
        scanf("%f",&num);
        array[i]=num;
        i++;
    }


    f1=media(array);
    f2=minimo(array);
    f3=maximo(array);

    printf("%.2f\n",f1);
    printf("%.2f\n",f2);
    printf("%.2f\n",f3);
    imprimir_vetor(array,10);

    return 0;
}