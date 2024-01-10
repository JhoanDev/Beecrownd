conect1 = list(map(int,input().split(" ")))
conect2 = list(map(int,input().split(" ")))

compativeis = True

for i in range(5):
    if conect1[i] == conect2[i]:
        compativeis = False
        break

if compativeis:
    print("Y")
else:
    print("N")