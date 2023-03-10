'''
Programa Krustal.py
Descricao : Implementacao de um algoritmo de kruskal para encontrar caminhos minimo
Autor : Augusto dos Santos e Lucas Abbiati
Data : 05/03/2023
'''

class Vertex:
    def __init__(self):
        self.pai = None
        self.altura = None

class Grafo:
    def __init__(self):
        self.nVertices = 0
        self.nArestas = 0
        self.vertices = []
        self.pesos = [[] for _ in range(self.nVertices)]


# Inicializa uma arvore com o vertice passado como raiz
def make_set(vertice : Vertex):	
    vertice.pai = vertice 	# Colocando o pai de V na árvore como ele mesmo
    vertice.altura = 0	# Define a altura dele na árvore como 0, pois é o unico

# Retorna o pai do vértice
def Find_set(vertice : Vertex):
    if vertice.pai != vertice:      # Verificando se o no nao 'e seu proprio pai
        return Find_set(vertice.pai)    # Se nao o for, faz uma busca recursiva ate achar a raiz
                                        # Pois essa tera como pai o proprio vertice
    return vertice.pai                  # Se for pai de si mesmo, o vertice 'e a raiz de sua arvore

# Funde as arvore de u e v
def Union(u : Vertex, v : Vertex):
    if u.altura > v.altura:         # Se o no u tiver altura maior do que v, ele se torna o pai de 
        v.pai = u
    else :                          # Caso contrario, o oposto acontece
        u.pai = v
        if u.altura == v.altura:    # E caso os dois sejam iguais, arbitrariamente u vira pai de v
            v.altura += 1           # E o rank de v aumenta


def Krustal(grafo : Grafo):
    for vertice in grafo.vertices:
        make_set(vertice)
