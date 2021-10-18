n = int(input())

def teste(j, m, n):
    while n > 0:
        n-=1
        copy.pop(j)
        j = abs(j - j)
    if copy[n] == n:
        return copy

lista = []
for i in range(1, ((2*n) + 1)):
    lista.append(i)
m = n+1
copy = lista[:]
for j in range(n+1, (10**16)):
    copy = lista[:]
    teste(j, m, n)
