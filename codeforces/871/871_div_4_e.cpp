#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 1111

int vet[MAX][MAX];
int vis[MAX][MAX];
int m, n;

long long busca(int i, int j) {
    long long ans = 0;

    if (vet[i][j] == 0 || vis[i][j] || i >= n || i < 0 || j >= m || j < 0)
    {
        return 0;
    }
    vis[i][j] = 1;
    ans += vet[i][j];
    ans += busca(i+1, j);
    ans += busca(i-1, j);
    ans += busca(i, j+1);
    ans += busca(i, j-1);
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, aux;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> vet[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            memset(vis[i], 0, sizeof(vis[i]));
        }

        long long maior  = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0)
                {
                    aux = busca(i, j);
                    if (aux > maior) maior = aux;
                }
                
            }
            
        }
        cout << maior << '\n';
    }

    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome