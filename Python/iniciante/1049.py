entrada = input()
total = 0
A = int(entrada[0])
for i in range(len(entrada)):
    if entrada[i+1].isdigit():
        if int(entrada[i+1]) > 0:
            I = int(entrada[i+1])
            break
for J in range(I):
    total += J + A
print(total)
