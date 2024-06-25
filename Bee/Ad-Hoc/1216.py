distanciamedia = 0
cont = 0.0

while True:
    try:
        entrada = input()
        distancia = int(input())
        distanciamedia += distancia
        cont += 1.0
    except EOFError:
        break

print(f"{distanciamedia/cont:.1f}")