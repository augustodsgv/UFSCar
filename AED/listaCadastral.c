#include <stdio.h>
#include <stdlib.h>
#include "listaCadastral.h"

typedef struct no{
    int info;
    no * next;
}no;

typedef struct list{
    no * inicio;
    no * final;
}list;

no * criaNo(){
    no * novoNo;
    novoNo = (no *)malloc(sizeof(no));
    novoNo->next = NULL;
}

list * criaLista(){
    no * auxNo = criaNo();
    list * auxLista = (list*)malloc(sizeof(list));
    auxLista->inicio = auxNo;
    auxLista->final = auxNo;
}

void insere(list * lista, int elemento, int ok){
    no * novoNo = criaNo();
    novoNo->info = elemento;
    novoNo->next = lista->final;
    lista->final = novoNo;
    ok = 1;
}

int estaNaLista(list * lista, int elemento){
    no * aux = lista->inicio;
    while(aux != NULL){
        if(aux->next->info == elemento)
            return 1;
        else
            aux = aux->next;
    }
    return 0;
}

void limpaLista(list * lista){
    no * aux = lista->inicio;
    no * dead;
    while(aux != NULL){
        dead = aux;
        aux = aux->next;
        free(dead);
        dead = NULL;
    }
    free(lista);
    lista = NULL;

}

