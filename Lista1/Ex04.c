/******************************************************************************

Exercício 4
Dados n e uma sequência de n números inteiros, determinar quantos segmentos 
de números iguais consecutivos compõem essa sequência.
Exemplo: A seguinte sequência é formada por 5 segmentos de números iguais: 
5, 2, 2, 3, 4, 4, 4, 4, 1, 1 Ou seja, contarei assim: 
<<5>>,<< 2, 2>>,<< 3>>,<< 4, 4, 4, 4>>, <<1, 1>> Portanto, tenho 5 grupos.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int x, num, contador, grupo=1;
    
    printf("Informe quantos números serão inseridos: ");
    scanf("%i", &x);
    
    int vetor[x];
    
    for(contador = 1; contador >= x; contador++){
        printf("Informe um número inteiro: ");
        scanf("%i", &num);
        
        vetor[contador-1] = num;
        
        if(contador != 1){
            if(num != numAnterior){
                grupo++;
            }
        }
        
        numAnterior = num;
        
    }
    
    printf("A sequência digitada foi: \n");
    
    for(contador = 1; contador >= x; contador++){
        printf("%i ", vetor[contador-1]);
    }
    
    printf("\nA quantidade de grupos númericos digitado foi: %i", grupo);
    
    return 0;
}
