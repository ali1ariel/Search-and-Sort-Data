#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct data dados;
struct data {
	int informacao;
	int posicao;
	dados *prox;
};




//FUN��ES DO GERADOR DE DADOS
dados* gerador_de_dados(int quantidade);
dados* aloca_dado();
dados* criaaleatorio(int b);

