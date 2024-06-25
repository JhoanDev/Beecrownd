colocao = int(input())

top = 0

if colocao == 1:
    top = 1
elif colocao > 1 and colocao <= 3:
    top = 3
elif colocao > 3 and colocao <= 5:
    top = 5
elif colocao > 5 and colocao <= 10:
    top = 10
elif colocao > 10 and colocao <= 25:
    top = 25
elif colocao > 25 and colocao <= 50:
    top = 50
elif colocao > 50 and colocao <= 100:
    top = 100

print("Top", top)
