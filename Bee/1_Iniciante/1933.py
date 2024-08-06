entrada = input()
a, b = map(int, entrada.split(' '))
c = 0
if a == b:
    c = a
else:
    c = max(a,b);
print(c)