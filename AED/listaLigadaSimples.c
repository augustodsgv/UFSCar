#include <stdio.h>
#include "listaLigadaSimples.h"

typedef struct no{
    tipo conteudo;
    no * proximo;
}no;

tipo * criaNo(){
    no * novo;
    novo->proximo = NULL;
    return novo;
}

void insere(no** noBase, tipo novoElemento){
    no * novoNo = criaNo;
    novoNo->proximo = (*noBase)->proximo;
    (*noBase)->proximo = novoNo;
    novoNo->conteudo = novoElemento;
}

void retira(no* noAnterior, tipo * elemento){
    *elemento = noAnterior->proximo->conteudo;
    noAnterior->proximo = noAnterior->proximo->proximo;
}