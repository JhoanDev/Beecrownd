a,b = map(int, input().split(' '))

for i in range(abs(b)):
    q = int((a - i)/b)
    if a == (b*q) + i:
        r = i
        break
print(f"{q} {r}")