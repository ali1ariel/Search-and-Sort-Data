#include "dados.h"

//gera o valor de cada dado e seus ponteiros de lista
dados* gerador_de_dados(int quantidade){
	srand(time(NULL));	
	dados *primeiro = aloca_dados();
	dados *aux = primeiro;
	for(int a = 0; a<quantidade ; a++){
		//densidade dos dados
		aux->dado = rand()%200;
		if(a!=quantidade-1) {
			dados *proximo = aloca_dados();
			aux->prox = proximo;
			proximo->ant = aux;
			aux = proximo;
		}
	
	}
	return primeiro;
}

//Função que aloca um novo nó da lista e define seus ponteiros nulos para facilitar o código
dados* aloca_dados(){
	dados *retorno =  (dados*)malloc(sizeof(dados));
	retorno->ant=NULL;
	retorno->prox=NULL;
	return retorno;
}

//função que percorre os nós até o primeiro elemento da lista
dados* retornaPrimeiro (dados* auxiliar){
	while(1){
		if(auxiliar->ant!=NULL) auxiliar = auxiliar->ant;
		else break;
	}

	return auxiliar;
}

//função que imprime os dados a partir do que recebe até o final da lista
void imprimeDados(dados* primeiro){
	dados *imprime = primeiro;
	while (1){
		printf("dado: %d\n", imprime->dado);
		if (imprime->prox==NULL) break;
		imprime = imprime->prox;
	}
}


main(){
	
	int quantidade = 1000000;
	dados *recebe = gerador_de_dados(quantidade);
	
	/*printf("dados sem ordem:\n");
	imprimeDados(recebe);*/
	
	//laço principal, assim que faz uma ordenação é feito novamente a seleção do primeiro elemento da lista
	bool ordena = false;
	do{
		ordena = quickSort(recebe);
		recebe = retornaPrimeiro(recebe);
	}while(ordena==false);
	

	/*printf("dados ordenados:\n");
	imprimeDados(recebe);*/
	return 0;
}

