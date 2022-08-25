
def a(n):
    if n == 0:
        return 4
    if n == 1:
        return 7
    if n == 2:
        return 2
    
    return (6 * a(n-1) - 12 * a(n-2) + 8 * a(n-3) + (n ** 2) * (2 ** n))

x = a(10)

print(x)