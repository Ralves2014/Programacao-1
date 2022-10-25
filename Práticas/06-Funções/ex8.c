#include <stdio.h>

float tempoDecorrido(float d, float v){

    return (d/v)*60;

}

void horaChegada(int hp, int mp, float min){

    float min_total= hp*60+mp+min;
    //printf("min_total: %f\n",min_total);
    int hc=min_total/60;
    int mc=min_total-hc*60;

    printf("%d : %d\n",hc,mc);
}

int main(){
    
    int hpart=10, mpart=0, escolha;

    printf("1. troço 1: 2 km, velocidade média de 7.5km/h\n");
    printf("2. troço 2: 6 km, velocidade média de 10.9km/h\n");
    printf("3. troço 3: 2 km, velocidade média de 7.5km/h\n");

    scanf("%d", &escolha);

    if (escolha==1)
    {
        float dist=2, vel=7.5, result;
        result=tempoDecorrido(dist,vel);
        horaChegada(hpart,mpart,result);
    }
    else if (escolha==2)
    {
        float dist=6, vel=10.9, result;
        result=tempoDecorrido(dist,vel);
        horaChegada(hpart,mpart,result);
    }
    else if (escolha==3)
    {
        float dist=2, vel=5.5, result;
        result=tempoDecorrido(dist,vel);
        horaChegada(hpart,mpart,result);
    }
    
    

    return 0;
}