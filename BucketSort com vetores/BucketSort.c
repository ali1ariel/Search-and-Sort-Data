#include "dados.h"

struct bucket 
{
	int *dadosDoBucket;
    int count;
};


int* bucketSort(int* primeiro,int quantidade)
{
	//numero de buckets
    struct bucket buckets[3];
    int i, j, k;
    //inicialização dos buckets
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].dadosDoBucket = (int*)malloc(sizeof(int) * quantidade);
    }
    
   
    //seleção dos itens de qual vai para cada bucket
    for (i = 0; i < quantidade; i++)
    {
    	//os elementos de 0 a 9999 vão para o primeiro bucket que é o que passará por RadixSort
        if (primeiro[i] < 10000)
        {
        	
            buckets[0].dadosDoBucket[buckets[0].count] = primeiro[i];
            buckets[0].count++;
        }
        //os restantes, que vão de 10000 a aproximadamente 32000 vão sendo distribuídos entre os 2 outros baldes.
        else if (primeiro[i] < 21000)
        {
            buckets[1].dadosDoBucket[buckets[1].count] = primeiro[i];
            buckets[1].count++;

        }
        else
        {
            buckets[2].dadosDoBucket[buckets[2].count] = primeiro[i];
            buckets[2].count++;

        }
    }
    //limpa o espaço do array que foi enviado a esta função, pois em seguida iremos criar outro que irá retornar com os dados ordenados.
    free(primeiro);
    int *array = (int*)malloc(sizeof(int) * quantidade);
    
    radixsort(buckets[0].dadosDoBucket,buckets[0].count);
    quicksort(buckets[1].dadosDoBucket,0, buckets[1].count-1);
    heapsort(buckets[2].dadosDoBucket,buckets[2].count);
   
   //aqui é feita a junção dos dados dos 3 baldes, para isso é preciso que cada balde vá de de uma valor mínimo a um máximo que é menor que
   // o mínimo do próximo balde.
    for (k = 0, i = 0; i < 3; i++)
    {
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].dadosDoBucket[j];
        }
        k += buckets[i].count;
        free(buckets[i].dadosDoBucket);
    }
   return array;
}

