#include <stdio.h>

float calcula_somatorio(float v[], int n){

    float soma=0;

    for (size_t i = 0; i < n; i++)
    {
        soma+=v[i];
    }
    
    return soma;

}
void imprimir_vetor(float v[], int n){

    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", v[i]);
    }
    
}
int main(){
    
    float array[15];
    int n, i=0;
    float f, num;

    printf("Quantos valores pretende introduzir: ");
    scanf("%d", &n);

    while (n>15)
    {
        printf("Valor inválido, insira outro valor");
        scanf("%d", &n);
    }

    while (n!=i)
    {
        printf("numero %d: ", i+1);
        scanf("%f",&num);
        array[i]=num;
        i++;
    }

    
    
    f=calcula_somatorio(array,n);

    printf("%.2f\n",f);
    imprimir_vetor(array,n);

    return 0;
}