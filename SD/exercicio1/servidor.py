'''
Programa : servidor.py
Descrição : servidor do exercício
Autor : Augusto dos Santos
Última edição : 04/05/2023
'''

import socket

servidor = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

servidor.bind(('127.0.0.1', 8000))      # Estabelecendo conexão

servidor.listen(1)                      # Ficando se standby

cliente, _ = servidor.accept()          # Aceitando conexão

mensagem = cliente.recv(8192)              # Recebendo mensagem 

print(f'Mensagem recebida do cliente : {mensagem}')

cliente.send(mensagem + b'*')           # Reenviando mensagem com alteração

servidor.close()                        # Fechando conexão


