#include <stdio.h>

float tempoDecorrido(float d, float v){

    return (d/v)*60;

}

int main(){
    
    float dist=2, vel=3, f;
    f=tempoDecorrido(dist,vel);

    printf("%.2f min\n",f);

    return 0;
}