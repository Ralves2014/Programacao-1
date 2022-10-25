#include <stdio.h>

struct datas
{
    int dia;
    int mes;
    int ano;

};

void diaSeguinte(struct datas d){
    d.dia+=1;
    printf("Dia de seguinte: %d/%d/%d\n",d.dia,d.mes,d.ano);
}

struct datas diaAnterior(struct datas d){
    struct datas da;
    da.dia=d.dia-1;
    da.mes=d.mes;
    da.ano=d.ano;
    
    return da;
}

int main(){
    struct datas hoje;
    struct datas diaanterior;
    int dia=10, mes=2,ano=2002;

    hoje.dia=dia;
    hoje.mes=mes;
    hoje.ano=ano;

    diaanterior=diaAnterior(hoje);
    
    printf("Dia anterior: %d/%d/%d",diaanterior.dia,diaanterior.mes,diaanterior.ano);


    return 0;
}