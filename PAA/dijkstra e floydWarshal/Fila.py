'''
Programa : Fila.py
Descrição : Implementação de uma classe fila para uso no algoritmo de Dijkstra
Autor : Augusto dos Santos Gomes Vaz
Data : 19/02/2023
'''

class Fila:
    def __init__(self):
        self.array = []

    # Remove o elemento do início da fila
    def dequeue(self):
        if len(self.array) == 0:
            return False
        # Else
        return self.array.pop(0)
    
    # Adiciona elemento ao final da fila
    def enqueue(self, elemento):
        self.array.append(elemento)

    '''
    def decreaseKey(self, element, newCost):
        # Achando e removendo o elemento da fila
        for i in range(len(self.array)):
            if self.array[i][0] == element:
                temp = self.array.pop(i)
        
        # Alterando o valor do custo
        temp[1] = newCost

        # Achando a posição novamente
        for i in range(1, len(self.array)):
        # Inserindo novamente na fila
            if self.array[i][1] > newCost:
                self.array.insert(i, temp)
                return i
    '''
