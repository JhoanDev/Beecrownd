n = int(input())
for i in range(n):
    entrada = input()
    xy = entrada.split()
    xy[0] = int(xy[0])
    xy[1] = int(xy[1])
    if xy[0] % 2 == 0:
        xy[0] += 1
        aux = xy[0]
        for j in range(xy[1] - 1):
            aux += 2
            xy[0] += aux
        print(xy[0])
    else:
        aux = xy[0]
        for j in range(xy[1] - 1):
            aux += 2
            xy[0] += aux
        print(xy[0])
