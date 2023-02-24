#include <stdio.h>
#include "bubbleSort.h"

void bubbleSort(int vetor[], int tamVetor){
    for(int i = 0; i < tamVetor; i++)//número de vezes que vai percorrer o vetor 'o tamanho
        for(int j = 1; j < tamVetor - i; j++)//considera que, em cada passada o ultimo elemento está posicionado corretamente, e assim por diante
            if(vetor[j-1] > vetor[j]){//par "desordenado"
                int aux = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = aux;
            }

}