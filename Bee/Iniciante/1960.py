pags = int(input())

numeros_romanos = {
    1: 'I',
    5: 'V',
    10: 'X',
    50: 'L',
    100: 'C',
    500: 'D',
    1000: 'M'
}

mill = 1000
quinhentos = 500
cem = 100
cinquenta = 50
dez = 10
cinco = 5
um = 1

saida = ""

while pags > 0:
    if pags >= mill:
        saida += numeros_romanos[mill]
        pags -= mill
    elif pags >= (mill - cem):
        saida += numeros_romanos[cem]
        pags += cem

    elif pags >= quinhentos:
        saida += numeros_romanos[quinhentos]
        pags -= quinhentos
    elif pags >= (quinhentos - cem):
        saida += numeros_romanos[cem]
        pags += cem

    elif pags >= cem:
        saida += numeros_romanos[cem]
        pags -= cem
    elif pags >= (cem - dez):
        saida += numeros_romanos[dez]
        pags += dez

    elif pags >= cinquenta:
        saida += numeros_romanos[cinquenta]
        pags -= cinquenta
    elif pags >= (cinquenta - dez):
        saida += numeros_romanos[dez]
        pags += dez

    elif pags >= dez:
        saida += numeros_romanos[dez]
        pags -= dez
    elif pags >= (dez - um):
        saida += numeros_romanos[um]
        pags += um
    
    elif pags >= cinco:
        saida += numeros_romanos[cinco]
        pags -= cinco
    elif pags >= (cinco - um):
        saida += numeros_romanos[um]
        pags += um

    elif pags >= um:
        saida += numeros_romanos[um]
        pags -= um

print(saida)
