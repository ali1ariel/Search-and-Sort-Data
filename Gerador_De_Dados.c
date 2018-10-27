#include "dados.h"

dados* gerador_de_dados(int quantidade){
	srand(time(NULL));	 
	dados *primeiro = NULL;
	dados *atual = NULL;
	for(int a = 0; a < 100000; a++){
		dados *gerando = aloca_dado();
		gerando->informacao = (1+(rand()%quantidade));
	
		if(a==0){
			gerando->posicao = 1;
			primeiro = gerando;
			atual = primeiro;
		} else {
			gerando->posicao = atual->posicao+1;
			atual->prox = gerando;
			atual = gerando;
		}
	}
	return primeiro;
}


dados* aloca_dado(){
	dados *alocacao = (dados*)malloc(sizeof(dados));
	alocacao->informacao = NULL;
	alocacao->posicao = NULL;
	alocacao->prox=NULL;	
	return alocacao;
}
