while True:
    entrada = int(input())
    if entrada == 0:
        break
    assasinos = list(map(int, input().split(" ")))
    maior = [assasinos[0], 0]
    i = 1
    j = 1
    k = 1
    for a in assasinos:
        if maior[0] < a:
            maior[1] = maior[0]
            maior[0] = a
            j = k
            k = i
        elif maior[0] > a and maior[1] < a:
            maior[1] = a
            j = i
        i += 1
    print(j)