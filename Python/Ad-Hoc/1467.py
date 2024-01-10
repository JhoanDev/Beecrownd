while True: 
    try:
        a,b,c = map(int, input().split(' '))
        if a == b and b == c:
            print('*')
        elif a != b and b == c:
            print("A")
        elif c != b and b == a:
            print("C")
        else:
            print("B")

    except EOFError:
        break