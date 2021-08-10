/******************************************************************************

Projeto Calendário Permanente:
https://p.calameoassets.com/100318202814-34a9c063ecaf9fc19c30483d0a7f0160/p1.jpg

*******************************************************************************/
#include <stdio.h>
#include <locale.h>

int procuraLinha (int linha, int coluna, int M[linha][coluna], int procurado){

    int i, j;
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            if(M[i][j] == procurado){
                return i;
            }
        }
    }
}

//Calendário permanente de 1901 a 2092

int A1[28][4];

int A2[28][4];

int B[28][12] = { 
{4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
{5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
{6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
{0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
{2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
{3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
{4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
{5, 1, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
{0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
{1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
{2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
{3, 6, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
{5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
{6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
{0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
{1, 4, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
{3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
{4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
{5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
{6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
{1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
{2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
{3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
{4, 0, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
{6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
{0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
{1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
{2, 5, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1}
};

int C[7][6];

int main (){
    
    int l, c, x;
    
//populando a tabela A1
    x = -3;
    for (c = 0; c < 4; c++){
        for (l = 0; l < 28; l++, x++){
            if (x < 1){
                A1[l][c] = -1;
            }
            else if (x < 100){
                A1[l][c] = x;
            }
            else if (x == 100){
                A1[l][c] = 0;
            } 
            else{
                A1[l][c] = -1; 
            }
        }
    }
    

//populando a tabela A2
    x = -19;
    for (c = 0; c < 4; c++){
        for (l = 0; l < 28; l++, x++){
            if (x < 1){
                A2[l][c] = -1;
            }
            else{
                A2[l][c] = x; 
            }
        }
    }


//populando a tabela C
    x = 1;
    for (c = 0; c < 6; c++){
        for (l = 0; l < 7; l++, x++){
            if (x > 37){
                C[l][c] = -1;
            }
            else{
                C[l][c] = x;
            }
        }
    }

    int dia, mes, ano, linha, procurado, resposta;
    
    printf ("\nEntre com uma data no formato DD/MM/AAAA: ");
    scanf ("%d/%d/%d", &dia, &mes, &ano);

    if (ano < 1901 || ano > 2092){
        printf ("Erro! O ano deve ser de 1901 a 2092.\n");
    } 
    else{
        if(ano <= 2000){
            linha = procuraLinha(28, 4, A1, ano%100);
        }
        else{
            linha = procuraLinha(28, 4, A2, ano%100);
        }
        
        procurado = dia + B[linha][mes-1];
        
        resposta = procuraLinha(7, 6, C, procurado);
        switch (resposta){
           case 0:
            printf("A data em referência foi um Domingo.");
           break;
           
           case 1:
            printf("A data em referência foi uma Segunda-feira.");
           break;
           
           case 2:
            printf("A data em referência foi uma Terça-feira.");
           break;
           
           case 3:
            printf("A data em referência foi uma Quarta-feira.");
           break;
           
           case 4:
            printf("A data em referência foi uma Quinta-feira.");
           break;
           
           case 5:
            printf("A data em referência foi uma Sexta-feira.");
           break;
           
           case 6:
            printf("A data em referência foi um Sábado.");
           break;
           
           default:
            printf("Erro.");
        }
        
    }

    return 0;
}
