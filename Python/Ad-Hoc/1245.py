class Botas:
    def __init__(self, tamanho, pe):
        self.tamanho = tamanho
        self.pe = pe

while True:
    try:
        botas = int(input())
        pares = 0
        direitos = [0]*31
        esquerdos = [0]*31
        for i in range(botas):
            tam, p = map(str, input().split(" "))
            tam = int(tam)
            if (p == 'D'):
                direitos[tam-30] += 1
            else:
                esquerdos[tam-30] += 1
        for j in range(31):
            if (esquerdos[j] < direitos[j]):
                pares += esquerdos[j]
            else:
                pares += direitos[j]
        print(pares)
    except EOFError:
        break