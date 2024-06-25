testes = int(input())
for _ in range(testes):
    tp = int(input())
    tiros = list(map(int,input().split(' ')))
    saltos = input()
    acertos = 0
    for i in range(tp):
        if saltos[i] == 'J':
            if tiros[i] > 2:
                acertos += 1
        else:
            if tiros[i] < 3:
                acertos += 1
    print(acertos)