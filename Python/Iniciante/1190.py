operacao = input()

matriz = []

for _ in range(12):
    linha = []
    for _ in range(12):
        linha.append(float(input()))
    matriz.append(linha)

soma = 0
media = 0

for i in range(1,6):
    for j in range(12-i,12):
        soma += matriz[i][j]
        soma += matriz[11-i][j]
        media += 2

if operacao == "S":
    print("{:.1f}".format(soma))
else:
    print("{:.1f}".format(soma/media))



