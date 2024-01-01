operacao = input()

matriz = []

for _ in range(12):
    linha = []
    for _ in range(12):
        linha.append(float(input()))
    matriz.append(linha)

soma = 0 
media = 0

for i in range(11,6,-1):
    for j in range(12-i,i):
        soma += matriz[i][j]
        media += 1

if operacao == 'S':
    print("{:.1f}".format(soma))
else:
    print("{:.1f}".format(soma/media))