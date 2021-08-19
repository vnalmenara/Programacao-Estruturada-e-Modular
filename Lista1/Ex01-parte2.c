/******************************************************************************

Exercício 1 - parte II
Quais são os números perfeitos até 10.000?

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num, soma=0, i;
    for(num=1; num<10000; num++){
        soma=0;
        for(i = 1; i < num; i++){
            if(num%i == 0){
                soma = soma + i;
            }
        }
        
        if(num == soma){
            printf("\nO número %i É perfeito!", num);
        }
        
    }
    
    return 0;
}
