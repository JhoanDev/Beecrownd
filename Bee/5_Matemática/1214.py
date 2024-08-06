testes = int(input())

for _ in range(testes):
    vet = list(map(int, input().split(' ')))
    soma = 0
    media = 0
    for element in vet[1:]:
        media += element
    media = media/vet[0]
    for element in vet[1:]:
        if element > media:
            soma += 1
    media = soma / vet[0] * 100
    print(f"{media:.3f}%")
