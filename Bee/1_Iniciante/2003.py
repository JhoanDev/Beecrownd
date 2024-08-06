while True:
    try:
        hour, minutes = map(int, input().split(':'))
        minutes += hour * 60 + 60
        time = 8 * 60
        delay = minutes - time
        if delay < 0:
            print("Atraso maximo: 0")
        else:
            print("Atraso maximo:", delay)
    except EOFError:
        break
