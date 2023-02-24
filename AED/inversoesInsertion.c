/*
Inversoes insertion
Data : 22/
*/

#include <stdio.h>
#include <stdlib.h>

int
insertionCounting(int * vetor, int tamanho)
{
    int i, j, k, aux, count = 0;
    for(i = 1; i < tamanho; i++)
    {
        j = i;

        while(j >= 0 && vetor[i] >= vetor[j])        //achando a posicao
            j--;

        aux = vetor[i];                             //"rolando" os elementos no vetor
        printf("i : %d, j : %d\n", i, j);
        for(k = i; k > j; k--)
        {
            vetor[k] = vetor[k - 1];
            count++;
        }
        vetor[j] = aux;
    }
    return count;
}


int
main()
{
    int vetor[] = {10, 9, 3, 1, 5, 6, 2, 8, 4, 7};
    printf("%d\n", insertionCounting(vetor, 10));

    for(int i = 0; i < 10; i ++)
        printf("%d ", vetor[i]);
    return 0;
}