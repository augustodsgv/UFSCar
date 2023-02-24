/*
Distância Genômica
Dada a sequência de genes de dois indivíduos diferentes, podemos inferir quão
distantes eles estão evolutivamente contando o número de mutações gênicas
necessárias para transformar o genoma de um indivíduo no do outro. Existem
diversos tipos de mutações gênicas, mas uma das mais comuns é a troca da
posição de genes adjacentes, ou seja, a inversão de dois genes. Vamos focar
apenas neste tipo de mutaçõeo, o que nos leva a supor que os dois indivíduos
analisados tem os mesmos genes. Para simplificar, vamos numerar os genes de
um dos indivíduos de 1 até n e cada um dos genes do indivíduo recebe
o mesmo n´umero, ainda que apareça em posição distinta. Seu objetivo é, dada
uma sequência de números inteiros correspondendo ao genoma do indivíduo 2
(numerado de acordo com a ordem do indivíduo 1), determinar a distˆancia
genˆomica baseada apenas em invers˜oes entre os dois indivíduos.
Entrada
Cada instância está armazenada em um arquivo com extensão “.in”. A ´unica
linha a ser lida da entrada padrão contém o nome de tal arquivo contendo a
instância. Esse nome deve ser usado para ler o arquivo da instância, que se
encontra na mesma pasta que o executável.
A primeira linha de cada instância informa a quantidade N de genes dos
indivíduos comparados, a segunda linha apresenta uma sequência de N números
inteiros correspondendo ao genoma do indivíduo 2, numerado de acordo com a
ordem em que os genes aparecem no indivíduo 1.
Saída
Deve ser impresso na saída padrão o menor número de inversões de genes nescessário 
para transformar o genoma do indivíduo 2 no genoma do indivíduo 1.
*/

/*
*   Programa : inversoes.c
*   Objetivo : conta quantas inversões existem em um vetor de inteiros
*   Autor : Augusto dos Santos Gomes Vaz
*   RA : 800268
*   Data : 22/08/2022 - 28/08/2022
*/

#include <stdio.h>
#include <stdlib.h>

/*
*   conta_inversoes
*   A função usa de um mecanismo de merge sort pra contar quantos números inteiros estão invertidos entre si
*   ou seja, um número maior está antes em um vetor de inteiros do que seus antecessores.
*   Foi usado unsigned long long pois são gerados números muito altos de inversoes.
*   No pior caso, ou seja, quando o vetor está totalmente invertido, cada elemento possui (m - 1) inversoes,
*   sendo m = n - numero, ou seja, a posição relativa do número com o maior número do vetor. 
*   Neste caso pode-se escrever o número de inversões como (n - 1) + (n - 2) + ... + (n - (n -1)) + (n - n).
*   Existem n "termos", que podem ser reescritos como n² - (1 + 2 + ... + n). 
*   Esse segundo termo é a soma de uma PA de razão 1, logo pode-se escreve-la como n * (n + 1) / 2.
*   Logo, tem-se que MAX de inversoes = n² - (n² + n) / 2 = (n² - n) / 2.
*   Dessa forma, percebe-se que esse número de contagens cresce de forma quadrática e pode ser extremamente
*   custosa para achar o resultado
*/
int
conta_inversoes(int * vetor, int inicio_vetor, int fim_vetor, unsigned long long * n_inversoes)
{   
    int i, j, k, meio_vetor;
    int * vetor_ordenado;

    if (fim_vetor - inicio_vetor < 2)                                                   //se o vetor tiver menos do que dois 
        return 0;                                                                       //elementos significa que se chegou num vetor de tamanho mínimo                       

    //else : o vetor não tem tamanho mínimo
    meio_vetor = (fim_vetor + inicio_vetor) / 2;
    
    //divisão do vetor
    conta_inversoes(vetor, inicio_vetor, meio_vetor, n_inversoes);
    conta_inversoes(vetor, meio_vetor, fim_vetor, n_inversoes);

    vetor_ordenado = (int*) malloc (sizeof(int) * (fim_vetor - inicio_vetor));

    //intercalando
    i = inicio_vetor;
    j = meio_vetor;
    k = 0;
    while(i < meio_vetor && j < fim_vetor)
    {
        if(vetor[i] < vetor[j])
            vetor_ordenado[k++] = vetor[i++];                   //caso o elemento do subvetor da esquerda seja menor
        else
        {
            vetor_ordenado[k++] = vetor[j++];                   //caso o elemento do subvetor da direita seja menor
            *n_inversoes += meio_vetor - i;                     //contagem das inversoes
        }
    }
    while(i < meio_vetor)                                       //preenchimento com o restante do vetor
        vetor_ordenado[k++] = vetor[i++];
    while(j < fim_vetor)
        vetor_ordenado[k++] = vetor[j++];

    for(k = 0; k < fim_vetor - inicio_vetor; k++)              //reconstrução do vetor ordenado
        vetor[k + inicio_vetor] = vetor_ordenado[k];

    free(vetor_ordenado);
    
    return 1;
}

#define MAX 100

void imprime(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    char file_name[MAX];
    FILE *entrada;
    int i, n;
    unsigned long long num_inv = 0;

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
    // lendo do arquivo da instância
    fscanf(entrada, "%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        fscanf(entrada, "%d", &v[i]);

    // imprime(v, n);
    num_inv = 0;
    conta_inversoes(v, 0, n, &num_inv);

    // printf("%I64u\n", num_inv);
    printf("%llu\n", num_inv);

    fclose(entrada);
    return 0;
}