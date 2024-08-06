N = int(input())
i = N-1
while i > 1:
    N *= i
    i -= 1
print(N) 