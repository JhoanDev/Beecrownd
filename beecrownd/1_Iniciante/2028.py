cases = 0
while True:
    try:
        entry = int(input())
        cases += 1
        array = [j for i in range(entry+1) for j in [i] * i]
        array.insert(0, 0)
        tam = len(array)
        if (entry == 0):
            print(f"Caso {cases}: {tam} numero")
        else:
            print(f"Caso {cases}: {tam} numeros")
        for i in range(tam - 1):
            print(array[i], end=' ')
        print(array[tam-1])
        print()
    except EOFError:
        break
