#include<stdio.h>

int main(){

    float litros, escolha, dia=1;

    while(dia<15){

        
        float gasoleo=1.149, gasolina95=1.364, gasolina98=1.414; 

        printf("Quantos litros? ");
        scanf("%f", &litros);

        printf("Qual o combustivel (1:gasoleo, 2:gasolina95, 3:gasolina98)? ");
        scanf("%f", &escolha);

        printf("Qual o dia do abastecimento? ");
        scanf("%f", &dia);

        if(escolha==1){
            printf("O custo é %.2f\n", litros*gasoleo);
            break;
        }
        else if(escolha==2){
            printf("O custo é %.2f\n", litros*gasolina95);
            break;
        }  
        else if(escolha==3){
            printf("O custo é %.2f\n", litros*gasolina98);
            break;
        }
            
    }

    while(dia>=15){

        
        float gasoleo=1.149-0.023, gasolina95=1.364-0.021, gasolina98=1.414; 

        printf("Quantos litros? ");
        scanf("%f", &litros);

        printf("Qual o combustivel (1:gasoleo, 2:gasolina95, 3:gasolina98)? ");
        scanf("%f", &escolha);

        printf("Qual o dia do abastecimento? ");
        scanf("%f", &dia);

        if(escolha==1){
            printf("O custo é %.2f\n", litros*gasoleo);
            break;
        }
        else if(escolha==2){
            printf("O custo é %.2f\n", litros*gasolina95);
            break;
        }  
        else if(escolha==3){
            printf("O custo é %.2f\n", litros*gasolina98);
            break;
        }
    }
    return 0;
}