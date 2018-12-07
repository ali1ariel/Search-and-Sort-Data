#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//FUN��ES DO GERADOR DE DADOS
int* gerador_de_dados(int quantidade);
int* bucketSort(int* primeiro,int quantidade);
void quicksort(int *a, int menor, int maior);
void radixsort(int vetor[], int tamanho);
void heapsort(int a[], int n) ;
void peneira(int *vet, int raiz, int fundo);
