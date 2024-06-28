def is_even(num):
    return (num & 1) == 0

p, j1, j2, r, a = map(int, input().split(' '))

result = ""
add = j1 + j2

if (r == 1):
    if (a == 1):
        result = "Jogador 2 ganha!"
    else:
        result = "Jogador 1 ganha!"
elif (r == 0 and a == 1):
    result = "Jogador 1 ganha!"
elif (p == 1):
    if (is_even(add)):
        result = "Jogador 1 ganha!"
    else:
        result = "Jogador 2 ganha!"
else:
    if (is_even(add)):
        result = "Jogador 2 ganha!"
    else:
        result = "Jogador 1 ganha!"
print(result)
