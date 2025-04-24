T = int(input())  # Número de casos de teste

for _ in range(T):
    pa, pb, G1, G2 = map(float, input().split())
    anos = 0
    while pa <= pb:
        pa = int(pa * (1 + G1 / 100))
        pb = int(pb * (1 + G2 / 100))
        anos += 1
        if anos > 100:
            print("Mais de 1 seculo.")
            break
    if anos <= 100:
        print(anos, "anos.")
