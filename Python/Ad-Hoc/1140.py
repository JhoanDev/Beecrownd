while True:
    entrada = input()
    cond = 0
    if entrada == '*':
        break
    for x in range(1,len(entrada)):
        if entrada[x].upper() != entrada[0].upper() and entrada[x-1] == ' ':
            cond = 1
            break
    if cond == 0:
        print('Y')
    else:
        print('N')


