lista_x = [9.9,9.1,9.5,9.8,9,8.8,8.6,9.3,8.1,7.8,8.3,7.6,8.9]
lista_y = [9.0,5.0,4.0,9.0,7.5,10.0,1.0,8.0,7.0,3.0,5.0,6.8,8.7,2.5,7.0,3.2,6.1,6.0]

a = "9.0,5.0,4.0,9.0,7.5,10.0,1.0,8.0,7.0,3.0,5.0,6.8,8.7,2.5,7.0,3.2,6.1,6.0"
b = a.replace(',', ', ')
print(b)
media_x = 8.823
media_y = 6.044
desvio_x = 0.724
desvio_y = 2.546

alfa = 0.05
n_x = len(lista_x)
n_x = 13
n_y = len(lista_y)
n_y = 18
print(f'n_x: {n_x}')
print(f'n_x: {n_y}')
gl = n_x + n_y - 2
gl = 29
print(f'gl: {gl}')
tc = 2.045

scp = (((n_x - 1) * (desvio_x ** 2) + (n_y - 1) * (desvio_y ** 2) ) / (n_x + n_y -2) )** 0.5
print(f'{scp:.3f}')

scp = 2.004

tcalc = (media_x - media_y) / (scp * (((1 / n_x) + (1 / n_y)) ** 0.5))
print(f'{tcalc:.3f}')
tcalc = 3.810


