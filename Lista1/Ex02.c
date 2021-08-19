/******************************************************************************

Exercício 2
Dado um número natural na base binária, transformá-lo para a base decimal.
Exemplo: Dado 10010 a saída será 18, pois 1. 2^4 + 0. 2^3 + 0. 2^2 + 1. 2^1 + 0. 2^0 = 18.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int bin, resto, potencia=1, soma=0;
    
    printf("Entre com um número binário: ");
    scanf("%d", &bin);
    
    while(bin>0){
        resto = bin % 10;
        bin = bin / 10;
        soma = soma + potencia * resto;
        potencia = potencia * 2;
    }
    
    printf("O equivalente em decimal é %d\n", soma);
    

    return 0;
}
