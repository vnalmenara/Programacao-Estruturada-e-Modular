/******************************************************************************

2) Faça um programa (ou uma função) que some os elementos da diagonal 
principal de uma matriz quadrada.

*******************************************************************************/
#include <stdio.h>

void somaDiagonalPrincipal(int dimensao, int M[dimensao][dimensao]){
    
    int i, soma=0;
    
    for(i = 0; i< dimensao; i++){
        soma = soma + M[i][i];
    }
    
    printf("A soma da diagonal principal da matriz de [%d][%d] é %d.", dimensao, dimensao, soma);
}

int main()
{
    
    int dimensao, l, c;
    
    printf("Informe a dimensão da matriz quadrada: ");
    scanf ("%d", &dimensao);
    
    int M[dimensao][dimensao];
    
    for(l = 0; l< dimensao; l++){
        for(c = 0; c< dimensao; c++){
            printf("Informe o valor na posição [%d][%d] da matriz: ", l, c);
            scanf("%d", &M[l][c]);
        }
    }
    
    somaDiagonalPrincipal(dimensao, M);
    
    /* for(l = 0; l< dimensao; l++){
        printf("\n");
        for(c = 0; c< dimensao; c++){
            printf("%d  ", M[l][c]);
        }
    } */
    
    return 0;
}
