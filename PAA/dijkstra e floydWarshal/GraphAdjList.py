'''
Programa : GraphAdjList.py
Descrição : implementação de um grafo co mlista da adjascência
Autor : Augusto dos Santos
Data : 18/02/2023
'''

import Node

# Trata a entrada do arquivo para retornar somente inteiros
def funcLeitura(arquivo):
    leitura = ""
    while(True):                                                                    # Loop para ler todos os caracteres de um número
        caractere = arquivo.read(1)
        if caractere == '@':
            return 0
        if caractere != '\n' and caractere != ' ':                                  # verificando o último caractere inserido
            leitura += caractere                                                    # Adicionando o novo caractere

        else:
            # print(f"leitura : {leitura}")
            if leitura != "":                                  # Verificando se a leitura não é somente um vazio
                return int(leitura)                                                     # Por hora, o label e o weight são inteiros
            # Else : continua buscando numero
    


class Graph:
    # Cria grafo a partir de um arquivo de texto
    '''
    numero_nós

    numero_arestas_noN
    destino_noN custo_noN
    ...
    destino_noN custo_noN

    ...
    numero_arestas_noN
    destino_noN custo_noN
    ...
    destino_noN custo_noN

    @
    '''


    def __init__(self, nome_arquivo : str):
        # Abrindo arquivo
        arquivo = open(nome_arquivo, "r")                # Lendo o arquivo

        # Lendo o tamanho do arquivo
        self.tam = funcLeitura(arquivo)
        
        # Criando a lista
        self.lista = []

        for i in range(self.tam):
            self.lista.append(Node.Node(i))
            noAtual = self.lista[-1]

            # Criando as adjacências do no atual 
            n_arestas = funcLeitura(arquivo)           # Quantas arestas saem desse nó

            for _ in range(n_arestas):          
                aresta = funcLeitura(arquivo)          # Qual o destino da aresta atual
                custo = funcLeitura(arquivo)
                noAtual.next = Node.Node(aresta, None, custo)     # Adicionando ao final da lista
                noAtual = noAtual.next                      # Avançando para o próximo nó

        # Fechando o arquivo
        arquivo.close()

    def printGraph(self):
        for origem in self.lista:
            current = origem
            while current != None:
                print(f"{current.label} -({current.weight})->", end = " ")
                current = current.next
            print()

