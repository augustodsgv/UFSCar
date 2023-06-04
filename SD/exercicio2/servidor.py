'''
Programa : servidor.py
Descrição : Programa que testa a performance de um servidor com uma e várias threads
Autor : Augusto dos Santos
Última edição : 04/05/2023
'''

import socket, threading, time

nTestes = 16

# Função que recebe, trata e envia mensagem novamente
def conecta(servidor, indice):
    print(f'Iniciando conexao {indice}')
    cliente, _ = servidor.accept()  # Aceitando conexão
    mensagem = cliente.recv(8192)   # Recebendo mensagem do cliente
    time.sleep(2)
    print(f'Mensagem recebida do cliente {indice} : {mensagem}')
    cliente.send(mensagem + b'*')   # Enviando mensagem de volta
    cliente.close()


# Criando servidor
servidor = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

servidor.bind(('127.0.0.1', 8080))          # Criando conexão

servidor.listen(nTestes+1)

cliente, _ = servidor.accept()  # conexão de controle
while cliente.recv(8192) != b'pode comecar':
    None


# Criando teste para servidor com única thread
inicio = time.time()
for i in range(nTestes):
    conecta(servidor, i)               # Adicionando ao vetor

fim = time.time()
t1 = fim - inicio
print(f'Teste 1 thread finalizado com tempo {fim - inicio}')

# Criando teste ultilizando threads
threads = []
inicio = time.time()
for i in range(int(nTestes / 4)):
    # Criando threads
    thread1 = threading.Thread(target=conecta, args=(servidor, i))       # Criando thread com função que trata a conexão
    thread1.start()
    thread2 = threading.Thread(target=conecta, args=(servidor, i))       # Criando thread com função que trata a conexão
    thread2.start()
    thread3 = threading.Thread(target=conecta, args=(servidor, i))       # Criando thread com função que trata a conexão
    thread3.start()
    thread4 = threading.Thread(target=conecta, args=(servidor, i))       # Criando thread com função que trata a conexão
    thread4.start()


    # Esperando threads terminarem
    thread1.join()
    thread2.join()
    thread3.join()
    thread4.join()

fim = time.time()
t2 = fim - inicio
print(f'Teste com {nTestes} threads finalizado com tempo {fim - inicio}')

servidor.close()
print(f'Teste 1 terminado com {t1}')
print(f'Teste 2 terminado com {t2}')