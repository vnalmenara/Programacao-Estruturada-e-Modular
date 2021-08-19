/******************************************************************************

Exercício 1
Dizemos que um inteiro positivo n é perfeito se for igual à soma de seus 
divisores positivos diferentes de n. Dado um inteiro positivo n, verificar 
se n é perfeito.
Exemplo 1: 6 é perfeito, pois 1+2+3 = 6	
Exemplo 2: 20 não é perfeito, pois 1+2+4+5+10 = 22

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num, soma=0, i;
    printf("Entre com um número inteiro: ");
    scanf("%i", &num);
    
    for(i = 1; i < num; i++){
        if(num%i == 0){
            soma = soma + i;
        }
    }
    
    if(num == soma){
        printf("É perfeito!");
    }else{
        printf("Não é perfeito!");
    }
    
    return 0;
}
