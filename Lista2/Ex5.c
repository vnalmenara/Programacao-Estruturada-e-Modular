/******************************************************************************

Resolva o problema chamado de o Campo das Minhocas:
https://www.urionlinejudge.com.br/judge/pt/problems/view/2293

*******************************************************************************/
#include <stdio.h>

int somaN(int N, int M, int CampoMinhocas[N][M], int linha){
    
    int soma=0;
    for(int c = 0; c< M; c++){
        soma = soma + CampoMinhocas[linha][c];
    }
    
    return soma;
}

int somaM(int N, int M, int CampoMinhocas[N][M], int coluna){
    
    int soma=0;
    for(int l = 0; l< N; l++){
        soma = soma + CampoMinhocas[l][coluna];
    }
    
    return soma;
}

int main()
{
    int N, M, l, c, maximo=0, soma=0;
    
    printf("Informe a dimensão N da matriz: ");
    scanf ("%d", &N);
    
    printf("Informe a dimensão M da matriz: ");
    scanf ("%d", &M);
    
    int CampoMinhocas[N][M];
    
    for(l = 0; l< N; l++){
        for(c = 0; c< M; c++){
            printf("Informe o valor na posição [%d][%d] da matriz: ", l, c);
            scanf("%d", &CampoMinhocas[l][c]);
        }
    }
    
    for(l = 0; l< N; l++){
        soma = somaN(N, M, CampoMinhocas, l);
        
        printf("\n%d", soma);
        
        if(soma > maximo){
            maximo = soma;
        }
    }
    
    for(c = 0; c< M; c++){
        soma = somaM(N, M, CampoMinhocas, c);
        
        printf("\n%d", soma);
        
        if(soma > maximo){
            maximo = soma;
        }
    }
    
    printf("\nO número de minhocas esperado na colheita é %d", maximo);

    return 0;
}
