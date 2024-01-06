testes = int(input())

for _ in range(testes):
    comida = float(input())
    dias = 0
    while comida > 1.0:
        comida /= 2
        dias+=1
    print(f"{int(dias)} dias")