#include <stdio.h>

float custosEnvio(int n, float c, float cs){

    return c+cs*(n-1);

}

int main(){
    int nl=5;
    float cp=2, cs=3, f;
    f=custosEnvio(nl,cp,cs);

    printf("%.2f\n",f);

    return 0;
}