while True:
    entry = int(input())
    if(entry == 0):
        break
    string = input()
    face = 2 # 0-sul 1-oeste 2-norte 3-leste
    for x in string:
        if(x == 'D'):
            face = (face + 1) % 4
        else:
            face = (face - 1) % 4
    match (face):
        case 0:
            print("S")
        case 1:
            print("O")
        case 2:
            print("N")
        case 3:
            print("L")