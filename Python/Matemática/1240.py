testes = int(input())

for _ in range(testes):
    num1, num2 = map(str, input().split(' '))
    if len(num1) < len(num2):
        print("nao encaixa")
    else:
        encaixa = True
        tamanho = len(num1) - 1
        for i in range(len(num2)-1, -1, -1):
            if num2[i] != num1[tamanho]:
                encaixa = False
                break
            tamanho -= 1
        if encaixa:
            print('encaixa')
        else:
            print("nao encaixa")
