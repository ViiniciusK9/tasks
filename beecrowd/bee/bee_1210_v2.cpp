#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 2111
#define INF 8000000

int n, l, m, p;

int custo[MAX], venda[MAX];
int memo[MAX];
int vendeu[MAX];
vector<int> sol;


void dp(int ano) {

    while (ano <= m)
    {
        if (ano == 0)
        {
            memo[0] = custo[0];
        } else if (ano == m) {
            memo[ano] = p - venda[ano];
            vendeu[ano] = 1;
        } else {
            memo[ano] = min(p - venda[ano], custo[ano]);
            if ((p - venda[ano]) < custo[ano])
            {
                vendeu[ano] = 1;
            }
        }
        
        

        ano++;
    }

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
        venda[0] = -INF;
        for (int i = 1; i <= m; i++)
        {
            cin >> venda[i];
        }
        memset(memo, -1, sizeof(memo));
        memset(vendeu, -1, sizeof(vendeu));
        dp(0);
        int i = 0;
        int ans = 0;
        while (i < n)
        {
            if (vendeu[l] == 1)
            {
                ans += memo[l];
                l = 0;
            } else {
                ans += memo[l];
                l++;
                i++;
            }

            
        }
        cout << ans << "\n";
        
        
        for (int i = 0; i < m+1; i++)
        {
            cout << memo[i] << " " << vendeu[i] << " ";
        }
    
        cout << "\n";
        
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome