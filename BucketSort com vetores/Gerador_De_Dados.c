#include "dados.h"

//gera um vetor com a quantidade exigida e valores aleatórios para os itens do vetor
int* gerador_de_dados(int quantidade){
	srand(time(NULL));	
	int *vetor = (int*)malloc(sizeof(int)*quantidade);
	for(int a = 0; a<quantidade ; a++){
		vetor[a] = rand();
	
	}
	return vetor;
}

//imprime dados do vetor recebido
void imprimeDados(int* recebe, int quantidade){
	for(int i = 0; i < quantidade; i++){
		printf("%dn\n", recebe[i]);
	}
}

main(){
	int quantidade = 100000;
	int *recebe = gerador_de_dados(quantidade);
	recebe = bucketSort(recebe, quantidade);
	printf("\n\nValores ordenados\n");
	imprimeDados(recebe, quantidade);
	return 0;
}
