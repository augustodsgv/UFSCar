'''
Programa : huffman.py
Descrição : implementação de um algoritmo de Huffman para a matéria de Projeto e Analise de Algoritmos
Autor : Augusto dos Santos e Lucas Abbiati
Data : 03/03/2023
'''

import Node

# Função que retorna o dicionário de frequencias em ordem crescente de frequencia
# O dicionario {'a' : 10, 'b' : 5, 'c' : 7} e retornado como [('b', 5), ('c', 7), ('a', 10)]
def ordenaFreq(dictFrequencia : dict):
    return sorted(dictFrequencia.items(), key=lambda x:x[1], reverse=True)

# Funcao que cria a arvore de huffman com as ordens
def huffmanTree(dictFrequencia : dict):
    # Criando dicionário com os nós de cada letra
    dictArvore = {}
    for letra in dictFrequencia:
        noLetra = Node.Node(letra)
        dictArvore[letra] = noLetra

    # Criando a árvore enquanto tem pelo menos dois elementos
    while len(dictFrequencia) > 1:  
        # Ordenando o dicionário
        tuplaOrdenada = ordenaFreq(dictFrequencia)

        # Removendo os menores
        menor = tuplaOrdenada.pop()
        dictFrequencia.pop(menor[0])
        segundoMenor = tuplaOrdenada.pop()
        dictFrequencia.pop(segundoMenor[0])

        # Criando o pai destes nos
        # Node(nome, peso, esq, dir)
        # dictArvore[menor[0]] pois menor[0] é p nome dele e dictArvore[nome] retorna o nó dele
        noPai = Node.Node(menor[0] + segundoMenor[0], dictArvore[menor[0]], dictArvore[segundoMenor[0]])

        # Adicionando o no pai ao dicionário de frequencias
        dictFrequencia[noPai.label] = (segundoMenor[1] + menor[1])

        # Adicionando o no pai ao dicionário da árvore
        dictArvore[noPai.label] = noPai

    # Retorna a raiz da arvore e o dicionario que guarda os nos
    return noPai

# Função que percorre a arvore gerada criada pelo algoritmo e cria a tabela
def criaTabela(noRaiz : Node.Node, codigoAtual : str, dictResultado : dict):
    # Indo para o filho esquerdo
    if noRaiz.left != None:
        criaTabela(noRaiz.left, codigoAtual + '0', dictResultado)

    # Indo para o filho direito
    if noRaiz.right != None:
        criaTabela(noRaiz.right, codigoAtual + '1', dictResultado)

    # Caso seja uma folha, define o valor final
    if noRaiz.left == None and noRaiz.right == None:
        dictResultado[noRaiz.label] = codigoAtual
        
    

def huffman(dictFrequencia : dict):
    # Criando copia que sera usada para guardar o resultado
    dictResultado = dictFrequencia.copy()

    # Adicionando espaços e quebra de linha com maior prioridade
    dictFrequencia['\n'] = 1
    dictFrequencia[' '] = 1

    # Criando a arvore que sera o resultado
    raizArvore = huffmanTree(dictFrequencia)

    # Achando o resultado da arvore, com busca em produndidade
    # O valor e incremetado dentro de cada funcao
    codigoAtual = ''
    criaTabela(raizArvore, codigoAtual, dictResultado)

    # Adicionando o elemento quebra de linha e espaço e 
                       
    return dictResultado

def compactaNormal(arrayTexto):
    arrayCompacta = []              # Array com o texto compactado
    stringCompacta = ''             # String com o texto compatado todo junto
    # Considerando o alfabeto com 26 letras, é preciso 5 bits
    dictPadrao = {
                'a':'00000',
                'b':'00001',
                'c':'00010',
                'd':'00011',
                'e':'00100',
                'f':'00101',
                'g':'00110',
                'h':'00111',
                'i':'01000',
                'j':'01001',
                'k':'01010',
                'l':'01011',
                'm':'01100',
                'n':'01101',
                'o':'01110',
                'p':'01111',
                'q':'10000',
                'r':'10001',
                's':'10010',
                't':'10011',
                'u':'10100',
                'v':'10101',
                'w':'10110',
                'x':'10111',
                'y':'11000',
                'z':'11001',
                ' ':'11110',
                '\n':'11111'
                }

    for letra in arrayTexto:
        arrayCompacta.append(dictPadrao[letra])
        stringCompacta += dictPadrao[letra]

    return arrayCompacta, stringCompacta

def compactaHuffman(arryTexto, dictFrequencia : dict):
    dictResultado = huffman(dictFrequencia)
    
    arrayCompacta = []              # Array com o texto compactado
    stringCompacta = ''             # String com o texto compatado todo junto

    for letra in arryTexto:
        arrayCompacta.append(dictResultado[letra])
        stringCompacta += dictResultado[letra]


    return arrayCompacta, stringCompacta