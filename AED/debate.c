/* 
ATIVIDADE:
Debate
Voltemos à quinta série. Não, não vamos fazer trocadilhos ofensivos. Neste
problema você deve ajudar o senhor William, professor de Geografia que adora
fazer debates entre os alunos.
Como atividade de suas aulas, William decidiu fazer um debate entre os
alunos separando-os em dois grupos, os quais devem defender ideias opostas.
Para montar esses grupos, o professor pediu para que cada aluno anotasse o
nome de um ou mais estudantes para os quais deseja fazer perguntas. Mas,
para isso, há a restrição de que uma pergunta deve ser feita por alguém de um
grupo e respondida por algum participante do grupo oposto. não deve haver
interação entre membros do mesmo grupo.
Por exemplo, considere que dois grupos devem ser formados com os alunos
João, Paulo, Maria e Sara. Caso João queira perguntar a Paulo e Maria, João
deve estar em um grupo, enquanto Paulo e Maria em outro. Assim, Paulo e
Maria não poderão fazer perguntas um ao outro. Nesse cenário, Sara não poderá
perguntar a João e também a alguém do grupo com Paulo e Maria, senão não
poderia ser colocada em qualquer grupo sem ferir as restriçõees. Caso Sara decida
por fazer perguntas apenas a Paulo, por exemplo, ela será do grupo de João.
Sua tarefa é ajudar o professor a decidir se é possível separar os alunos em
dois grupos sem ferir qualquer restrição. Para isso, você deve fazer um programa
que receba a lista de alunos, identificados por seu npumero de chamada, e seus
interesses em fazer perguntas. Ao final, responda se é possível ou não tal divisão.
Entrada
Os dados de cada caso de teste estão armazenado em um arquivo com extens˜ao
“.in”. Assim, a única linha a ser lida da entrada padrão contém o nome de
tal arquivo. Esse nome deve ser usado para ler o arquivo, que se encontra na
mesma pasta que o executável.
A primeira linha de cada arquivo contém um único inteiro positivo, indicando
quantas instâncias estão contidas no arquivo. A primeira linha de cada instância
indica o npumero N (2 ≤ N ≤ 1000) de estudantes na turma a ser analisada.
As pr´oximas N linhas contém informações sobre a vontade de cada estudante
fazer perguntas. Mais precisamente, a primeira das N linhas corresponde ao
estudante 0, a seguinte ao estudante 1, e assim por diante. Cada uma dessas
linhas come¸ca com um inteiro M (1 ≤ M ≤ N/2) que indica a quantos alunos o
estudante corrente deseja fazer perguntas. Esse inteiro M é seguido, na mesma
linha, de M valores correspondentes aos npumeros dos alunos alvos das quest˜oes.
Note que os npumeros de identifica¸c˜ao dos estudantes come¸cam em 0 e v˜ao até
N − 1.

Saída
Para cada instância do arquivo com os dados do caso de teste, seu programa
deve imprimir a palavra “Impossivel” em uma nova linha, caso não seja possível
*/

/**
 * Programa : debate.c
 * Objetivo : Resolução do desafio de formar grupos para um debate
 * Autor : Augusto dos Santos
 * Data : 30/09/2022
 */


/*_______________________________________________Grafos.c_______________________________________________*/
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
    novo_grafo = (graph*) malloc (sizeof(graph));

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

    /* Tirando por questões de performance 

    // Procurando a posição no vetor a qual se deve inserir de forma ordenada
    while (aux->next != NULL && aux->next->id < no_destino)
        aux = aux->next;

    // Verificando se o nó já não está na lista
    if (aux->id == no_destino)
        return 0;

    */
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

// Desaloca nos recursivamente
void
desalocaLista(node * no)
{   
    node * aux;
    if (no != NULL){
        if(no->next != NULL){
            aux = no->next;
            free(no);
            no = NULL;
            desalocaLista(aux);              // Chamada recursiva
        }
    }
}

// Desaloca toda a memória usada no grafo
void excluiGrafo(graph * grafo)
{
    // Desalocando os nós
    for(int i = 0; i < grafo->tam; i++)
    {
        desalocaLista(grafo->lista[i]);        
        grafo->lista[i] = NULL;
    }

    // Desalocando a lista e o grafo
    free(grafo->lista);
    free(grafo);
}
/*_______________________________________________debate.c_______________________________________________*/

// Verifica se pode haver um debate na turma
// Isso pode ser feito usando uma busca em largura que verifica se, saindo de um nó, seus vizinhos fazem
// Parte do outro grupo, e caso não o façam, marcar estes como do outro grupo

// Função recursiva usada para busca em profundidade
int
verDebateRec(graph * grafo, int noID, int * vetGrupos)
{
    int * nonVisited = (int*) malloc (sizeof(int) * grafo->tam); // Vetor que marca os nós não visitados
    int nonVisitedCont = 0;

    /* Etapa de "pesquisa" */
    node * nodeAux = grafo->lista[noID];

    while (nodeAux != NULL)                                     // Verificando os nós vizinhos
    {
        if(vetGrupos[nodeAux->id] == -1)                        // Inicializando o nó caso esse não tenha o sido
        {
            nonVisited[nonVisitedCont++] = nodeAux->id;
            vetGrupos[nodeAux->id] = !vetGrupos[noID];
        }
        else
            if(vetGrupos[nodeAux->id] == vetGrupos[noID])       // Verificando se vizinhos não tem a mesma cor
            {
                free(nonVisited);
                return 0;
            }

        nodeAux = nodeAux->next;                                // Pulando para o próximo nó da lista
    }

    /* Pulando para os nos vizinhos */
    for(int i = 0; i < nonVisitedCont; i++)
        if(!verDebateRec(grafo, nonVisited[i], vetGrupos))        // Caso haja um caso errado numa chamada em um vizinho
        {
            free(nonVisited);
            return 0;
        }
    free(nonVisited);
    return 1;                                                   // Retornando True caso nenhum caso tenha dado errado
}

/* Função que encapsula as chamadas recursivas da verDebateRec */
int
verDebateCall(graph * grafo)
{   
    int * vetGrupos = (int *) malloc (sizeof(int) * grafo->tam);    // Alocando o vetor de grupos

    for(int i = 0; i < grafo->tam; i++)                             // Chamando as n_nos vezeses
    {
        for(int j = 0; j < grafo->tam; j++) vetGrupos[j] = -1;      // inicializando o vetor
        
        vetGrupos[i] = 1;                                           // Inicializando o primeiro nó observado com uma "cor"

        if(!verDebateRec(grafo, i, vetGrupos))                      // Caso a função retorne falso, tudo já é retornado como falso
        {
            free(vetGrupos);
            return 0;
        }
    }

    free(vetGrupos);
    return 1;                                                       // Caso passe no testes para todos os nós, é considerado válido
}

/*_______________________________________________main.c________________________________________________*/
#define MAX 100

int main(int argc, char *argv[])
{
    char file_name[MAX];
    FILE *entrada;

    if (argc != 1)
    {
        printf("Numero incorreto de parametros. Ex: .\\nome_arquivo_executavel\n");
        return 0;
    }
    scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if (entrada == NULL)
    {
        printf("\nNao encontrei o arquivo! Informe o nome da instancia\n");
        exit(EXIT_FAILURE);
    }

    
    /* Rodando o algoritmo */
    int n_casos;
    graph * grafo;
    // Leitura do número de casos
    fscanf(entrada, "%d", &n_casos);

    for(int i = 0; i < n_casos; i++)
    {
        // Criando o Grafo
        grafo = formaGrafo(entrada);

        // Verificando o grafo
        if(verDebateCall(grafo))
            printf("Vai ter debate\n");
        else
            printf("Impossivel\n");
            
        // Desalocando o grafo
        excluiGrafo(grafo);
    }

    fclose(entrada);
    return 0;
}
