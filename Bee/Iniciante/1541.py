import math;

while True:
    inp = input()
    if int(inp[0]) == 0:
        break
    A,B,C = map(float,inp.split(" "))
    terreno = (A*B)/(C/100)
    Ladoterreno = int(math.sqrt(terreno))
    print(Ladoterreno)