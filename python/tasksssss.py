n = int(input())
lista = dict()
for i in range(n):
    nome, pre, valor = map(str, input().split(" "))
    lista.update({nome+" "+ pre:int(valor)})
for i in sorted(lista, key = lista.get):
    print(i, lista[i])