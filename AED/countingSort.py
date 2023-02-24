'''
Programa : countingSort.py
Objetivo : implementação de um algoritmo de counting sort
Autor : Augusto dos Santos Gomes Vaz
Data : 08/09/2022
'''

'''
get Digito
Esta função retorna o dígito especificado
'''
from cmath import log
from itertools import count


def getDigito(numero, digito):
    return int(numero / 10 ** (digito - 1)) % 10

'''
Max digitos do vetor
Retorna a quantidade máxima de dígitos que tem o vetor
'''
#def maiorDigitos(vetor):
#    return int(log(max(vetor)))

#vetor = [100, 200]
#print(maiorDigitos(vetor))
    
'''
Max vetor digito
Retorno o maior elemento de um determinado dígito em um vetor de inteiros
'''
def maxDigito(vetor, digito):
    # Determinando o numero de casas
    var = 0
'''
get Vetor Frequencias
Esta função cria um vetor que contém a quantidade de vezes que cada número do vetor aparece;
O vetor tem tamanho igual ao maior valor presente no vetor;
'''
def getFreq(vetor):
    vetFreq = [0] * (max(vetor) + 1)

    for i in vetor:
        vetFreq[i] += 1
    return vetFreq

'''
get Vetor Frequencias Digito
Esta função cria um vetor que contém a quantidade de vezes que cada número do vetor aparece;
O vetor tem tamanho igual ao maior valor presente no vetor;
'''
def getFreqDig(vetor, digito):
    vetFreq = [0] * (max(vetor) + 1)

    for i in vetor:
        vetFreq[i] += 1
    return vetFreq

'''
Get Frequencias Acumuladas
Retorna a quantidade de vezes que aparecem números antes do número atual
'''
def getFreqAcumulada(vetFreq):
    vetFreqAcumulada = [0] * (len(vetFreq))
    for i in range(1, len(vetFreq)):
        vetFreqAcumulada[i] = vetFreqAcumulada[i - 1] + vetFreq[i]
        
    return vetFreqAcumulada

'''
couting sort
retorna o vetor ordenado usando o método counting sort estável;
Precisa acessar o vetor desordenado para funcionar
'''
def countingSort(vetor):
    vetOrdenado = [0] * len(vetor)
    vetFreqAcumulada = getFreqAcumulada(getFreq(vetor))
    for i in reversed(vetor):
        vetFreqAcumulada[i] -= 1
        vetOrdenado[vetFreqAcumulada[i]] = i

    return vetOrdenado

'''

'''
def countingSortDigito(vetor, digito):
    vetOrdenado = [0] * len(vetor)
    vetFreqAcumulada = getFreqAcumulada(getFreq(vetor))
    
    for i in reversed(vetor):
        vetFreqAcumulada[i] -= 1
        vetOrdenado[vetFreqAcumulada[i]] = i

    return vetOrdenado


# main
vetor = [3, 0, 1, 3]
vetor = countingSort(vetor)
print(vetor)