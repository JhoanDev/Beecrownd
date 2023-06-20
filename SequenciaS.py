i = 1
total = 0.00
while i <= 100:
    total += 1/i
    i += 1
total = "{:.2f}".format(total)
print(total)