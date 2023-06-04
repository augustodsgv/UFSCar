'''
Programa : Gale-shappley.py
Descrição : Implementação de um algoritmo Gale Shappley Para criar emparelhamentos estáveis
Autor : Augusto dos Santos e Lucas Abbiati
Última ediçao : 01/04/2023
'''

# Função que retorna o parceiro atual da pessoa, seja homem ou mulher
def getPartner(pessoa, dictCasais : dict):
    # Se a pessoa é do lado dominante
    if pessoa in dictCasais.keys():
        return dictCasais[pessoa]
    
    # Se a pessoa é do lado não dominante
    if pessoa in dictCasais.items():
        for parceiro in dictCasais:
            if dictCasais[parceiro] == pessoa:
                return parceiro
            
    # Caso não tenha parceiro
    return None    

# Função de Gale_shappley
def Gale_Shappley(dictMen : dict, dictWoman : dict):
    # Lista dos casais arranjados
    dictCasais = {}

    # Pilha dos homens a serem arranjados
    filaHomens = []
    for homem in dictMen:
        filaHomens.append(homem)
    
    while len(filaHomens) > 0:
        homem = filaHomens.pop(0)       # Removendo o primeiro homem da fila

        # Rodando até o homem achar uma parceira
        while getPartner(homem, dictCasais) == None: 
            mulher = dictMen[homem].pop(0)  # Pegando a mulher mais prioritária
            if (getPartner(mulher, dictCasais) == None): # Caso a mulher não esteja relacionada
                dictCasais[homem] = mulher
            else:
                parceiroAtual = getPartner(mulher, dictCasais)
                # Verificando se o parceiro atual tem mais prioridade que o homem
                if dictWoman[mulher].index(homem) < dictWoman[mulher].index(parceiroAtual):
                    # Retirando o homem antigo e colocando-o na fila novamente
                    dictCasais.pop(parceiroAtual)
                    filaHomens.insert(0, parceiroAtual)

                    # Adicionando o novo casal
                    dictCasais[homem] = mulher
                # Caso o parceiro atual tenha maior prioridade, vai pra próxima mulher
    return dictCasais

# Função que printa os casais
def printaCasais(dictCasais : dict):
    for homem in dictCasais:
        print(f'{homem} : {dictCasais[homem]}')

if __name__ == '__main__':

    # Dicionário que contém os homens
    dictMen = {'m1' : ['w3', 'w2', 'w5', 'w1', 'w4'],
               'm2' : ['w1', 'w2', 'w5', 'w3', 'w4'],
               'm3' : ['w4', 'w3', 'w2', 'w1', 'w5'],
               'm4' : ['w1', 'w3', 'w4', 'w2', 'w5'],
               'm5' : ['w1', 'w2', 'w4', 'w5', 'w3'],
            }

    # Dicionário que contém as mulheres
    dictWoman = {'w1' : ['m3', 'm5', 'm2', 'm1', 'm4'],
                 'w2' : ['m5', 'm2', 'm1', 'm4', 'm3'],
                 'w3' : ['m4', 'm3', 'm5', 'm1', 'm2'],
                 'w4' : ['m1', 'm2', 'm3', 'm4', 'm5'],
                 'w5' : ['m2', 'm3', 'm4', 'm1', 'm5'],
                }
    printaCasais(Gale_Shappley(dictMen, dictWoman))