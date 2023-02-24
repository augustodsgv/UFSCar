#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TAM 3
void criaMatriz(int matriz[][TAM]){//cria a matriz com os valores em 0
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            matriz[i][j] = 0;
        }
    }
}

int somaCerta(){//devolve o valor da soma de uma linha/coluna/diagonal de uma matriz de tamanho TAM
    int soma = 0;
    for(int i = 1; i <= pow(TAM, 2); i++){
        soma = soma + i;
    }
    return soma/TAM;
}

int testaLinhas(int matriz[][TAM]){//testa se a soma das linhas possui o valor certo
    for(int i = 0; i < TAM; i++){
        int soma = 0;
        for(int k = 0; k < TAM; k++)
            soma = soma + matriz[i][k];
        if(soma != somaCerta())
            return 0;
    }
    return 1;

}

int testaColunas(int matriz[][TAM]){//testa se a soma das colunas possui o valor certo
    for(int i = 0; i < TAM; i++){
        int soma = 0;
        for(int k = 0; k < TAM; k++)
            soma = soma + matriz[k][i];
        if(soma != somaCerta())
            return 0;
    }
    return 1;

}

int testaDiagonais(int matriz[][TAM]){//testa se a soma das diagonais possui o valor certo
    //diagonal principal
    int soma = 0;
    for(int k = 0; k < TAM; k++)
        soma = soma + matriz[k][k];

    if(soma != somaCerta())
        return 0; 


    soma = 0;
    for(int k = 0; k < TAM; k++)
        soma = soma + matriz[TAM - 1 - k][k];

    if(soma != somaCerta())
        return 0;

    return 1;
}

void retornaNumeros(int vetor[]){//retorna os valores a serem usados na 
    for(int i = 0; i < pow(TAM, 2); i++)
        vetor[i] = i+1;
}

int main(){
    int * numeros = (int*)malloc(pow(TAM, 2) *  sizeof(int));
    retornaNumeros(numeros);
    int matrizCerta[][TAM] = {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}};
    int mat[TAM][TAM];
    criaMatriz(mat);
    printf("Soma = %d\n", somaCerta());
    printf("A linhas da matriz certa esta : %d\n", testaLinhas(matrizCerta));
    printf("As colunas da matriz certa esta : %d\n", testaColunas(matrizCerta));
    printf("As Diagonais da matriz certa estao : %d\n", testaDiagonais(matrizCerta));

    for(int i = 0; i < pow(TAM, 2); i++){
        printf("elementos %d : %d\n", i + 1, numeros[i]);
    }

    return 0;
}