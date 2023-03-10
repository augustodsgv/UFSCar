'''
Programa : resolução do problema "The rod cutting problem" por estratégia top down
Auto : Augusto dos Santos
Data : 05/02/2023
Matéria : PAA -> programação dinâmica
'''
'''
Esta primeira é uma abordagem somente recursiva que não é muito eficiente
pois há muito retrabalho para calcular a mesma combinação de preço
'''

# Função envelope
def rod_cut_top_down(n, vet_precos):
    vetor_memoria = [0 for _ in range(n + 1)]       # Vetor que evita retrabalho
    return rod_cut_top_down_rec(n, vet_precos, vetor_memoria)
    
# Função recursiva
def rod_cut_top_down_rec(n, vet_precos, vet_memoria):
    if n == 0:
        return 0
    
    if vet_memoria[n] > 0:
        return vet_memoria[n]
    
    maior_preco = 0                         # Iniciando o valor com o menor preço possivel (não há preços negativos)
    # combinacao = []                         # Vetor que guarda a combinação dos maiores valores

    for i in range(n):
        novo_preco = rod_cut_top_down_rec(n - i, vet_precos, vet_memoria)
        if maior_preco > (vet_precos[i] + novo_preco):
            maior_preco = vet_precos[i] + novo_preco

    vet_memoria[n] = maior_preco
    return maior_preco


precos = [0, 1, 5, 8]
print(rod_cut_top_down(3, precos))
