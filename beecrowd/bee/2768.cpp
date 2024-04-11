#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)

const int maxn = 100;
const int INF = 1e7 + 10;

int n, m;
int u, v, w, q, kk;
int adj[maxn][maxn];
int dis[maxn][maxn];
int arr[maxn][maxn][maxn];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m)
    {
        for (int i = 0; i < maxn; i++)
        {
            fill(adj[i], adj[i]+maxn, -1);
        }
        
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            adj[u - 1][v - 1] = w;
            adj[v - 1][u - 1] = w;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    dis[i][j] = 0;
                }
                else if (adj[i][j] != -1)
                {
                    dis[i][j] = adj[i][j];
                }
                else
                {
                    dis[i][j] = INF;
                }
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    arr[i][j][k] = dis[i][j];
                }
            }
        }

        cin >> q;

        while (q--)
        {
            cin >> u >> v >> kk;
            if (arr[u-1][v-1][kk-1] < INF) {
                cout << arr[u-1][v-1][kk-1] << '\n';
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome