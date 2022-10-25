#include <stdio.h>

float posicao(float p0, float v0, float t, float a){

    return p0+v0*t+(a*t*t)/2;

}

int main(){
    float pi=10, vi=10, a=2.5, tempo=10, f;
    f=posicao(pi,vi,tempo,a);

    printf("%.2f\n",f);

    return 0;
}