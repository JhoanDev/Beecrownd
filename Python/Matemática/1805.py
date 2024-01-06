a,b = map(int,input().split(' '))

def soma_seq(x,y):
    resultado = ((y-x+1)/2)*(x+y)
    return resultado

res = soma_seq(a,b)
print(int(res))