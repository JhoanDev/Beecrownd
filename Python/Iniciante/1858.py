pessoas = int(input())

vezesAtingido = list(map(int, input().split(' ')))

resposta = 0

for i in range(pessoas):
    if vezesAtingido[resposta] > vezesAtingido[i]:
        resposta = i

print(resposta+1)
