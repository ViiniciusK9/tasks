#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int n;
vi prices;

int memo[1000000];
int dp[1000000];

int solve(int len) 
{
    //DBG(len);
    if (len == 0) {
        return 0;
    }

    if (memo[len]) {
        return memo[len];
    }

    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        if (i <= len) {
            ans = max(ans, solve(len - i) + prices[i]);
        }
    }

    return memo[len] = ans;
}

int cut(int len)
{
    dp[0] == 0;
    int tam = prices.size();

    for (int i = 1; i < tam; i++) {
        for (int j = 0; j < i+1; j++)
        {
            dp[i] = max(dp[i], dp[i-j] + prices[j]);
        }
    }

    return dp[len];
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int aux, tam;

    cin >> tam;

    cin >> n;


    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        prices.pb(aux);
    }

    /*
        Cuidado que esse algoritmo só aceita que o tamanho
        do objeto cortado sejá menor que o tamanho total de
        elementos no array exemplo se temos os valores
        [0, 1, 3, 5, 2], nosso tamanho do objeto precisa
        ser 4.

        Caso precise aceitar tamanhos maiores precisa modificar
        o algoritmo.
    */
    
    cout << solve(tam) << '\n';    

    cout << cut(tam) << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome