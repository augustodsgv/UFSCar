'''
Programa : Node.py
Descrição : implementação de um nó que será usado para implementar um grafo
Autor : Augusto dos Santos
Data : 18/02/2023
'''

class Node:
    def __init__(self, label, next = None, weight = None):
        self.label = label
        self.next = next
        self.weight = weight

