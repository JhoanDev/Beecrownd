import math

while True:
    ordem = int(input())
    if ordem == 0:
        break
    matriz = [[0] * ordem for _ in range(ordem)]
    k = 1
    for i in range(ordem):
        matriz[0][i] = 2**i
    for i in range(1,ordem):
        for j in range(ordem):
            matriz[i][j] = matriz[i-1][j]*2
    tamanho = math.floor(math.log10(matriz[ordem-1][ordem-1])) + 1
    for linha in matriz:
        print(f"{linha[0]:>{tamanho}}", end='')
        for elemento in linha[1:]:
            print(f" {elemento:>{tamanho}}", end='')
        print()
    print()