#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct data dados;

struct data {
	int dado;
	dados *prox;
	dados *ant;
};

dados* gerador_de_dados(int quantidade);
dados* aloca_dados();
dados* retornaPrimeiro (dados* auxiliar);
void imprimeDados(dados* primeiro);
bool quickSort(dados *recebe);
dados* pivoteamento(dados *primeiro);
void trocaDeEspacoVazio(dados* novo, dados* original);
