/*
 * Programa : countinSort.h
 * Objetivo : implementação de um counting sort
 * Autor : Augusto dos Santos
 * Data : 09/09/2022
 */

int getMaior(int * vetor, int tamVetor);

int getDigit(int numero, int digit);

int getMaiorDigit(int * vetor, int tamVetor, int digit);

int * getFreq(int * vetor, int tamVetor);

int * getFreqDigit(int * vetor, int tamVetor, int digit);

int * getFreqAcumulada(int * vetorFreq, int tamVetor);

int * countingSort(int * vetor, int tamVetor);

int * countingSortDigit(int * vetor, int tamVetor, int digit);