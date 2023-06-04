'''
Programa : main.py
Descricao : programa para testar o uso da compactacao de huffman
Autores : Augusto dos Santos e Lucas Abbiati
Data : 05/03/2023
'''
import huffman

freqPort = {
'a':14.63,
'b':1.04,
'c':3.88,
'd':4.99,
'e':12.57,
'f':1.02,
'g':1.30,
'h':1.28,
'i':6.18,
'j':0.40,
'k':0.02,
'l':2.78,
'm':4.74,
'n':5.05,
'o':10.73,
'p':2.52,
'q':1.20,
'r':6.53,
's':7.81,
't':4.34,
'u':4.63,
'v':1.67,
'w':0.01,
'x':0.21,
'y':0.01,
'z':0.47
}

freqEng = {
'a':8.167,
'b':1.492,
'c':2.782,
'd':4.253,
'e':12.702,
'f':2.228,
'g':2.015,
'h':6.094,
'i':6.966,
'j':0.153,
'k':0.772,
'l':4.025,
'm':2.406,
'n':6.749,
'o':7.507,
'p':1.929,
'q':0.095,
'r':5.987,
's':6.327,
't':9.056,
'u':2.758,
'v':0.978,
'w':2.360,
'x':0.150,
'y':1.974,
'z':0.074
}

texto = 'o rato roeu a roupa do rei de roma o rato roeu a roupa do rei de roma o rato roeu a roupa do rei de roma'
arrayTexto = list(texto)

arrayNormal, stringNormal = huffman.compactaNormal(arrayTexto)
arrayHuffman, stringHuffman = huffman.compactaHuffman(arrayTexto, freqPort)


print(f'Tamanho do normal {len(stringNormal)}, string : {stringNormal}')
print(f'Tamanho do huffman {len(stringHuffman)}, string : {stringHuffman}')
