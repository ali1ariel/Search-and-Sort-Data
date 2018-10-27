#include "dados.h"

dados* criaaleatorio(int b){
	int c = 250000;
	dados *principal = gerador_de_dados(b,c);
	dados *primeiro = principal;
	for(int a = 0; a < b; a++){
		printf("o dado %d esta na posicao %d\n", principal->informacao, principal->posicao);
		principal = principal->prox;
	}
	return primeiro;
}
