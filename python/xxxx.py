n = int(input())
a, b = 0, 1
for i in range(n - 1):
    print(a, end=' ')
    aux = a
    a = b
    b = aux + b
    #a, b = b, a + b
print(a)