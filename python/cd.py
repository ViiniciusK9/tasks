n = int(input())
string = str(input())
lista = dict()
for i in range(len(string)-1):
    sub = string[i:i+2]

    if(sub in lista):
        lista[sub] += 1
    else:
        lista.update({sub:1})

for i in sorted(lista, key = lista.get, reverse=True):
    print(i)
    break