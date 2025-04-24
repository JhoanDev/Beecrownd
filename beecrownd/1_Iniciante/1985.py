entry = int(input())

pricefinal = 0
for _ in range(entry):
    cod, quantity = map(int, input().split(' '))
    if cod == 1001:
        pricefinal += 1.50 * quantity
    elif cod == 1002:
        pricefinal += 2.50 * quantity
    elif cod == 1003:
        pricefinal += 3.50 * quantity
    elif cod == 1004:
        pricefinal += 4.50 * quantity
    elif cod == 1005:
        pricefinal += 5.50 * quantity
print("{:.2f}".format(pricefinal))