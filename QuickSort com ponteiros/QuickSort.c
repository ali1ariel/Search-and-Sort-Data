#include "dados.h"
//fun��o de ordena��o, retorna true quando a lista est� toda ordenada
bool quickSort(dados *recebe){

	dados *primeiro = recebe;
	dados *apontaPrimeiro = NULL;
	dados *apontaUltimo = primeiro;
	dados *aux = NULL;
	//la�o que faz um ponteiro para o ultimo elemento da lista.
	while (apontaUltimo->prox != NULL){
		apontaUltimo = apontaUltimo->prox;
	}
	//sele��o do piv�, se n�o for encontrado nenhum piv�, � porque a lista est� ordenada. (verificar fun��o)
	dados *pivo = pivoteamento(primeiro);
	if(pivo==NULL) return true;
	//cria um espa�o que � o que ser� trocado as posi��es durante o c�digo
	dados *espacoVazio = aloca_dados();
	//todos os ponteiros do piv� s�o trocados com o do espa�o vazio, logo o piv� para de pertencer a lista, sendo substitu�do pelo espa�o vazio
	trocaDeEspacoVazio(espacoVazio,pivo);
	//se o pivo era o primeiro elemento da lista, o ponteiro do primeiro elemento aponta para o espa�o vazio, se n�o,
	//continua apontado para o primeiro padr�o.
	if(primeiro == pivo) apontaPrimeiro = espacoVazio;
	else apontaPrimeiro = primeiro;

	
		while(1){
			
			while(apontaPrimeiro != apontaUltimo){
				//se apontaUltimo percorreu toda a lista
				if(apontaUltimo==espacoVazio) break;
				//se o dado do ultimo ponteiro for menor que o piv�
				if(apontaUltimo->dado < pivo->dado){
					//o espa�o vazio troca com o elemento que o ponteiro Ultimo apontava.
					trocaDeEspacoVazio(apontaUltimo, espacoVazio);
					//logo o aponta primeiro tem que se mover para o pr�ximo, quem contem essa informa��o � o atual pr�ximo do ponteiro ultimo,
					//por possuir os ponteiros que pertenciam ao espa�o vazio. 
					apontaPrimeiro = apontaUltimo->prox;
					//apontaUltimo passa a apontar para o espa�oVazio.
					apontaUltimo=espacoVazio;
					break;				
				}
				//se n�o satisfaz nenhum if, o ponteiro se locomove na lista
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
			//se os dois ponteiros se encontraram ent�o ambos est�o apontando para o local vazio, esse local vazio � a nova posi��o do pivo;
			if((apontaPrimeiro == apontaUltimo)){
				trocaDeEspacoVazio(pivo, espacoVazio);
				//feito a troca, o espa�o destinado ao espa�o vazio pode ser liberto;
				free(espacoVazio);
				break;
			}
			
			
		} 
	return false;	   
}


//fun��o que escolhe o pivo, se o dado do *primeiro for maior que o dado do *aux, significa que ele est� com certeza fora do lugar
//ent�o � decidido como piv�.
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

//aqui � a fun��o que � feita a trocca de todos os ponteiros, n�o � s� feita a troca entre os n�s recebidos, mas tamb�m dos n�s que
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
