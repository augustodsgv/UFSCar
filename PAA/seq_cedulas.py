'''
Programa : problema da sequência de cédulas
Autor : Augusto dos Santos
Data : 27/01/2023
Matéria : PAA -> Programação dinâmica
'''

def seq_cedulas(vet_cedulas):
    # O vetor deve ter ao menos 1 cédula para o algoritmo funcionar
    if len(vet_cedulas) < 1:
        return 0
    
    '''
    O vet_soma acumula as melhores somas até o momento
    O primeiro 0 é o valor da soma de 0 elementos, ou seja, nenhuma cédula é pegada
    Vet_cedulas[0] tem um tratamento diferente pois não pode somar com o vet[-2], que não existe
    '''
    vet_soma = [0, vet_cedulas[0]]

    # O vet_sequencia acumula a sequencia escolhida em cada iteração
    vet_sequencia = [[], [0]]

    # Loop principal
    for i in range(1, len(vet_cedulas)):
        ''' Modo manual de comparação para portabilidade para outras linguagens que não possuem "max()" '''

        # Caso o valor atual com soma da sequência anterior seja melhor      
        if vet_soma[-1] < (vet_cedulas[i] + vet_soma[-2]):
            vet_soma.append(vet_cedulas[i] + vet_soma[-2])
            vet_sequencia.append(vet_sequencia[-2].copy())
            vet_sequencia[-1].append(i)

        # Caso a soma anterior seja melhor
        else:
            vet_soma.append(vet_soma[-1])
            vet_sequencia.append(vet_sequencia[-1].copy())
    print(vet_soma)
    print(vet_sequencia)
    return vet_soma[-1], vet_sequencia[-1]
        
# Main
cedulas = [2, 5, 5, 2, 10, 50, 100, 50, 20, 20, 50, 100]
print(seq_cedulas(cedulas))