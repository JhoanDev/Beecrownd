testes = int(input())

for _ in range(testes):
    feedbacks = int(input())
    for _ in range(feedbacks):
        setor = int(input())
        if setor == 1:
            print("Rolien")
        elif setor == 2:
            print("Naej")
        elif setor == 3:
            print("Elehcim")
        else:
            print("Odranoel")
