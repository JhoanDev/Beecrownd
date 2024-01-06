while True:
    try:
        hasmat,oponente = map(int,input().split(' '))
        diferenca = abs(hasmat-oponente)
        print(diferenca)
    except EOFError:
        break