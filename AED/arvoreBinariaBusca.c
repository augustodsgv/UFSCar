#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinariaBusca.h"

node* criaNo(int valor){
    node * novoNo = (node*)malloc(sizeof(node));
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    novoNo->info = valor;
}

int push(node * noRaiz, int novoElemento){//funfando liso
    //caso seja igual ao elemento raiz
    if(novoElemento == noRaiz->info)
        return 0;//nao pode haver elementos repetidos

    //caso seja maior que o elemento raiz
    if(novoElemento > noRaiz->info){
        if(noRaiz->dir == NULL){
            node * novoNo = criaNo(novoElemento);
            noRaiz->dir = novoNo;
            return 1;
        }
        return push(noRaiz->dir, novoElemento);
    }
    //caso seja menor que o elemento raiz
    if(noRaiz->esq == NULL){
        node * novoNo = criaNo(novoElemento);
        noRaiz->esq = novoNo;
        return 1;
    }
    return push(noRaiz->esq, novoElemento);
}

int estaNaArvore(node * noRaiz, int elemento){
    //caso seja o elemento
    if(noRaiz->info == elemento)
        return 1;
    //caso a raiz seja maior que o elemento
    if(noRaiz->info > elemento)
        if(noRaiz->esq == NULL)//caso o "no raiz" seja uma folha
            return 0;

        return estaNaArvore(noRaiz->esq, elemento);

    if(noRaiz->dir == NULL)//caso seja um nó filho
        return 0;
    return estaNaArvore(noRaiz, elemento);
}
