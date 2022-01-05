import math

def intervalo(x1, x2):
    resultado =(x1 + x2) / 2
    resfunc = resultado**3 + 5*math.sin(resultado)
    return resfunc
while True:
    x = float(input("Digite o 1 numero"))
    y = float(input("Digite o 2 numero"))

    x1 = x**3 + 5*math.sin(x)
    x2 = y**3 + 5*math.sin(y)

    y1 = -2*x - 4
    y2 = -2*y - 4

    if x1 < 0 and x2 > 0 or x1 > 0 and x2 < 0 :
        resf = intervalo(x1, x2)
        print("a equação tem pelo menos uma solução neste intervalo", resf)
    elif y1 < 0 and y2 > 0 or y2 < 0 and y1 > 0:
        resf = intervalo(y1,y2)
        print("a equação tem pelo menos uma solução neste intervalo", resf)
    else:
        print("não é possível afirmar que existe solução neste intervalo, tente outros dois números")