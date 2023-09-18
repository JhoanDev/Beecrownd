n = int(input())

for _ in range(n):
    entrada = input()
    strings = list(map(str,entrada.split(' ')))
    strings.sort(key=lambda x: len(x), reverse= True)
    strings = ' '.join(strings)
    print(strings)
