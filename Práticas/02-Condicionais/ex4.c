
#include <math.h>
#include <stdio.h>

int main() {
   double number, squareRoot;

   printf("Enter a number: ");
   scanf("%lf", &number);


    if (number<0)
        printf("O numero e negativo\n");
    else{
        squareRoot = sqrt(number);
        printf("Raiz de %.2lf =  %.2lf\n", number, squareRoot);

    }
        
   return 0;
}