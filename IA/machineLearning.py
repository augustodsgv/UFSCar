'''
Programa : machineLearning.py
Descirção : Programa que treina e testa uma IA que reconhece letras a partir de um dataframe com features de letras
Autores : Ana Luísa, Augusto dos Santos, Gabrielly Castilho, Victor Enzo
Última edição : 28/03/2023
'''

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn import preprocessing
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import ConfusionMatrixDisplay, f1_score, precision_score, recall_score

# Importando o dataframe
df = pd.read_csv('handwritten_data_785.csv')

# Separando entre conjunto de testes e treino
df = df.sample(frac=1).reset_index(drop=True)

# Aqui, X é o dado de input, aquele que mostra as características daquele objeto
X = df.drop('0', axis=1)

# Aqui, y são as classificações desse input, ou seja, o que cada um representa
y = df['0']

# Separando o dataset em treino e teste
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state=237)

# Padronizando
scaler = preprocessing.MaxAbsScaler()
# Escalando os dados de treinamento
X_train = scaler.fit_transform(X_train)
# Escalando os dados de teste com os dados de treinamento, visto que os dados de teste podem ser apenas 1 amostra
X_test = scaler.transform(X_test)

# Treinando
# Usando um knn com 3 visinhos
knn = KNeighborsClassifier(n_neighbors = 3)
knn.fit(X_train, y_train)

# Usando o modelo para prever os valores
predicted = knn.predict(X_train)
# Calculando o valor F1-Score
f1score = f1_score(y_test, predicted, average = 'macro')
# Calculando a Precision
precisao = precision_score(y_test, predicted, average = 'macro')
# Calculando o Recall
recall = recall_score(y_test, predicted, average = 'macro')
# Calculando a Acurácia
acuracia = knn.score(X_test, y_test)

print(f'f1score : {f1score}')
print(f'precisao : {precisao}')
print(f'recall : {recall}')
print(f'acuracia : {acuracia}')

ConfusionMatrixDisplay.from_predictions(y_test, predicted, labels=knn.classes_)
plt.show()
