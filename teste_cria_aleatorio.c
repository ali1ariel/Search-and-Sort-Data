#include "dados.h"

void main(){
	printf("Oi");
	int b = 10000;
	dados *principal = gerador_de_dados(b);
	dados *primeiro = principal;
	for(int a = 0; a < 100000; a++){
		printf("o dado %d esta na posicao %d\n", principal->informacao, principal->posicao);
		principal = principal->prox;
	}
	return;
//	return primeiro;
}
