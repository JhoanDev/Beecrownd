while True:
    try:
        linhas = int(input())
        entra = []
        fila = False
        pilha = False
        filaprioridade = False
        naomax = True
        naofila = True
        naopilha = True
        impossible = False
        for _ in range(linhas):
            comando, x = map(int, input().split(' '))
            if comando == 1:
                entra.append(x)
            elif not impossible:
                tamanho = len(entra)
                maximo = max(entra)
                if x == entra[0] and maximo != x:
                    if naofila:
                        fila = True
                    if tamanho != 1:
                        pilha = False
                        filaprioridade = False
                        naopilha = False
                        naomax = False
                if x == entra[tamanho-1] and maximo != x:
                    if naopilha:
                        pilha = True
                    if tamanho != 1:
                        fila = False
                        filaprioridade = False
                        naofila = False
                        naomax = False
                if x == maximo and x != entra[tamanho-1] and x != entra[0]:
                    if naomax:
                        filaprioridade = True
                    if tamanho != 1:
                        fila = False
                        pilha = False
                        naopilha = False
                        naofila = False
                if x == maximo:
                    if naomax:
                        filaprioridade = True
                if x != maximo:
                    filaprioridade = False
                    naomax = False
                if x == entra[0]:
                    if naofila:
                        fila = True
                if x != entra[0]:
                    fila = False
                    naofila = False
                if x == entra[tamanho-1]:
                    if naopilha:
                        pilha = True
                if x != entra[tamanho-1]:
                    pilha = False
                    naopilha = False
                if x in entra:
                    entra.remove(x)
                else:
                    impossible = True
        if fila and not pilha and not filaprioridade:
            print("queue")
        elif pilha and not fila and not filaprioridade:
            print("stack")
        elif filaprioridade and not pilha and not fila:
            print("priority queue")
        elif (not fila and not pilha and not filaprioridade) or impossible:
            print("impossible")
        else:
            print("not sure")
    except EOFError:
        break