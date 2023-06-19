#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 2111
#define INF 8000000

int n, l, m, p;

int memo[MAX][MAX];
int path[MAX][MAX];

int venda[MAX];
int custo[MAX];


int dp(int i, int w) {
    if (i == n)
    {
        return 0;
    }

    if (memo[i][w] != -1)
    {
        return memo[i][w];
    }

    int ans2;
    int ans1;

    if (w == m)
    {
        ans2 = dp(i + 1, 1) + custo[0] + p - venda[w-1];
        ans1 = INF;
    } else {
        ans2 = dp(i + 1, 1) + custo[0] + p - venda[w-1];
        ans1 = dp(i + 1, w + 1) + custo[w];
    }
    if (ans2 <= ans1)
    {
        path[i][w] = 1;
        return memo[i][w] = ans2;
    } else {
        return memo[i][w] = ans1;
    }
    
    
}


void pp(int ano, int idade) {
    int flag = 1;
    while (ano < n)
    {
        if (path[ano][idade] == 1)
        {
            cout << ((!flag) ? " " : "") << ano + 1;
            ano++;
            idade = 1;
            flag = 0;
        } else {
            ano++;
            idade++;
        }
        
    }
    if (flag)
    {
        cout << "0";
    }
    cout << "\n";
    

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
        memset(path, -1, sizeof(path));

        cout << dp(0, l) << '\n';

        pp(0, l);
        /*
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << path[i][j] << " ";
            }
            cout << "\n";
        }
        */
        
        

    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome