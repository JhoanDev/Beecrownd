while True:
    A,B = map(int,input().split(' '))
    if(A == 0 and B == 0):
        break
    C = 2*A - B
    print(f"{C}")

