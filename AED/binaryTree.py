'''
Programa : binaryTree.py
Objetivo : implementação de uma árvore binária de busca básica para testes
Autor : Augusto dos Santos Gomes Vaz
Data : 19/09/2022
'''
class node:
    def __init__(self, cont):
        self.cont = cont
        self.prev = None
        self.next = None
    

class tree:
    def __init__(self):
        self.root = None

    # Inserindo a partir de um nó
    def insertNode(self, cont, root):
        # Caso a árvore esteja vazia
        if root == None:
            novoNo = node(cont)
            root = novoNo
            return novoNo
        # Caso a Árvore não esteja vazia
        if cont > self.root.cont:
            return self.insertNode(cont, root.next)

        return self.insertNode(cont, root.prev)

    # Envelope da função 
    def insertEnv(self, cont):
        return self.insertNode(cont, self.root)

    
    # Printar a árvore
    def printTree(self):
        None                # Não implementado ainda
