#include "dados.h"

void quicksort(int *a, int menor, int maior) {
    int i, j, pivo, aux;
     
    i = menor;
    j = maior;
    //o elemento que est� no meio do vetor, o piv�
    pivo = a[(menor + maior) / 2];
    
    //enquanto i n�o for maior que j
    while(i <= j) {
    	//enquanto o elemento de a na posi��o i for menor que o piv�, sai quando acha um elemento fora do lugar
        while(a[i] < pivo && i < maior) {
            i++;
        }
        //enquanto o elemento de a na posi��o i for maior que o piv�, sai quando acha um elemento fora do lugar
        while(a[j] > pivo && j > menor) {
            j--;
        }
        
        //no caso, se i ainda n�o j, os 2 elementos que est�o fora do lugar s�o trocados, e o c�digo continua sendo executado
        if(i <= j) {
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            i++;
            j--;
        }
        
    //se i > j, o while � cortado;
    }
     
    //se j ainda n�o chegou na extremidade menor, o c�digo � chamado recursivamente para ordenar os dados de menor at� j
    if(j > menor) {
        quicksort(a, menor, j);
    }
    //se i ainda n�o chegou na extremidade maior, o c�digo � chamado recursivamente para ordenar os dados de i at� maior;
    if(i < maior) {
        quicksort(a, i, maior);
    }
}


void radixsort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;
	
    b = (int *)malloc(tamanho*sizeof(int));
	
	//procura o maior elemento do vetor
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

	//enquanto h� casas decimais
    while (maior/exp > 0) {
    	
        int Bucket[10] = { 0 };
        //aqui define o tamanho de cada bucket nessa execu��o
    	for (i = 0; i < tamanho; i++)
    	    Bucket[(vetor[i] / exp) % 10]++;
    	//faz os buckets terem uma contagem cumulativa    
    	for (i = 1; i < 10; i++)
    	    Bucket[i] += Bucket[i - 1];
    	//de tr�s pra frente, o valor de vetor na posi��o i � mandando para o elemento de p em uma f�rmula.
    	for (i = tamanho - 1; i >= 0; i--)
    		//a posi��o de b, em que se localiza a ordem da casa decimal avaliada.
    	    b[--Bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}



void heapsort(int *vet, int n) {
	int i, tmp;
	//i � igual a metade do vetor, enquanto n�o for menor que 0, executa
	//aqui � criado o Max heap
	for (i = (n / 2); i >= 0; i--) {
	//� enviado pra fun��o primeiramente, 		 metade do vetor, e nas outras execu��es vai aumentando at� enviar todo o vetor;
		peneira(vet, i, n - 1);
	}
	
	//nessa ultima parte do c�digo, a cada execu��o, o maior valor est� na posi��o 0 do vetor, � passado pra i que � a ultima posi��o n�o ordenada;
	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		// � criado o Max Heap no array reduzido;
		peneira(vet, 0, i-1);
	}
}

void peneira(int *vet, int raiz, int fundo) {
	int filhoMax, tmp;
	//variavel de controle;
	bool pronto = false;
	//enquanto n�o est� pronto.
	while ((raiz*2 <= fundo) && (!pronto)) {
		//se raiz * 2 == posi��o da extremidade final do vetor, filhoMax recebe esse n�mero; 
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		
		//sen�o se o vetor na posicao raiz*2 tiver um elemento maior que o pr�ximo elemento, filhoMax recebe o numero equivalente a essa posi��o.
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		//sen�o recebe o numero equivalente a posi��o do pr�ximo;
		else {
			filhoMax = raiz * 2 + 1;
		}
		//se o elemento da raiz foi maior que o elemento da posi��o determinada anteriormente, esses elementos trocam de posi��o e raiz recebe
		//o valor presente na vari�vel filho max; e o while continua sendo executado;
		if (vet[raiz] < vet[filhoMax]) {
			tmp = vet[raiz];
			vet[raiz] = vet[filhoMax];
			vet[filhoMax] = tmp;
			raiz = filhoMax;
	    }
	    //sen�o, o while � cortado;
		else {
	      pronto = true;
		}
  }
}
