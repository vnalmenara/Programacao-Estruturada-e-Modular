/******************************************************************************
Projeto Validador de CNPJ
------------------------------------

Este projeto destina-se à fixação dos conceitos aprendidos até aqui (vetores, strings e, especialmente, funções e procedimentos).
Como a lógica de validação do CNPJ é muito similar à do CPF, você poderá reforçar suas habilidades de programação.
O algoritmo é explicado no link:

http://www.macoratti.net/alg_cnpj.htm


1) No link acima você encontra a explicação do algoritmo usado pela Receita Federal para validação de um CNPJ.
Estude-o e monte uma planilha em Excel ou Calc para implementar a ideia.

2) Crie um código "base" em C que valida o primeiro dígito verificador. Faça um CTRL+C e CTRL+V com atenção, visto que o algoritmo para o segundo dígito é muito parecido com o do primeiro.

3) Agora vamos melhorar o código anterior com o uso de uma função para validação de um dígito, que você escreverá uma vez e usará duas vezes.

4) Vamos melhorar mais ainda o código anterior trabalhando na nova entrada dos dígitos do CNPJ. Vamos lê-los com uma string e processá-la adequadamente.


*******************************************************************************/

#include <stdio.h>
#include<stdbool.h>
#include<string.h>

bool repetidos(int cnpj[]){   
    int i;
    for(i=0; i<13; i++){
        if(cnpj[i] != cnpj[i+1]){
            return false;
        }
    }
    return true;
}

bool verificaDigito(int cnpj[], int mult[], int n){
    int i, soma=0, resto=0;
    
	for(i=0; i<n; i++){	
	    soma = soma + cnpj[i] * mult[i];
	}
	
	resto = ((soma*10) % 11)%10;
	
	return (resto == cnpj[n]);
}

void converterEntrada(char entrada[], int cnpj[]){
    int i, j, tamanhoEntrada;
    
	for(j=0;j<14;j++){
	    cnpj[j] = 0;
	}
	
	tamanhoEntrada = strlen(entrada);
	j=13;
	
	for(i=tamanhoEntrada-1;i>=0;i--){
	    if(entrada[i]>='0' && entrada[i]<='9'){ 
	        cnpj[j] = entrada[i] - '0';  
	        j--;
	        if(j<0){
	           return; 
	        } 
	    }
	}
}

int main()
{
    int cnpj[14];
	char entrada[50];
	int validador1[12]={5,4,3,2,9,8,7,6,5,4,3,2};
	int validador2[13]={6,5,4,3,2,9,8,7,6,5,4,3,2};
	
	printf("Entre com os 14 digitos do CNPJ:");
	fgets(entrada, 50, stdin);
	
	converterEntrada(entrada, cnpj);
	
	if(!repetidos(cnpj) && verificaDigito(cnpj, validador1, 12) && verificaDigito(cnpj, validador2, 13)){
		printf("\nCNPJ válido.\n");
	}
	else{
		printf("\nCNPJ inválido.");
	}
}
