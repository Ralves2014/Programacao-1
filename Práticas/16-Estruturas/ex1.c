#include <stdio.h>
#include <math.h>

struct complexo 
{
    double i;
    double r;
};

struct complexo soma_complexo(struct complexo c1, struct complexo c2){
    struct complexo n;
    n.r=c1.r+c2.r;
    n.i=c1.i+c2.i;

    return n;
}

void escreve_complexo(struct complexo c){
    printf("%.1f+%.1fy", c.r,c.i);
}

double modulo_complexo(struct complexo c){
    double dist;
    dist=sqrt((c.r*c.r)+(c.i*c.i));

    return dist;
}

double argumento_complexo(struct complexo c){
    double hip, arg;
    hip=sqrt((c.r*c.r)+(c.i*c.i));

    arg=acos(c.r/hip);

    return arg;

}

int main(){

    struct complexo soma;

    double m_c, arg_c;
    
    struct complexo t;
    t.i=1;
    t.r=2;

    struct complexo t2;
    t2.i=1;
    t2.r=2;

    soma=soma_complexo(t,t2);

    m_c=modulo_complexo(t);
    arg_c=argumento_complexo(t);

    escreve_complexo(t);
    printf("\n");
    printf("Soma de complexos: %.2f+%.2fy\n",soma.r,soma.i);
    printf("Modulo do complexo: %f\n",m_c);
    printf("Argumento do complexo: %f\n",arg_c);
    

}
