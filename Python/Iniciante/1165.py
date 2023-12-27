def eh_primo(primo):
    for i in range(2, primo):
        if primo % i == 0:
            return False
    return True if primo > 1 else False


testes = int(input())

for n in range(0, testes):
    primo = int(input())
    if eh_primo(primo) == True:
        print(primo, "eh primo")
    else:
        print(primo, "nao eh primo")
