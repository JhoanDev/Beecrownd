i = 3
j = 2
total = 1.00
while i <= 39:
    total += i/j
    i += 2
    j *= 2
total = "{:.2f}".format(total)
print(total)