while True:
    x = int(input())
    if x == 0:
        break
    else:
        if x%2 == 0:
            aux = x
            for i in range(4):
                aux += 2
                x += aux
        else:
            x += 1
            aux = x
            for i in range(4):
                aux += 2
                x += aux
        print(x)
