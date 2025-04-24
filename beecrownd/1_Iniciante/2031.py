cases = int(input())

for _ in range(cases):
    player1 = input()
    player2 = input()
    result = ""
    if (player1 == "pedra"):
        if (player2 == "pedra"):
            result = "Sem ganhador"
        elif (player2 == "ataque"):
            result = "Jogador 2 venceu"
        else:
            result = "Jogador 1 venceu"
    elif (player1 == "ataque"):
        if (player2 == "pedra"):
            result = "Jogador 1 venceu"
        elif (player2 == "ataque"):
            result = "Aniquilacao mutua"
        else:
            result = "Jogador 1 venceu"
    else:
        if (player2 == "pedra"):
            result = "Jogador 2 venceu"
        elif (player2 == "ataque"):
            result = "Jogador 2 venceu"
        else:
            result = "Ambos venceram"
    print(result)
