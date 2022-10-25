#include <stdio.h>

float primeiro(float v[], int sz){

    float menor=v[0];

    for (int i = 1; i < sz; i++)
    {
        if (v[i]<menor)
        {
            menor=v[i];
        }
        
    }

    return menor;
    
}

float segundo(float v[], int sz){

    float menor=primeiro(v,sz);
    float segundo_menor;
    int i=0;

    do
    {
        segundo_menor=v[i];
        i++;
    } while (segundo_menor==menor);
    

    for (; i < sz; i++)
    {
        if (v[i]>menor && v[i]<segundo_menor)
        {
            segundo_menor=v[i];
        }
        
    }
    
    return segundo_menor;
    
    
}

float terceiro(float v[], int sz){

    float menor=primeiro(v,sz);
    float segundo_menor=segundo(v,sz);
    float terceiro_menor;
    int i=0;

    do
    {
        terceiro_menor=v[i];
        i++;
    } while (terceiro_menor==segundo_menor || terceiro_menor==menor);
    

    for (; i < sz; i++)
    {
        if (v[i]>menor && v[i]>segundo_menor && v[i]<terceiro_menor) 
        {
            terceiro_menor=v[i];
        }
        
    }
    
    return terceiro_menor;

}

int main(){
    int n, i=0;
    
    float tempo, f1, f2, f3;
    printf("Quantos tempos pretende inserir? ");
    scanf("%d",&n);

    float array[n];

    while (n!=i)
    {
        printf("tempo do atleta %d: ", i+1);
        scanf("%f",&tempo);
        array[i]=tempo;
        i++;
    }

    f1=primeiro(array,n);
    f2=segundo(array,n);
    f3=terceiro(array,n);

    printf("primeiro: %.2f\n",f1);
    printf("segundo: %.2f\n",f2);
    printf("terceiro: %.2f\n",f3);

    
    return 0;
}