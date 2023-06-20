i = 0
total = 0.00
idades = []
while True:
    idades.append(int(input()))
    if idades[i] < 0:
        break
    i += 1
idades.pop()
for element in idades:
    total += element

total = total/i
total = "{:.2f}".format(total)
print(total)
