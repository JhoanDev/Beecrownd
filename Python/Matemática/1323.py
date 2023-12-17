def quadrados(entrada):
    if entrada == 1:
        return 1
    else:
        return (entrada*entrada) + quadrados(entrada-1)


while True:
    entrada = int(input())
    if entrada == 0:
        break
    total = quadrados(entrada)
    print(total)
