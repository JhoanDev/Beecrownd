while True:
    try:
        n = int(input())
        matriz = []
        for i in range(n):
            matriz.append([0] * n)
        for i in range(n):
            for j in range(n):
                matriz[i][j] = 3
        for i in range(0,n):
            matriz[i][i] = 1
        for i in range(n-1,-1,-1):
            matriz[i][n-i-1] = 2
        for i in range(0,n):
            for j in range(0,n):
                print(matriz[i][j], end='')
            print()

    except EOFError:
        break