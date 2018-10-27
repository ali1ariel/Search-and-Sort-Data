#include "dados.h"
 
struct bucket 
{
	int *dadosDoBucket;
    int count;
  //  int* value;
};
 
int compareIntegers(const void* first, const void* second)
{
    int x = *((int*)first), y =  *((int*)second);
    if (x == y)
    {
        return 0;
    }
    else if (x < y)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
 
void bucketSort(dados* primeiro,int quantidade)
{
	int array[quantidade];
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].dadosDoBucket = (int*)malloc(sizeof(int) * quantidade);
    }
    
   
    
    for (i = 0; i < quantidade; i++)
    {
        if (primeiro->informacao < (quantidade/3))
        {
        	
            buckets[0].dadosDoBucket[buckets[0].count] = primeiro->informacao;
            buckets[0].count++;
        }
        else if (primeiro->informacao >(2*(quantidade/3)))
        {
            buckets[2].dadosDoBucket[buckets[2].count] = primeiro->informacao;
            buckets[2].count++;

        }
        else
        {
            buckets[1].dadosDoBucket[buckets[1].count] = primeiro->informacao;
            buckets[1].count++;

        }
        primeiro = primeiro->prox;
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        // now using quicksort to sort the elements of buckets
        qsort(buckets[i].dadosDoBucket, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].dadosDoBucket[j];
        }
        k += buckets[i].count;
        free(buckets[i].dadosDoBucket);
    }
    printf("\n After Sorting\n");
    for (k = 0; k<quantidade; k++)
        printf("%d \n", array[k]);   
}
 
int main() {
 /*	srand(time(NULL));
    int array[100];
    for(int a = 0; a < 100; a++) array[a]=(1+rand()%300); */

 	int b = 1000000;
	dados *principal = criaaleatorio(b);
	    	printf("%d B\n", principal->informacao);

    bucketSort(principal, 100000); 

 
 
    return 0;
}
