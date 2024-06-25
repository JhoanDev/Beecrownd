while True:
    partidas = int(input())
    if partidas == 0:
        break
    a = 0
    b = 0
    for _ in range(partidas):
        numa,numb = map(int, input().split(" "))
        if numa > numb:
            a += 1
        if numa < numb:
            b += 1
    print(f"{a} {b}")