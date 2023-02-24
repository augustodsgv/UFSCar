/*
Todo ano, na escola municipal de Abadia dos Açores, ocorre uma competição
literária. Nessa, cada aluno participante deve redigir um texto sobre um determinado tema.
Para tornar a competição mais objetiva, os organizadores
decidiram introduzir um sistema de pontuação. Basicamente, os professores
estipulam um conjunto de palavras (que eles consideram pertinentes ao tema)
e atribuem uma pontuação a cada uma delas. Nesse sistema, a nota de um
dado aluno é calculada da seguinte maneira: somam-se os valores de todas as
palavras do texto que estão na lista dos professores e subtraem-se 10 pontos
para cada vez que uma palavra que não está na lista aparece no texto. Como
é possível fazer um programa para calcular rapidamente as notas de todos os
participantes?
Entrada: Os dados devem ser lidos diretamente da entrada padrão.
A primeira linha da entrada contém dois inteiros positivos: N, o número de palavras
escolhidas pelos professores, e M, o número de participantes na competição.
Em seguida, o arquivo contém N linhas, compostas por uma palavra e sua
pontuação. Nas linhas seguintes a estas são apresentados os textos produzidos
pelos alunos, sendo que, ao final de cada texto existe uma linha com o caractere
'.' (ponto). Vale notar que cada texto pode estar em uma ou mais linhas e
todas as palavras estão em letras minúsculas, não contendo caracteres especiais
ou acentuados.
Saída: É composta de M linhas, cada uma contendo um inteiro correspondente à pontuação obtida por um texto. 
As pontuações devem ser apresentadas respeitando a mesma ordem em que os textos foram apresentados.
*/


/*_______________________________________________________________________________________________________*/
/*
* Programa : hash.h
* objetivo : cabeçalho da implementação de uma função de espalhamento
* Autor : Augusto dos Santos Gomes Vaz
* RA : 800268
* data : 06/08/2022
*/

#ifndef HASH_H
#define HASH_H

int nEntradas = 0;
//definicao do primo de referencia

/* FUNÇÕES */

//funcao hash
int hashFunc(char string [], int tamanho, int primo);

#endif /*HASH_H*/

/*_______________________________________________________________________________________________________*/
/*
* Programa : hash.c
* objetivo : implementação de uma função de espalhamento
* Autor : Augusto dos Santos Gomes Vaz
* RA : 800268
* data : 06/08/2022
*/

/* BIBLIOTECAS */
//#include "hash.h"

/* FUNÇÕES */
//função hash
int
hashFunc(char string [], int tamanho, int primo)
{
    int i = 0;
    int hash = 0;
    while (string[i] != '\0')
    {
        hash = (hash + string[i] * primo) % tamanho;
        i++;
    }
    return hash % tamanho;
}

/*_______________________________________________________________________________________________________*/
/*
* Programa : tabelaHash.h
* Objetivo : cabeçalho da implementação de uma tabela de espalhamento
* Autor : Augusto dos Santos Gomes Vaz
* RA : 800268
* Data : 06/08/2022
*/

#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#define PALAVRA_TAM 20
/* REGISTROS */

//registro que representa cada palavra e seu valor
typedef struct word
{
    char * wordString;
    int value;
    int ativo;
}word;

//registro que representa a tabela avl e seu tamanho
typedef struct table
{
    word * vetor;
    int tamanho;
    int primo;
}table;


/* FUNÇÕES */

//devolve um tamanho sugerido para a tabela com base na quantidade de elementos que serão guardados nela
int tamanhoTabela(int n_elementos);

//cria uma palavra a partir de uma string e seu valor
word criaPalavra(char palavra[], int valor);

//cria uma tabela hash com o tamanho especificado
table * criaTabela(int tamanho);

//printa todas as palavras do vetor de palavras
int printaTabela(table * tabela);

//trata as colisões
int trata_colisao(table * tabela, char * string, int hash);

//indica se achou a palavra na tabela
int buscaTabela(table * tabela, char * string, int * valor);

//insere elementos na tabela
int insereTabela(table * tabela, char * string, int valor);

//remove uma string da tabela
int removeTabela(table * tabela, char * string);

//desaloca o vetor da tabela e a tabela
int deletaTabela(table * tabela);
#endif /*TABELA_HASH_H*/

/*_______________________________________________________________________________________________________*/
/*
* Programa : tabela hash
* objetivo : implementação de uma tabela de espalhamento
* Autor : Augusto dos Santos Gomes Vaz
* RA : 800268
* Data : 04/08/2022
*/

/* BIBLIOTECAS */
//#include "hash.h"
//#include "tabelaHash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


//devolve um tamanho sugerido para a tabela com base na quantidade de elementos que serão guardados nela
int
tamanhoTabela(int n_elementos)
{
    return n_elementos * 4;
}

//cria um struct palavra a partir de uma string e seu valor
word
criaPalavra(char palavra[], int valor)
{
    word novaPalavra;
    novaPalavra.wordString = palavra;
    novaPalavra.value = valor;
    novaPalavra.ativo = 0;
    return novaPalavra;
}

//cria uma tabela hash com o tamanho especificado
table *
criaTabela(int n_elementos)
{
    table * tabela = (table*) malloc (sizeof(table));
    tabela->tamanho = tamanhoTabela(n_elementos);
    tabela->primo = tabela->tamanho - 1;
    tabela->vetor = (word*) malloc (sizeof(word) * tabela->tamanho);

    for(int i = 0; i < tabela->tamanho; i++)
    {
        tabela->vetor[i].ativo = 0;
        tabela->vetor[i].wordString = NULL;
    }
    return tabela;
}

//percorre toda a tabela printando os seus valores
int
printaTabela(table * tabela)
{
    if (tabela != NULL)
    {
        for(int i = 0; i < tabela->tamanho; i++)
        {
            if(tabela->vetor[i].ativo)
                printf("[%d] %s, valor : %d\n", i, tabela->vetor[i].wordString, tabela->vetor[i].value);
            else
                printf("[%d] none\n", i);
        }
        return 1;


    }
    return 0;
}

//indica se achou a palavra na tabela
int
buscaTabela(table * tabela, char * string, int * valor)
{
    int hash, n_tentativas = 0;
    hash = hashFunc(string, tabela->tamanho, tabela->primo);
    
    while(tabela->vetor[hash].wordString != NULL && strcmp(tabela->vetor[hash].wordString, string))
    {   
        hash += (int)pow(2, n_tentativas);
        hash = hash % tabela->primo;         //para garantir que hash está dentro do tamanho do vetor
        n_tentativas++;
    }
    //descobrindo se existe, de fato, um elemento com esse código hash na tabela
    if(tabela->vetor[hash].wordString == NULL)
        return 0;

    //caso haja, verificando se é o primeiro elemento ou se é uma colisao
    if (!strcmp(tabela->vetor[hash].wordString, string))
    {
        *valor = tabela->vetor[hash].value;
        return 1;
    }
    return 0;  
}



//insere uma string na tabela
//se ele já existir, incrementa seu contador
//se houver colisao, ignora e mantem o antigo
int
insereTabela(table * tabela, char * string, int valor)
{
    int hash, n_tentativas;
    hash = hashFunc(string, tabela->tamanho, tabela->primo);

    //tratamento da colisão usando codificação aberta    
    //aqui sera usado um tratamento de colisao quadratico, ou seja,
    //cada vez que houver uma tentativa nova de inserção,
    //ele irá somar o valor do código hash com 2 ^ n_tentativas
    n_tentativas = 0;
    while(tabela->vetor[hash].wordString != NULL)
    {   
        if (!strcmp(tabela->vetor[hash].wordString, string))        //caso seja uma chave já usada, ela nao pode ser inserida novamente, 
            return 0;                                               //pois ela estaria inacessivel
        
        //else : o conflito não é com a mesma chave
        hash += (int)pow(2, n_tentativas);
        hash = hash % tabela->primo;         //para garantir que hash está dentro do tamanho do vetor
        n_tentativas++;       

    }
    

    //adicionando à tabela
    tabela->vetor[hash].wordString = (char *) malloc (sizeof(char) * PALAVRA_TAM);  //alocando a string
    strcpy(tabela->vetor[hash].wordString, string);
    tabela->vetor[hash].value = valor;
    tabela->vetor[hash].ativo = 1;

    return 1;
}

//remove uma string da tabela
int
removeTabela(table * tabela, char * string)
{
    int hash = hashFunc(string, tabela->tamanho, tabela->primo);

    //caso não exista o elemento na table
    if (tabela->vetor[hash].wordString == NULL)
        return 0;

    //caso exista mas não seja a palavra
    if (!strcmp(tabela->vetor->wordString, string))
        return 0;

    //caso seja, de fato, a palavra procurada
    tabela->vetor[hash].wordString = NULL;
    tabela->vetor[hash].value = 0;
    return 1;

}

//desaloca a tabela
int
deletaTabela(table * tabela)
{
    free(tabela->vetor);
    tabela->vetor = NULL;
    free(tabela);
    tabela = NULL;
    return 1;
}

/*_______________________________________________________________________________________________________*/
/*
* Programa : main.c
* objetivo : le os textos passados para leitura e atribui uma pontuação de acordo com as palavras usadas
* Autor : Augusto dos Santos Gomes Vaz
* RA : 800268
* Data : 06/08/2022
*/

/* Bibliotecas */
//#include "tabelaHash.h"
//#include "hash.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

//#define PALAVRA_TAM 15

int main()
{
    /* Declarações locais */
    int N, M;                   //N : numero de palavras, M : numero de textos
    int * pontuacao;              //guarda a pontuação de cada texto
    char string_Leitura[PALAVRA_TAM];    //guarda as palavras lidas do texto
    int valor_leitura;          //guarda o valor da palavra achada
    table * tabela;             //tabela hash

    /* Leitura dos parâmetros de leitura */
    scanf("%d %d", &N, &M);
    tabela = criaTabela(N);
    pontuacao = (int*)malloc(M * sizeof(int));
    /* Leitura das palavras */
    for(int i = 0; i < N; i++)
    {
        int valor;
        scanf("%s %d", string_Leitura, &valor);
        insereTabela(tabela, string_Leitura, valor);

    }

    /* Leitura dos textos */
    for(int i = 0; i < M; i++)      //repete a quantidade de textos que houver
    {
        pontuacao[i] = 10;             //começa em 10 pois serão descontados 10 pontos na leitura do ponto final
        do
        {
            scanf("%s", string_Leitura);
            if(buscaTabela(tabela, string_Leitura, &valor_leitura))
                pontuacao[i] += valor_leitura;

            else
                pontuacao[i] -= 10;
        
        }while(strcmp(string_Leitura, "."));
    }

    for(int i = 0; i < M; i++)
    {
        printf("%d\n", pontuacao[i]);
    }
    free(pontuacao);
    deletaTabela(tabela);

    return 0;
}

/*_______________________________________________________________________________________________________*/