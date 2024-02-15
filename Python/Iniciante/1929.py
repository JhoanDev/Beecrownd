entrada = input()
a, b, c, d = map(int, entrada.split(' '))

def formatriangulo(a,b,c):
    if (abs(b-c) < a and a < b+c) and (abs(a-b) < c and c < b+a) and (abs(a-c) < b and b < a+c):
        return True
    return False

if formatriangulo(a,b,c) or formatriangulo(a,b,d) or formatriangulo(a,d,c) or formatriangulo(d,b,c):
    print("S")
else:
    print("N") 