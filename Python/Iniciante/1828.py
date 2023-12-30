def disputa(Sheldon, Raj):
    if Sheldon == Raj:
        return "De novo!"
    elif (
        (Sheldon == "tesoura" and (Raj == "papel" or Raj == "lagarto")) or
        (Sheldon == "papel" and (Raj == "pedra" or Raj == "Spock")) or
        (Sheldon == "pedra" and (Raj == "lagarto" or Raj == "tesoura")) or
        (Sheldon == "lagarto" and (Raj == "Spock" or Raj == "papel")) or
        (Sheldon == "Spock" and (Raj == "tesoura" or Raj == "pedra"))
    ):
        return "Bazinga!"
    else:
        return "Raj trapaceou!"


T = int(input()) 
for caso in range(1, T + 1):
    escolha_sheldon, escolha_raj = input().split()
    resultado = disputa(escolha_sheldon, escolha_raj)
    print(f"Caso #{caso}: {resultado}")

