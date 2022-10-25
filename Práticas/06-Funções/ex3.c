#include <stdio.h>

float velocidade(float v0, float t, float a){

    return v0+a*t;
}

int main(){
    float vi=10, a=2.5, tempo=10, f;
    f=velocidade(vi,tempo,a);

    printf("%.2f m/s\n",f);

    return 0;
}