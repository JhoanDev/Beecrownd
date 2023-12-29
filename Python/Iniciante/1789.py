while True:
    try:
        quantidadeLesma = int(input())
        velocidade = 0
        lesmas = []
        lesmas = list(map(int, input().split()))
        lesmas.sort()
        if lesmas[quantidadeLesma - 1] >= 20:
            velocidade = 3
        elif lesmas[quantidadeLesma - 1] >= 10 and lesmas[quantidadeLesma - 1] < 20:
            velocidade = 2
        else:
            velocidade = 1
        print(velocidade)
    except EOFError:
        break
