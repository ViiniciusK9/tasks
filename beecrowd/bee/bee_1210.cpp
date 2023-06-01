#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 2111
#define INF 8000000

int n, l, m, p;

int custo[MAX], venda[MAX];
int memo[MAX][MAX];
vector<int> sol;


int dp(int ano, int i_a, int i_l) {
    int op1, op2;
    if (ano == n)
    {
        return min(p, ((i_a == i_l) ? (p - venda[i_a -1]) : custo[i_a]));
    }
    if (memo[ano][i_a] != -1)
    {
        return memo[ano][i_a];
    }
    
    if (i_a == i_l)
    {
        op1 = dp(ano, 0, i_l) + p - venda[i_a-1];
        op2 = INF;
    } else if (i_a == 0) {
        op2 = dp(ano + 1, i_a + 1, i_l) + custo[i_a];
        op1 = INF;
    } else {
        op1 = dp(ano, 0, i_l) + p - venda[i_a-1];
        op2 = dp(ano + 1, i_a + 1, i_l) + custo[i_a];
    }

    return memo[ano][i_a] = min(op1, op2);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> l >> m >> p && n != EOF)
    {
        for (int i = 0; i < m; i++)
        {
            cin >> custo[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> venda[i];
        }
        memset(memo, -1, sizeof(memo));
        cout << (dp(1, l, m)) << '\n';
        
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome