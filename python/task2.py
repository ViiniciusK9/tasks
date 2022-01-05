nump, litro, cuia = map(str, input().split())
pessoas = list(map(str, input().split()))

nump = int(nump)
litro = float(litro)
cuia = float(cuia)

sum = int(litro // cuia)
resto = round((litro % cuia), 1)
sum = sum % nump
if resto != 0:
    print(f'{pessoas[sum]} {resto}')
else:
    sum -=1
    print(f'{pessoas[sum]} {cuia}')