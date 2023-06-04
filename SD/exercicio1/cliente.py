'''
Programa : cliente.py
Descrição : cliente do exercício
Autor : Augusto dos Santos
Última edição : 04/05/2023
'''

import socket

cliente = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # Criando socket

cliente.connect(('127.0.0.1', 8000))                # Estabelecendo conexão

cliente.send(b'Mensagem')                           # Enviando arquivo

mensagem = cliente.recv(8192)                           # Recebendo mensagem de volta

print(f'Mensagem do servidor : {mensagem}')

cliente.close()

