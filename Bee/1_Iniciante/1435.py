while True:
    ordem = int(input())
    if ordem == 0:
        break

    matriz = [[0] * ordem for _ in range(ordem)]

    for k in range((ordem + 1) // 2):
        valor = k + 1
        for i in range(k, ordem - k):
            matriz[i][k] = matriz[i][ordem - k - 1] = valor
            matriz[k][i] = matriz[ordem - k - 1][i] = valor
    for linha in matriz:
        print(f"{linha[0]:>3}", end='')
        for elemento in linha[1:]:
            print(f" {elemento:>{3}}", end='')
        print()
    print()
