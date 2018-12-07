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
    //inicializa��o dos buckets
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].dadosDoBucket = (int*)malloc(sizeof(int) * quantidade);
    }
    
   
    //sele��o dos itens de qual vai para cada bucket
    for (i = 0; i < quantidade; i++)
    {
    	//os elementos de 0 a 9999 v�o para o primeiro bucket que � o que passar� por RadixSort
        if (primeiro[i] < 10000)
        {
        	
            buckets[0].dadosDoBucket[buckets[0].count] = primeiro[i];
            buckets[0].count++;
        }
        //os restantes, que v�o de 10000 a aproximadamente 32000 v�o sendo distribu�dos entre os 2 outros baldes.
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
    //limpa o espa�o do array que foi enviado a esta fun��o, pois em seguida iremos criar outro que ir� retornar com os dados ordenados.
    free(primeiro);
    int *array = (int*)malloc(sizeof(int) * quantidade);
    
    radixsort(buckets[0].dadosDoBucket,buckets[0].count);
    quicksort(buckets[1].dadosDoBucket,0, buckets[1].count-1);
    heapsort(buckets[2].dadosDoBucket,buckets[2].count);
   
   //aqui � feita a jun��o dos dados dos 3 baldes, para isso � preciso que cada balde v� de de uma valor m�nimo a um m�ximo que � menor que
   // o m�nimo do pr�ximo balde.
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

