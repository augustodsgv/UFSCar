/**
 * Programa : grafo.c
 * Objetivo : implementação de um grafo usando lista de adjacencia
 * Autor : Augusto dos Santos
 * Data : 30/09/2022
 */

#include <stdio.h>
#include <stdlib.h>

/* Registros*/
// Nó usado para a formação da lista
typedef struct node
{   
    int id;
    struct node * next;
}node;

// Struct do grafo
typedef struct graph
{
    node ** lista;                  // Vetor de nós
    int tam;
}graph;

/* Funções */

// Cria um nó sem "next"
node *
criaNo(int id)
{
    node *novoNo = (node *) malloc (sizeof(node));
    novoNo->id = id;
    novoNo->next = NULL;
    return novoNo;
}

// Cria um grafo vazio de tamanho tam
graph *
criaGrafo(int tam)
{
    graph * novo_grafo;
    novo_grafo = (graph *) malloc (sizeof(graph));

    // Alocando todos os apontadores de nó como NULL
    novo_grafo->lista = (node**) malloc (sizeof(node*) * tam);
    for(int i = 0; i < tam; i++)
        novo_grafo->lista[i] = NULL;

    novo_grafo->tam = tam;

    return novo_grafo;
}

// Insere uma aresta no grafo com origem e destino definidos
int
insereAresta(graph * grafo, int no_origem, int no_destino)
{
    node * aux = grafo->lista[no_origem];

    // Caso o grafo atual não tenha nenhum vizinho
    if (aux == NULL){
        node * novoNo = criaNo(no_destino);
        grafo->lista[no_origem] = novoNo;
        return 1;
    }

    // Procurando a posição no vetor a qual se deve inserir de forma ordenada
    while (aux->next != NULL && aux->next->id < no_destino)
        aux = aux->next;

    // Verificando se o nó já não está na lista
    if (aux->id == no_destino)
        return 0;

    // Criando e alocando o novo no
    node * novoNo = criaNo(no_destino);
    
    // Configurando os ponteiros
    novoNo->next = aux->next;
    aux->next = novoNo;

    return 1;
}

// Forma um grafo a partir de um arquivo de texto 
graph *
formaGrafo(FILE * arquivo)
{
    int n_nos, n_arestas, aux;

    // Criando o grafo
    graph * novoGrafo;
    fscanf(arquivo, "%d", &n_nos);                  // Leitura da quantidade de nós do grafo 
    novoGrafo = criaGrafo(n_nos);

    // montando o grafo
    for(int i = 0; i < n_nos; i++)
    {
        fscanf(arquivo, "%d", &n_arestas);          // Leitura da quantidade de arestas daquele no
        for(int j = 0; j < n_arestas; j++)
        {   
            fscanf(arquivo, "%d", &aux);            // Lendo os nós que fazem aresta com este nó
            insereAresta(novoGrafo, i, aux);        
        }
    }
    return novoGrafo;
}

void
printaGrafo(graph* grafo)
{
    node * aux;
    for(int i = 0; i < grafo->tam; i++)
    {
        printf("* %d -> ", i);
        aux = grafo->lista[i];
        while(aux != NULL)
        {
            printf("%d -> ", aux->id);
            aux = aux->next;
        }
        printf("\n");
    }
}

int
main()
{
    char nomeAquivo[] = "teste.txt";
    FILE * arquivo = fopen(nomeAquivo, "r");
    graph * g1 = formaGrafo(arquivo);
    /*
    insereAresta(g1, 0, 1);
    insereAresta(g1, 0, 2);
    insereAresta(g1, 0, 3);
    insereAresta(g1, 0, 4);
    */
    printaGrafo(g1);

    return 0;
}