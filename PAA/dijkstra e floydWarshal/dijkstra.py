'''
Programa : dijkstra.py
Objetivo : implementação de um algoritmo de Dijkstra em um grafo em lista de adjascência
Autor : Augusto dos Santos
Data : 19/02/2023
'''

import GraphAdjList
import Node
import Fila

# O maior valor possível de nó atualmente é "INF", que está definido como o maior inteiro de 16 bits
INF = 2147483647


# Função adicional à TAD fila primitiva
def decreseKey(queue : Fila, element, tabelaMenorCusto):
        # Achando e removendo o elemento da fila
        queue.array.remove(element)
    
        # Achando a posição novamente
        for i in range(len(queue.array)):
        # Inserindo novamente na fila
            if tabelaMenorCusto[i] > tabelaMenorCusto[element]:
                queue.array.insert(i, element)
                return i
        # Caso seja o último elemento
        queue.array.append(element)
        return len(queue.array)
        

def dijkstra(grafo : GraphAdjList, noOrigem):
    filaPioridade = Fila.Fila()                        # Fila de prioridades
    menorCusto = [INF for _ in range(grafo.tam)]      # Array do menor custo atual. Inicia com INF
    predecessor = [None for _ in range(grafo.tam)]    # Array dos melhores caminhos. Por hora não existe nenhum caminho da origem
    finalizados = []                                   # Array dos nós finalizados
    grafo.printGraph()
    # Inicializando o primeiro 
    menorCusto[noOrigem] = 0                            # A distância do nó origem a ele mesmo é 0
    for i in range(grafo.tam):
        filaPioridade.enqueue(grafo.lista[i].label)     # Colocando todos os vizinhos do nó na fila

    # Andando na fila de prioridade
    while len(filaPioridade.array) != 0:
        top = filaPioridade.dequeue()                     # Removendo o com maior prioridade
        finalizados.append(top)                           # Adicionando-o à fila de finalizados

        # Andando na lista de adjacência do nó atual
        noAtual = grafo.lista[top].next                     # Pega o primeiro próximo pois pegar ele mesmo não faz sentido
        while noAtual != None:                              # Enquanto não chega ao final da lista
            '''
            Se o custo de chegar até o nó atual mais o custo de ir para um determinado nó for menor que o custo atual,
            significa que este caminho é o melhor até este.
            Por exemplo, um grafo com A-(10)->B, A-(30)->C, B-(10)->C
            Primeiramente o melhor caminho para C é por AC que custa 30.
            Após ir para o nó B, observase que AB + BC custa 20, que é melhor que o caminho AC,
            assim, define-se o melhor caminho sendo por AB->BC
            '''
            if menorCusto[noAtual.label] > (menorCusto[top] + noAtual.weight):
                menorCusto[noAtual.label] = menorCusto[top] + noAtual.weight                # Adicionando o valor do novo melhor caminho
                predecessor[noAtual.label] = top                                            # Mudando o predecessor do nó
                decreseKey(filaPioridade, noAtual.label, menorCusto)                        # Mudando a lista de prioridade
            
            # Andando para o próximo nó da lista 
            noAtual = noAtual.next

    return predecessor

# Printa o melhor caminho do nó origem até cada nó do grafo usando dijkstra
def printDikjstra(grafo : GraphAdjList, noOrigem):
    predecessores = dijkstra(grafo, noOrigem)
    lista = []

    for noDestino in range(len(grafo.lista)):               # Andando em cada nó do grafo 
        noCaminho = noDestino
        while noCaminho != noOrigem:                         # Percorrendo o caminho de cada nó por backtracking
            lista.insert(0, predecessores[noCaminho])       # Inserindo na lista no início
            noCaminho = predecessores[noCaminho]            # Andando para o nó predecessor
            
    
g2 = GraphAdjList.Graph("g2.txt")
print(dijkstra(g2, 0))
