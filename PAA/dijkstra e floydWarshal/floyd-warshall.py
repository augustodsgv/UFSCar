'''
Programa : floyd-warshall.py
Descrição : implementação de um algoritmo floyd-warshall para encontrar caminhos mínimos em grafos
Autor : Augusto dos Santos
Data : 22/02/2023
'''

import GraphMatrix as Graph

def floyd_warshall(grafo : Graph):
    n = grafo.tam
    arrayMatrizes = []
    # Copiando W para D(0)
    arrayMatrizes.append(grafo.matriz.copy())
    for k in range(1, n):
        # Criando a matriz k
        arrayMatrizes.append([[None for _ in range(n)]for _ in range(n)])
        
        for i in range(n):    
            for j in range(n):
                # arrayMatrizes[k][i][j] é d(k)(i)(j)
                arrayMatrizes[k][i][j] = min(arrayMatrizes[k - 1][i][k], arrayMatrizes[k - 1][k][j])

    return arrayMatrizes[-1]

def printaMatriz(matriz):
    for linha in matriz:
        for coluna in linha:
            print(coluna, end=" ")
        print()

g2 = Graph.Graph("g2.txt")
g2.printGraph()
print()
printaMatriz(floyd_warshall(g2))
