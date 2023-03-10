'''
Programa : Node.py
Descrição : implementação de uma classe node para a formação de uma árvore binária para construção de um algoritmo de huffman
Autor : Augusto dos Santos e Lucas Abbiati
Data : 3/3/2023
'''

class Node:
    def __init__(self, label = None, right = None, left = None):
        self.label = label
        self.left = left
        self.right = right
