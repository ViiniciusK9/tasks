num, num2 = map(float, input().split())

sum = 1 + (1*(num/100))
sum2 = ((sum * (num2/100)) + (1*(num/100))) * 100

print(f'{sum2:.6f}')