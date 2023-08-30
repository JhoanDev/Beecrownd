def imprimebraile(num):
    tam = len(num)
    for j in range(3):
        for i in range(tam):
            if j == 0:
                if num[i] in ['1', '2', '5', '8']:
                    if i != tam - 1:
                        print("*. ", end="")
                    else:
                        print("*.", end="")
                elif num[i] in ['9', '0']:
                    if i != tam - 1:
                        print(".* ", end="")
                    else:
                        print(".*", end="")
                else:
                    if i != tam - 1:
                        print("** ", end="")
                    else:
                        print("**", end="")
            elif j == 1:
                if num[i] in ['1', '3']:
                    if i != tam - 1:
                        print(".. ", end="")
                    else:
                        print("..", end="")
                elif num[i] in ['2', '6', '9']:
                    if i != tam - 1:
                        print("*. ", end="")
                    else:
                        print("*.", end="")
                elif num[i] in ['4', '5']:
                    if i != tam - 1:
                        print(".* ", end="")
                    else:
                        print(".*", end="")
                else:
                    if i != tam - 1:
                        print("** ", end="")
                    else:
                        print("**", end="")
            else:
                if i != tam - 1:
                    print(".. ", end="")
                else:
                    print("..", end="")
        print()

def traduzdobraile(linha1, linha2):
    tam = len(linha1)
    j = 0
    while j < tam:
        if linha1[j] == '*' and linha1[j + 1] == '.':
            if linha2[j] == '*' and linha2[j + 1] == '*':
                print("8", end="")
            elif linha2[j] == '.' and linha2[j + 1] == '.':
                print("1", end="")
            elif linha2[j] == '.' and linha2[j + 1] == '*':
                print("5", end="")
            else:
                print("2", end="")
        elif linha1[j] == '*' and linha1[j + 1] == '*':
            if linha2[j] == '*' and linha2[j + 1] == '*':
                print("7", end="")
            elif linha2[j] == '.' and linha2[j + 1] == '.':
                print("3", end="")
            elif linha2[j] == '.' and linha2[j + 1] == '*':
                print("4", end="")
            else:
                print("6", end="")
        else:
            if linha2[j] == '*' and linha2[j + 1] == '*':
                print("0", end="")
            else:
                print("9", end="")
        j += 3
    print()

while True:
    quandigt = int(input())
    if quandigt == 0:
        break
    trad = input().strip()
    if trad == 'S':
        num = input().strip()
        imprimebraile(num)
    elif trad == 'B':
        linhas = [input().strip() for _ in range(3)]
        traduzdobraile(linhas[0], linhas[1])
