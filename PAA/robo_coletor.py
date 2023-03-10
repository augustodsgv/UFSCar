'''
Programa : resolução do problema do robô coletor
Autor : Augusto dos Santos
Data : 05/02/2023
Matéria : PAA -> programação dinâmica
'''

# Retorna o maior valor e um vetor com o caminho
def robo_coletor(matriz_tabuleiro):
    # Criação da matriz de tamanho n + 1, para comportar as filas imaginarias das bordas superior e esquerda
    matriz_valores = [[0 for _ in range(len(matriz_tabuleiro[0]) + 1)] for _ in range(len(matriz_tabuleiro) + 1)]

    # Matriz que guarda a sequência percorrida
    sequencia = []
    
    # Copiando a matriz tabuleiro para a matriz valores
    for i in range(len(matriz_tabuleiro)):
        for j in range(len(matriz_tabuleiro[0])):
            matriz_valores[i + 1][j + 1] = matriz_tabuleiro[i][j]

    # Cálculo dos melhores valores possíveis para cada casa do tabuleiro
    for i in range(1, len(matriz_valores)):                                     # Passando pelas linhas
        for j in range(1, len(matriz_valores[0])):                              # Passando pelas colunas
            if matriz_valores[i - 1][j] > matriz_valores[i][j - 1]:             # Caso o de cima seja maior
                matriz_valores[i][j] += matriz_valores[i - 1][j]
            else:                                                               # Caso o da esquerda seja maior
                matriz_valores[i][j] += matriz_valores[i][j - 1]       
    
    # Cálculo do melhor caminho com back-tracking
    linha = len(matriz_valores) - 1
    coluna = len(matriz_valores[0]) - 1
    while linha > 0 and coluna > 0:
        sequencia.insert(0, [linha - 1, coluna - 1])                                        # Adicionando ao início do vetor para manter a ordem
        if matriz_valores[linha - 1][coluna] > matriz_valores[linha][coluna - 1] and linha > 0:
            linha -= 1
        else:
            coluna -= 1
    

    # Adicionando o ponto de início para fins de visualização
    sequencia.insert(0, [0, 0])

    return matriz_valores, sequencia


matriz = [[0, 0, 1, 0, 1, 0], [1, 1, 0, 1, 0, 0], [0, 1, 0 , 0, 1, 0], [0, 0, 1, 0, 0, 1], [0, 1, 1, 0, 1, 0], [0, 0, 1, 0, 1, 0]]
solucao, caminho = robo_coletor(matriz)

for linha in solucao:
    for coluna in linha:
        print(coluna, end = " ")
    print()

for casa in caminho:
    print(f"({casa[0]}, {casa[1]})", end = "->")