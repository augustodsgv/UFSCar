/**
 * Programa : grafo.c
 * Objetivo : cabeçalho da implementação de um grafo usando lista de adjacencia
 * Autor : Augusto dos Santos
 * Data : 30/09/2022
 */

// Nó usado para a formação da lista
typedef struct node
{   
    int id;
    struct node * next;
}node;

typedef struct graph
{
    node ** lista;                  // Vetor de nós
    int tam;
}graph;

/* Funções */

// Cria um nó sem "next"
int criaNo(int id, node * novoNo);

// Cria um grafo vazio de tamanho tam
int criaGrafo(graph * grafo, int tam);

// Insere uma aresta no grafo com origem e destino definidos
int insereAresta(graph * grafo, int no_origem, int no_destino);

