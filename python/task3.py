lista = dict()
a = 1
while(True):
    try:
        n = input()
        if(n == EOFError):
            break
        if(a):
            nome, pre = map(str, n.split(" "))
        else:
            nome = n
        if(a == 1 and nome == pre):
            a = 0
            continue
        if(a):
            lista.update({nome:pre})
        else:
            if(nome in lista):
                print(f"""Child: {nome}
Gift {lista[nome]}\n""")
            else:
                print("404 not found\n")
    except(EOFError):
        break