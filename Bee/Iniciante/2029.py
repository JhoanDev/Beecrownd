while True:
    try:
        volume = float(input())
        diametro = float(input())
        altura = volume/(3.14*(diametro/2)**2)
        area = 3.14*(diametro/2)**2
        print("ALTURA = {:.2f}".format(altura))
        print("AREA = {:.2f}".format(area))
    except EOFError:
        break
