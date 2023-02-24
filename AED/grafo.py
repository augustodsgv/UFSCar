'''
Programa : Grafos.py
Objetivo : implementações de grafos usando python
Autor : Augusto dos Santos Gomes Vaz
Data : 16/09/2022
'''

import random

class grafo:
    def __init__(self, tam):
        self.tam = tam
        self.matriz = [[None] * tam] * tam

    def preencheAleatorio(self):
        for linha in range(self.tam):
            for coluna in range(self.tam):
                self.matriz[linha][coluna] = random.randint(0, 1)
    
    def printaGrafo(self):
        for linha in self.matriz:
            for coluna in linha:
                print(coluna, end = " ")
            print()

    def DFS(self, c_node, visitados):                       # Depth Fisrt Search
        visitados.append(c_node)
        for i in range(self.tam):
                if (self.matriz[c_node][i]):
                    if(not i in visitados):
                        print(f"{c_node + 1} -> {i + 1}")
                        self.DFS(i, visitados)

    def BFS(self, inicio, visitou, visitado):                        # Breadth First Search
        if visitou == []:
            visitou = [0] * self.tam

        if visitado == []:
            visitado = [0] * self.tam
                
        visitado[inicio] = 1
        
        for i in range(len(self.matriz[inicio])):
            print(f"chamada = {i + 1} de {inicio}")
            if not vetorVisitados[i]:
                print(f"{inicio} -> {i}")
                self.BFS(i, vetorVisitados)
        

grafo = grafo(6)
grafo.matriz = [[0, 0, 1, 0, 0, 0],
                [0, 0, 0, 0, 0, 0],
                [0, 1, 0, 1, 0, 0],
                [1, 0, 0, 0, 1, 1],
                [0, 1, 0, 0, 0, 1],
                [0, 0, 0, 0, 0, 0]]

#grafo.preencheAleatorio()
#grafo.printaGrafo()
pilha = []
fila = []
vetorVisitados = []
grafo.DFS(0, vetorVisitados)

# grafo.printaGrafo()
