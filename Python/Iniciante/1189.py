operador = input()

matriz = []

for _ in range(12):
    linha = []
    for _ in range(12):
        linha.append(float(input()))
    matriz.append(linha)

soma = 0
media = 0

for j in range(5):
    for i in range(10-j,0+j,-1):
        soma += matriz[i][j]
        media += 1

if operador == 'S':
    print("{:.1f}".format(soma))
else:
    print("{:.1f}".format(soma/media))
