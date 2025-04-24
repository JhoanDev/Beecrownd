while True:
    ordem = int(input())
    if ordem == 0:
        break
    matriz = [[0] * ordem for _ in range(ordem)]
    k = 0
    while k != ordem:
        aux = 1
        for i in range(k,ordem):
            matriz[k][i] = aux
            matriz[i][k] = aux
            aux += 1
        k += 1
    for linha in matriz:
        print(f"{linha[0]:>3}", end='')
        for elemento in linha[1:]:
            print(f" {elemento:>{3}}", end='')
        print()
    print()