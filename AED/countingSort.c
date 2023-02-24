/*
 * Programa : countinSort.c
 * Objetivo : implementação de um counting sort
 * Autor : Augusto dos Santos
 * Data : 08/09/2022
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "countingSort.h"

int
getMaior(int * vetor, int tamVetor)
{
    int maior = 0;
    for(int i = 0; i < tamVetor; i++)
        if (vetor[i] > maior)
            maior = vetor[i];
    return maior;
}

//retorna o número naquele determinado dígito
int
getDigit(int numero, int digit)
{
    return numero / (int) pow (10,digit) % 10;
}

//devolve o maior elemento do vetor em um digito específico
int
getMaiorDigit(int * vetor, int tamVetor, int digit)
{
    int maior = 0;
    int vetorAtual;
    for(int i = 0; i < tamVetor; i++)
    {   
        vetorAtual = getDigit(vetor[i], digit);
        if (vetorAtual > maior)
            maior = vetorAtual;
    }
    return maior;
}

int *
getFreq(int * vetor, int tamVetor)
{
    int * vetorFreq = (int *) calloc (sizeof(int), getMaior(vetor, tamVetor));
    for(int i = 0; i < tamVetor; i++)
        vetorFreq[vetor[i]]++;
    return vetorFreq;
}

//retorna a frequencia de cada valor de um determinado dígito
int *
getFreqDigit(int * vetor, int tamVetor, int digit)
{
    int * vetorFreq = (int *) calloc (sizeof(int), getMaiorDigit(vetor, tamVetor, digit));
    for(int i = 0; i < tamVetor; i++)
        vetorFreq[getDigit(vetor[i], digit)]++;
    return vetorFreq;
}

int *
getFreqAcumulada(int * vetorFreq, int tamVetor)
{
    int * vetorFreqAcumuladas = (int *) calloc (sizeof(int), tamVetor);

    vetorFreqAcumuladas[0] = vetorFreq[0];
    
    for(int i = 1; i < tamVetor; i++)
        vetorFreqAcumuladas[i] += vetorFreqAcumuladas[i - 1] + vetorFreq[i - 1];
    
    return vetorFreqAcumuladas;
}

int *
countingSort(int * vetor, int tamVetor)
{
    int * vetorOrdenado = (int *) malloc (sizeof(int) * tamVetor);
    int * vetFreq = getFreq(vetor, tamVetor);
    int * vetFreqAcumuladas = getFreqAcumulada(vetFreq, getMaior(vetor, tamVetor) + 1);

    for(int i = tamVetor -1; i >= 0; i--)
        vetorOrdenado[--vetFreqAcumuladas[vetor[i]]] = vetor[i];
    
    for(int i = 0; i < tamVetor; i++)
        vetor[i] = vetorOrdenado[i];

    free(vetFreq);
    free(vetFreqAcumuladas);
    free(vetorOrdenado);
}

int *
countingSortDigit(int * vetor, int tamVetor, int digit)
{
    int * vetorOrdenado = (int *) malloc (sizeof(int) * tamVetor);
    int * vetFreq = getFreqDigit(vetor, tamVetor, digit);
    int * vetFreqAcumuladas = getFreqAcumulada(vetFreq, getMaiorDigit(vetor, tamVetor, digit));

    for(int i = tamVetor -1; i >= 0; i--)
        vetorOrdenado[--vetFreqAcumuladas[getDigit(vetor[i], digit)]] = vetor[i];
    
    for(int i = 0; i < tamVetor; i++)           //copiando o vetor ordenado para o vetor original
        vetor[i] = vetorOrdenado[i];

    free(vetFreq);
    free(vetFreqAcumuladas);
    free(vetorOrdenado);
}

int
main()
{
    int * vetor = (int *) malloc (sizeof(int) * 10);
    vetor[0] = 90;
    vetor[1] = 81;
    vetor[2] = 72;
    vetor[3] = 63;
    vetor[4] = 54;
    vetor[5] = 45;
    vetor[6] = 36;
    vetor[7] = 27;
    vetor[8] = 18;
    vetor[9] = 9;

    countingSort(vetor, 10);
    for(int i = 0; i < 10; i++)
        printf("%d ", vetor[i]);


    return 0;
}