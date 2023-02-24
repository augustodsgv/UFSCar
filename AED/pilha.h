/*
Aluno : Augusto dos Santos Gomes Vaz
RA : 800268
Programa : Biblioteca com implementacao de uma pilha
*/
//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definicoes
#define N 50 //define o tamanho maximo da pilha que se deseja trabalhar

//TAD pilha
typedef struct pilha{
  int vetor[N];
  int tamanho;
}pilha;

//funcoes elementares
void criaPilha(pilha * p){//cria uma pilha começando do 0
  p->tamanho = 0;
}

int vazia(pilha p){//retorna verdadeiro se a pilha está vazia
  if (p.tamanho == 0)
    return 1;
  else
    return 0;
}

int cheia(pilha p){//retorna verdadeiro se a pilha está cheia
  if (p.tamanho == N)
    return 1;
  else
    return 0;
}

void empilha(pilha * p, int n){//aumenta o tamanho da pilha coloca o n no topo
  if(!cheia(*p)){
    p->vetor[p->tamanho++] = n;
    
  }else{
    printf("A pilha está cheia\n");
  }
  
}


int desempilha(pilha * p){//devolve o último termo e o retira da pilha
  if (!vazia(*p)){
    return p->vetor[--p->tamanho];

  }else{
    printf("A lista está vazia\n");
    return 0;
  }
}

int espiar(pilha p){//apenas devolve o valor do último elemento da pilha
  return p.vetor[p.tamanho - 1];
}

int tamanhoPilha(pilha p){
  return p.tamanho;
}