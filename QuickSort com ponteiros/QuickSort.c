#include "dados.h"
//função de ordenação, retorna true quando a lista está toda ordenada
bool quickSort(dados *recebe){

	dados *primeiro = recebe;
	dados *apontaPrimeiro = NULL;
	dados *apontaUltimo = primeiro;
	dados *aux = NULL;
	//laço que faz um ponteiro para o ultimo elemento da lista.
	while (apontaUltimo->prox != NULL){
		apontaUltimo = apontaUltimo->prox;
	}
	//seleção do pivô, se não for encontrado nenhum pivô, é porque a lista está ordenada. (verificar função)
	dados *pivo = pivoteamento(primeiro);
	if(pivo==NULL) return true;
	//cria um espaço que é o que será trocado as posições durante o código
	dados *espacoVazio = aloca_dados();
	//todos os ponteiros do pivô são trocados com o do espaço vazio, logo o pivô para de pertencer a lista, sendo substituído pelo espaço vazio
	trocaDeEspacoVazio(espacoVazio,pivo);
	//se o pivo era o primeiro elemento da lista, o ponteiro do primeiro elemento aponta para o espaço vazio, se não,
	//continua apontado para o primeiro padrão.
	if(primeiro == pivo) apontaPrimeiro = espacoVazio;
	else apontaPrimeiro = primeiro;

	
		while(1){
			
			while(apontaPrimeiro != apontaUltimo){
				//se apontaUltimo percorreu toda a lista
				if(apontaUltimo==espacoVazio) break;
				//se o dado do ultimo ponteiro for menor que o pivô
				if(apontaUltimo->dado < pivo->dado){
					//o espaço vazio troca com o elemento que o ponteiro Ultimo apontava.
					trocaDeEspacoVazio(apontaUltimo, espacoVazio);
					//logo o aponta primeiro tem que se mover para o próximo, quem contem essa informação é o atual próximo do ponteiro ultimo,
					//por possuir os ponteiros que pertenciam ao espaço vazio. 
					apontaPrimeiro = apontaUltimo->prox;
					//apontaUltimo passa a apontar para o espaçoVazio.
					apontaUltimo=espacoVazio;
					break;				
				}
				//se não satisfaz nenhum if, o ponteiro se locomove na lista
				if(apontaUltimo->ant==NULL) break;
				apontaUltimo = apontaUltimo->ant;
			}
	
			while(apontaPrimeiro != apontaUltimo){
				
				if(apontaPrimeiro == espacoVazio) break;
				
				if(apontaPrimeiro->dado > pivo->dado){
					
					trocaDeEspacoVazio(apontaPrimeiro, espacoVazio);	
					
					apontaUltimo = apontaPrimeiro->ant;	
					apontaPrimeiro=espacoVazio;				
					break;			
				}
				
				if(apontaPrimeiro->prox==NULL) break;
				apontaPrimeiro = apontaPrimeiro->prox;
			}																																																																																																																																																																																																																																																																																																																																																																																																																																																																													
			//se os dois ponteiros se encontraram então ambos estão apontando para o local vazio, esse local vazio é a nova posição do pivo;
			if((apontaPrimeiro == apontaUltimo)){
				trocaDeEspacoVazio(pivo, espacoVazio);
				//feito a troca, o espaço destinado ao espaço vazio pode ser liberto;
				free(espacoVazio);
				break;
			}
			
			
		} 
	return false;	   
}


//função que escolhe o pivo, se o dado do *primeiro for maior que o dado do *aux, significa que ele está com certeza fora do lugar
//então é decidido como pivô.
dados* pivoteamento(dados *primeiro){
	dados *aux = primeiro->prox;
	while(1){
		if(primeiro->dado > aux->dado){
			return primeiro;
		}
		primeiro = primeiro->prox;
		if(aux->prox == NULL) break;
		aux = aux->prox;
	}
	
	return NULL;
}

//aqui é a função que é feita a trocca de todos os ponteiros, não é só feita a troca entre os nós recebidos, mas também dos nós que
//apontam pra esses recebidos. sendo uma troca total.
void trocaDeEspacoVazio(dados* novo, dados* original){
	dados *aux = NULL;
	if(novo->ant != NULL){
		aux = novo->ant;
		aux->prox = original;
		novo->ant = original->ant;
		original->ant = aux;
		if(novo->ant!=NULL){
			aux = novo->ant;
			aux->prox = novo;
		}
	}
	else if(original->ant != NULL) {
		aux = original->ant;
		aux->prox = novo;
		original->ant = novo->ant;
		novo->ant = aux;
	}
	
	if(novo->prox != NULL){
		aux = novo->prox;
		aux->ant = original;
		novo->prox = original->prox;
		original->prox = aux;
		if(novo->prox!=NULL){
			aux = novo->prox;
			aux->ant = novo;
		}
	}
	else if(original->prox != NULL) {
		aux = original->prox;
		aux->ant = novo;
		original->prox = novo->prox;
		novo->prox = aux;
	}
		
}
