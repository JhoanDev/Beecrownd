numero = int(input())

numeroshexa = "0123456789ABCDEF"

hexadecimal = ''
resto = 0

while numero != 0:
    resto = numero % 16
    numero = numero // 16
    hexadecimal += numeroshexa[resto]

print(hexadecimal[::-1])
