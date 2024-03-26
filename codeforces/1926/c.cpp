#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
int memo[212345];


int raizDigital(int n) {
    int soma = 0;

    // Cria uma cópia do parâmetro `n` para manipular ao longo da função
    int x = n;

    // Repete o procedimento seguinte enquanto houverem dígitos a serem somados
    while (x > 0) {
        // Adiciona à variável `soma` o dígito atual de `x`
        // Essa operação é equivalente ao resto da divisão de `x` por 10 (32 % 10 = 2)
        soma += x % 10;

        // Avança o dígito atual de `x` em uma casa para a esquerda
        // Essa operação é equivalente à divisão de `x` por 10 (32 / 10 = 3)
        x /= 10;
    }

    return soma;
}

void solve() 
{
    memo[0] = 0;
    for (int i = 1; i <= 200005; i++)
    {
        memo[i] = memo[i-1] + raizDigital(i);
    }
    
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    
    memset(memo, 0, sizeof(memo));

    solve();

    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << memo[n] << '\n';
    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome