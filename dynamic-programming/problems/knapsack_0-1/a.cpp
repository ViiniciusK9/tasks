#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int INF = int(1e9);

const int MAX = int(500);
const int MAX_QNT = int(500);

vi values(MAX);
vi weights(MAX);

int memo[MAX][MAX_QNT];
int tab[MAX][MAX_QNT];

array<int, MAX> previ;
array<int, MAX> dp;

int n, k, aux;

int solve(int i, int qnt)
{
    if (qnt < 0)
        return -INF;

    if (i == n)
        return 0;

    if (memo[i][k])
        return memo[i][k];

    return memo[i][qnt] = max(solve(i + 1, qnt), solve(i + 1, (qnt - weights[i])) + values[i]);
}

/* Mais segura */
int solve2(int i, int qnt)
{
    if (i == n)
        return 0;

    if (memo[i][k])
        return memo[i][k];

    if (weights[i] > qnt)
    {
        return memo[i][k] = solve2(i + 1, qnt);
    }

    return memo[i][qnt] = max(solve2(i + 1, qnt), solve2(i + 1, (qnt - weights[i])) + values[i]);
}

int bottom_up(int qnt)
{
    for (int i = 0; i <= qnt; i++) {
        if (weights[0] <= i) {
            tab[0][i] = values[0];      
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= qnt; j++)
        {
            if (weights[i] > j) {
                tab[i][j] = tab[i-1][j];
            } else {
                tab[i][j] = max(tab[i-1][j], tab[i-1][j-weights[i]] + values[i]);
            }
        }
    }

    return tab[n-1][qnt];
}


/*
    O tempo de execução da memozation custama ser mais rapido devido a ter que resolver menos subproblemas.
    Quando utilizamos a abordagem bottom-up acabamos resolvendo todos os subproblemas. Vale apena analizar
    seu problema e verificar se precisa economizar memoria ou tempo, mas caso ambos os recursos estiverem
    OK da para passar com qualquer uma das abordagens.
*/
int bottom_up_optimization_memory(int qnt)
{
    for (int i = 0; i <= qnt; i++) {
        if (weights[0] <= i) {
            previ[i] = values[0];      
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= qnt; j++)
        {
            if (weights[i] > j) {
                dp[j] = previ[j];
            } else {
                dp[j] = max(previ[j], previ[j-weights[i]] + values[i]);
            }
        }
        previ = dp;
    }

    return previ[qnt];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
        // DBG(values[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
        // DBG(weights[i]);
    }

    cout << solve(0, k) << '\n';

    cout << solve2(0, k) << '\n';

    cout << bottom_up(k) << '\n';

    cout << bottom_up_optimization_memory(k) << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome