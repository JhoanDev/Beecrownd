A,B = map(float , input().split(" "))

porcentagem = ((B-A)/A) *100

print(f"{porcentagem:.2f}%")


# A = 10
# B = 15
# C = 0.5
# B = A + A*C
# B - A = A*C
# C = (B-A)/A