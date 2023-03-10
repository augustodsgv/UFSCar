'''
Programa : GraphMatrix.py
Descrição : Implementação de um grafo usando matriz de adjacência
Autor : Augusto dos Santos
Data : 22/02/2023
'''

# O maior valor possível de nó atualmente é "INF", que está definido como o maior inteiro de 16 bits
INF = 2147483647

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
    def __init__(self, nomeArquivo : str):
        # Abrindo o arquivo
        arquivo = open(nomeArquivo, "r")
        self.tam = funcLeitura(arquivo)

        # Criando a matriz
        self.matriz = [[0 for i in range(self.tam)] for j in range(self.tam)]

        # Atribuindo os valores à matriz
        for i in range(self.tam):                   # Andando as linhas
            # Lendo a quantidade de arestas que aquele nó tem
            nNos = funcLeitura(arquivo)

            for _ in range(nNos):                   # Andando nas colunas            
                # Lendo o objetivo
                destino = funcLeitura(arquivo)
                peso = funcLeitura(arquivo)
                self.matriz[i][destino] = peso

        # Atribuindo peso infinito aos nós que não fazem ligação
        for i in range(self.tam):
            for j in range(self.tam):
                if self.matriz[i][j] == 0:
                    self.matriz[i][j] = INF

        # Atribuindo peso infinito aos nós que não fazem ligação
        for i in range(self.tam):
            for j in range(self.tam):
                if i == j:
                    self.matriz[i][j] = 0

        

    def printGraph(self):
        for linha in self.matriz:
            for coluna in linha:
                print(coluna, end=" ")
            print()


grafo = Graph("g2.txt")
grafo.printGraph()