class Vareta:
    def __init__(self, com, qnt):
        self.com = com
        self.qnt = qnt

while True:
    n = int(input())
    if n == 0:
        break

    varetas = []

    for i in range(n):
        c, q = map(int, input().split())
        aux = Vareta(c, q)
        varetas.append(aux)
    qnt = 0
    dif = 0
    dif2= 0
    for vareta in varetas:
        if dif == 0:
            dif = vareta.qnt//2
            while dif > 1:
                dif -= 2
                qnt += 1
            if dif2 > 0:
                dif -= 1
                dif2 -= 1
                qnt += 1
        else:
            if dif2 == 0:
                dif2 = vareta.qnt//2
                while dif2 > 1:
                    dif2 -= 2
                    qnt += 1
                if dif == 1 and dif2 == 1:
                    dif -= 1
                    dif2 -= 1 
                    qnt += 1   
    print(qnt)
