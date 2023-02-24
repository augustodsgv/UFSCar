/*
Aluno : Augusto dos Santos Gomes Vaz
RA : 800268
programa : Biblioteca com uma implementação de uma TAD fila com suas funcoes primitivas
*/
//bibliotecas
#include <stdio.h>

//definicoes
#define N 50 //define o tamanho maximo de filas. Também indica a metade

//TAD fila
typedef struct fila{
    int vetor[N];//fila em si
    int ini;//controle do inicio do vetor
    int fim;//controle do fim do vetor
}fila;

//funcoes primitivas
void criaFila(fila * q){//cria a fila com os elementos no início do vetor
    q->ini = 0;
    q->fim = 0;
}

int vazia(fila q){//Devolve true se a fila estiver vazia
    if(q.fim == q.ini)
        return 1;
    else
        return 0;
}

int cheia(fila q){//Devolve True se a fila estiver cheia
    if (q.fim == N)
        return 1;
    return 0;
}

void enfileira(fila * q, int n){//coloca a o parametro n no final da fila
    if(!cheia(*q))
        q->vetor[q->fim++] = n;
    else
        printf("A fila esta cheia");
}

int desenfila(fila * q){//retira o primeiro elemento da fila e o retorna 
    if(!vazia(*q))
        return q->vetor[q->ini++];
    else
        printf("A pilha esta vazia\n");
        return 0;
}

int espiar(fila q){//devolve o primeiro elemento da fila sem o retirar
    return q.vetor[q.ini];
}

int tamanho(fila q){//devolve o tamanho da fila
    return q.fim - q.ini;
}

