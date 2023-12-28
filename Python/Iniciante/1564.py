while True:
    try:
        copa = int(input())
        if copa > 0:
            print("vai ter duas!")
        else:
            print("vai ter copa!")
    except EOFError:
        break