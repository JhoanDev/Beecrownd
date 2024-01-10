while True:
    l,r = map(int, input().split(" "))
    if l == r and r == 0:
        break
    print(l+r)