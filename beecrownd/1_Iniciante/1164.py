n = int(input())

for x in range(n):
    soma = 0
    numero = int(input())
    for i in range(numero):
        if numero%i+1 == 0:
            soma = soma + i
    if soma-numero == numero:
        print(f"{numero} eh perfeito")
    else:
        print(f"{numero} nao eh perfeito")