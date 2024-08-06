cont = 0
soma = 0

while True:
    entrada = input()
    if entrada == "caw caw":
        cont += 1
        print(soma)
        soma = 0
        if cont == 3:
            break
    else:
        if entrada[0] == '*':
            soma += 4
        if entrada[1] == '*':
            soma += 2
        if entrada[2] == '*':
            soma += 1