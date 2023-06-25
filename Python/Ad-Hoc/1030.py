nc = int(input())
cases = 0

for _ in range(nc):
    qnt, salto = map(int, input().split())

    sobrevivente = 0
    for i in range(2, qnt + 1):
        sobrevivente = (sobrevivente + salto) % i

    cases += 1
    print(f"Case {cases}: {sobrevivente + 1}")
