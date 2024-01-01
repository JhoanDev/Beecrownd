pulo,totalcanos = map(int,input().split(" "))

entrada = input()

canos = [int(valor) for valor in entrada.split(" ") if valor.isdigit()]

canoatual = canos[0]

ganhou = True

for i in range(1,totalcanos):
    diferença = abs(canoatual-canos[i])
    if diferença > pulo:
        ganhou = False
        break
    else:
        canoatual = canos[i]

print(f"{'YOU WIN' if ganhou else 'GAME OVER'}")
