testes = int(input())

for _ in range(testes):
    jogador1, escolhaJogador1, jogador2, escolhaJogador2 = map(str, input().split(' '))
    x,y = map(int, input().split(' '))
    res = x+y
    if res%2 == 0:
        if escolhaJogador1 == "PAR":
            print(jogador1)
        else:
            print(jogador2)
    else:
        if escolhaJogador1 == "IMPAR":
            print(jogador1)
        else:
            print(jogador2)