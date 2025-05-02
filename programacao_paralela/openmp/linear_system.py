import matplotlib.pyplot as plt
import numpy as np

# Dados do relatório
data = {
    'static': {
        'Threads': [2, 4, 8],
        'Linhas_par': [0.08078, 0.07371, 0.08154],
        'Colunas_par': [1.41766, 0.77580, 0.81979]
    },
    'dynamic': {
        'Threads': [2, 4, 8],
        'Linhas_par': [4.03230, 4.07060, 4.82198],
        'Colunas_par': [18.17953, 10.74943, 8.23682]
    },
    'guided': {
        'Threads': [2, 4, 8],
        'Linhas_par': [0.08854, 0.10176, 0.16926],
        'Colunas_par': [1.42266, 0.77810, 0.68294]
    }
}

# Configuração dos gráficos
plt.figure(figsize=(15, 10))

# Gráfico 1: Comparação para Linhas Paralelo
plt.subplot(1, 2, 1)
plt.plot(data['static']['Threads'], data['static']['Linhas_par'], 'b-o', label='Static')
plt.plot(data['dynamic']['Threads'], data['dynamic']['Linhas_par'], 'r--o', label='Dynamic')
plt.plot(data['guided']['Threads'], data['guided']['Linhas_par'], 'g-.o', label='Guided')
plt.title('Desempenho do Algoritmo Linhas Paralelo')
plt.xlabel('Número de Threads')
plt.ylabel('Tempo (s)')
plt.legend()
plt.grid(True)

# Gráfico 2: Comparação para Colunas Paralelo
plt.subplot(1, 2, 2)
plt.plot(data['static']['Threads'], data['static']['Colunas_par'], 'b-o', label='Static')
plt.plot(data['dynamic']['Threads'], data['dynamic']['Colunas_par'], 'r--o', label='Dynamic')
plt.plot(data['guided']['Threads'], data['guided']['Colunas_par'], 'g-.o', label='Guided')
plt.title('Desempenho do Algoritmo Colunas Paralelo')
plt.xlabel('Número de Threads')
plt.ylabel('Tempo (s)')
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.savefig('linear_system.png', dpi=300)
print("Gráfico salvo como 'comparacao_paralelo.png'")
plt.show()