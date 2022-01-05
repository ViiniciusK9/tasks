''' 
    Nesta parte os estudantes deverão fazer uma implementação. Deverão criar
    um algoritmo que aproxime a solução da referida equação (escolhida para 
    fazer a primeira parte) com intervalo de comprimento igual ou inferior a 
    1/10, que contenha uma solução, isto é, o erro de aproximação da referida 
    solução será menor que 10^(−1) . Quando o erro for o desejado, deverá ser 
    indicado o comando de parada. 

    Dados de entrada: Dois números reais 


    Dados de saída: O algoritmo deve retornar com a seguinte mensagem: 

        (a) “não é possível afirmar que existe solução neste intervalo, tente 
        outros dois números”; 

        (b) Ou “a equação tem, pelo menos, uma solução neste intervalo” e também
        deve retornar um 	intervalo de comprimento menor que 10^(−1). 

 '''


import math


def f(num): # função f(x) = x^3 + 5sen(x) + 2x + 4
    seno = math.sin(num)
    resultado = pow(num, 3) + (5 * seno) + (2 * num) + 4
    return resultado


def busca_intervalo(maior , menor): # função que faz a busca do intervalo desejado
    meio = (maior + menor) / 2
    resultado = f(meio)
    while (resultado > 0.1 or resultado < -0.1):
        if (resultado > 0.1):
            maior = meio
        else:
            menor = meio
        meio = (maior + menor) / 2
        resultado = f(meio)
    return maior, menor
    

def main():
    try:
        num_1 = float(input('Digite o primeiro número: ')) # entrada de dados
        num_2 = float(input('Digite o segundo número: '))

        resultado_1 = round(f(num_1), 1) # arredondamento a 1 casa decimal.
        resultado_2 = round(f(num_2), 1)
        print()

        if(resultado_1 > 0 and resultado_2 < 0 or resultado_1 < 0 and resultado_2 > 0): # verifica se é valida a solução.
            maior = max(num_1, num_2)
            menor = min(num_1, num_2)
            maior_resultado, menor_resultado = busca_intervalo(maior, menor)
            print(f'A equação tem pelo menos uma solução nesse intervalo [{maior_resultado}; {menor_resultado}].')
        else:
            print(f'Os resultados foram:\nf({num_1}) = {resultado_1}\nf({num_2}) = {resultado_2}\nSendo assim, não é possivel afirmar que existe solução nesse intervalo, tente outros dois números.')
            print()
            main()
    except:
        print(f'Ocorreu um erro inesperado, tente novamente.')
        main()


iniciar = main()
