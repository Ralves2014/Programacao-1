#include <stdio.h>

int main(){

    int segundos, dias, horas, min;

    printf("Quantos segundos: ");
    scanf("%d", &segundos);

    dias=segundos/(86400);       //24*60*60
    horas=(segundos-dias*86400)/3600;   //60*60
    min=(segundos-dias*86400-horas*3600)/60;
    segundos=segundos-dias*86400-horas*3600-min*60;


    printf("dias: %d\n", dias);
    printf("horas: %d\n", horas);
    printf("minutos: %d\n", min);
    printf("dias: %d\n", segundos);

    return 0;
}