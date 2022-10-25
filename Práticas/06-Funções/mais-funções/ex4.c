#include<stdio.h>
#include<math.h>

int nRaizes(double a, double b, double c){
    if ((b*b)-(4*a*c)<0)
        return 0;
    else
        return 1;
    
}
double raiz1(double a, double b, double c){
    int x;
    x=(-b-sqrt((b*b)-(4*a*c)))/(2*a);

    return x;
}

double raiz2(double a, double b, double c){
    int x;
    x=(-b+sqrt((b*b)-(4*a*c)))/(2*a);

    return x;
}

int main(){
    double f1, f2, f3, a=1, b=5, c=4;
    f1=raiz1(a,b,c);
    f2=raiz2(a,b,c);
    f3=nRaizes(a,b,c);

    if (f3)
    {
        printf("%f\n",f1);
        printf("%f\n",f2);
    }
    else    
        printf("Não e possivel resolver a equação.\n");
    
    return 0;

}