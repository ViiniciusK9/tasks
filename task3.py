n, k = map(int, input().split())

matriz = []
linha = []

m = 1
for i in range(n):
    linha = map(int, input().split())
    matriz.append(linha)
    linha = []
menorc = matriz[0][1]
minc = matriz[0][0]
for i in range(n):
    if matriz[i][1] < menorc:
        menorc = matriz[i][1]
    if matriz[i][0] < minc:
        menorc = matriz[i][0]

c = minc
while m < k:
    c += menorc
    if 