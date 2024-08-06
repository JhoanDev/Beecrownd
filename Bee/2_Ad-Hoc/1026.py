def sum_dif(bin1, bin2):
    string = ''
    for i in range(32):
        if (bin1[i] == bin2[i]):
            string += '0'
        else:
            string += '1'
    return string

while True:
    try:
        n1, n2 = map(int, input().split(' '))
        bin1 = bin(n1)[2:].zfill(32)
        bin2 = bin(n2)[2:].zfill(32)
        print(int(sum_dif(bin1, bin2), 2))
    except EOFError:
        break
