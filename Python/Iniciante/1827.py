while True:
    try:
        ordem = int(input())
        matriz = [[0] * ordem for _ in range(ordem)]
        for i in range(ordem):
            matriz[i][i] = 2
            matriz[i][ordem - i - 1] = 3
        quadradointerior = int(ordem/3)
        for i in range(quadradointerior,ordem - quadradointerior):
            for j in range(quadradointerior,ordem - quadradointerior):
                matriz[i][j] = 1
        meio = int(ordem/2)
        matriz[meio][meio] = 4
        for i in range(ordem):
            for j in range(ordem):
                print(matriz[i][j], end='')
            print()
        print()
    except EOFError:
        break