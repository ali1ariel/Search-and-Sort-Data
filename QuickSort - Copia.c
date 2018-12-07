#include "dados.h"
dados* quickSort(dados *recebe){
	dados *primeiro = recebe;
	
	dados *apontaUltimo = primeiro;
	while (apontaUltimo->prox != NULL){
		apontaUltimo = apontaUltimo->prox;
	}
	
	printf("%d__\n", apontaUltimo->dado);
	
	dados *apontaPrimeiro = primeiro->prox;
	dados *pivo = primeiro;
	
	while(1){
		
		while(apontaPrimeiro != apontaUltimo){

			if(apontaUltimo->dado <= pivo->dado){
				
				dados copia = *apontaUltimo;
				if(pivo->ant !=NULL){
					dados *aux = pivo->ant;
					aux->prox = apontaUltimo;
					apontaUltimo->ant = aux;
				} else{
					primeiro = apontaUltimo;				
					apontaUltimo->ant = NULL;
				}
				if(pivo->prox!=NULL){
					dados *aux = pivo->prox;
					aux->ant = apontaUltimo;
					apontaUltimo->prox = aux;
				} else {
					apontaUltimo->prox = NULL;
				}
				
			
				dados *aux = copia.ant;
				aux->prox = pivo;
				pivo->ant = aux;
				if(copia.prox!=NULL){
					aux = copia.prox;
					aux->ant = pivo;
					pivo->prox = aux;	
				} else pivo->prox = NULL;
				
				
				pivo = apontaUltimo;
				
				printf("%d\n", apontaUltimo);
				break;
			}
			apontaUltimo = apontaUltimo->ant;
		}

		while(apontaPrimeiro != apontaUltimo){

			if(apontaPrimeiro->dado > pivo->dado){
			
				dados copia = *apontaPrimeiro;
				
				if(pivo->ant !=NULL){
					dados *aux = pivo->ant;
					aux->prox = apontaPrimeiro;
					apontaPrimeiro->ant = aux;
				} else{				
					apontaPrimeiro->ant = NULL;
				}
				if(pivo->prox!=NULL){
					dados *aux = pivo->prox;
					aux->ant = apontaPrimeiro;
					apontaPrimeiro->prox = aux;
				} else {
					apontaPrimeiro->prox = NULL;
				}
				
				if(copia.ant!=NULL){
					dados *aux = copia.ant;
					aux->prox = pivo;
					pivo->ant = aux;	
				} else pivo->ant = NULL;
				dados *aux = copia.prox;
				aux->ant = pivo;
				pivo->prox = aux;
				

				
				pivo = apontaPrimeiro;
				break;
			}
			apontaPrimeiro = apontaPrimeiro->prox;
		}
		
		if(apontaPrimeiro == apontaUltimo){
			printf("chegou\n");
			dados *aux = apontaPrimeiro->ant;
			aux->prox=pivo;
			pivo->ant = aux;
			aux = apontaPrimeiro->prox;
			aux->ant=pivo;
			pivo->prox = aux;
			break;
		}
		
	}
	

	
	while(pivo->ant != NULL){
	 pivo = pivo->ant;
	 printf("%d - ", pivo->dado);
	}
    return pivo;
    
    
}
/*


	
	

*/
