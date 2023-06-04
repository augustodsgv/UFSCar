'''
Programa : servidor.py
Descrição : Programa que testa a performance de um servidor com uma e várias threads
Autor : Augusto dos Santos
Última edição : 04/05/2023
'''

import socket, time, threading

nTestes = 16

def conecta(indice):
    cliente = socket.socket(socket.AF_INET, socket.SOCK_STREAM)     # Criando socket cliente
    tempoInicio = time.time()
    cliente.connect(('127.0.0.1', 8080))                    # Estabelecendo conexão
    mensagem = 'Ola, sou o cliente ' + str(indice)
    cliente.send(mensagem.encode())      # Enviando a mensagem

    mensagem = cliente.recv(8192)   # Recebendo mensagem do servidor
    tempoFim = time.time()
    print(f'Mensagem recebida : {mensagem} em {tempoFim - tempoInicio} s')

    cliente.close()

cliente0 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
cliente0.connect(('127.0.0.1', 8080))
cliente0.send(b'pode comecar')

# Iniciando primeiro teste com 5 clientes, usando várias threads
threads = []
inicio = time.time()
for i in range(nTestes):
    thread = threading.Thread(target=conecta, args=(i,))
    thread.start()

for thread in threads:
    thread.join()
fim = time.time()

print(f'Tempo de resposta do primeiro teste = {fim - inicio}')

# Iniciando segundo teste com 5 clientes, usando várias threads
threads = []
inicio = time.time()
for i in range(nTestes):
    thread = threading.Thread(target=conecta, args=(i,))
    thread.start()


for thread in threads:
    thread.join()

fim = time.time()
print(f'Tempo de resposta do primeiro teste = {fim - inicio}')
cliente0.close()