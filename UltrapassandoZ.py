x = int(input())
i = 1
total = x
while True:
    z = int(input())
    if z > x:
        break
while total < z:
    x += 1
    total += x
    i += 1
print(i)
