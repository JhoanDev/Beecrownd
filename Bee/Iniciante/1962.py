qnt = int(input())

anoref = -2015

for _ in range(qnt):
    entrada = int(input())
    res = entrada + anoref
    if res >= 0:
        print(res+1,"A.C.")
    else:
        print(-1*res,"D.C.")