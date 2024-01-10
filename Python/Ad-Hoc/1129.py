while True:
    questoes = int(input())
    if questoes == 0:
        break
    vetor = [0,0,0,0,0]
    for i in range(questoes):
        vetor[0], vetor[1], vetor[2], vetor[3], vetor[4] = map(
            int, input().split(' '))
        quantidade = 0
        posicao = 0
        for j in range(5):
            if vetor[j] <= 127:
                quantidade += 1
                posicao = j
        if quantidade != 1:
            print("*")
        elif posicao == 0:
            print("A")
        elif posicao == 1:
            print("B")
        elif posicao == 2:
            print("C")
        elif posicao == 3:
            print("D")
        elif posicao == 4:
            print("E")
