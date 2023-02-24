/*
Programa : countingSort2
Descrição : Nova implementação do countingSort
Autor : Augusto dos Santos
Data : 20/09/2022
*/
#include <stdio.h>
#include <stdlib.h>


void countingSort2 ( int v [] , int n , int R ) { 
    int valor , i ; 
    int * ocorr_pred , * aux ; 
    ocorr_pred = malloc (( R + 1 ) * sizeof( int )); 
    aux = malloc ( n * sizeof( int )); 
    for ( valor = 0 ; valor <= R ; valor ++ ) 
        ocorr_pred [ valor ] = 0 ; 
        
    for ( i = n ; i > 0 ; i -- ) {                                                   // PODE   
        valor = v [ i ];    
        ocorr_pred [ valor + 1 ] += 1 ; 
    } 
 // ocorr_pred[valor] é o núm. de ocorrências de valor - 1 
    for ( valor = 1 ; valor <= R ; valor ++)                                        // NAO PODE
        ocorr_pred [ valor ] += ocorr_pred [ valor - 1 ]; 
 // ocorr_pred[valor] é o núm. de ocorrs dos predecessores de 
 // valor. Logo, a cadeia de elementos iguais a valor deve 
 // começar no índice ocorr_pred[valor] no vetor ordenado. 
    for ( i = n ; i >= 0 ; i -- ) {                                             // PODE 
        valor = v [ i ]; 
        aux [ ocorr_pred [ valor ]] = v [ i ]; 
        ocorr_pred [ valor ]++; // atualiza o número de predecessores 
 } 
 // aux[0 .. n-1] está em ordem crescente 
    for ( i = n ; i >= 0 ; -- i ) v [ i ] = aux [ i ];                           // PODE
    free ( ocorr_pred ); 
    free ( aux ); 
} 


int
main()
{
    //int vetor = (int*)malloc(sizeof(int) * 10);
    int vetor [] = {4, 5, 1, 4, 8, 9, 4, 7, 7, 11};
    countingSort2(vetor, 10, 12);
    for (int i = 0; i < 10; i++)
        printf("%d ", vetor[i]);


    return 0;
}