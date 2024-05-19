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

const int MAX = 260;
const int INF = int(1e9);

int mat[MAX][MAX];
int dist[MAX][MAX];
array<int, MAX> custo;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, c, dest, u, v, w;

    while (cin >> n >> m >> c >> dest)
    {
        if (n == 0)
        {
            break;
        }

        custo.fill(0);

        memset(mat, -1, sizeof(mat));
        memset(dist, 0, sizeof(dist));

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            mat[u][v] = w;
            mat[v][u] = w;
        }

        custo[c - 1] = 0;
        for (int i = c - 1; i > 0; i--)
        {
            custo[i - 1] += custo[i] + mat[i - 1][i];
            //DBG(custo[i - 1]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    dist[i][j] = 0;
                else if (mat[i][j] != -1)
                    dist[i][j] = mat[i][j];
                else
                    dist[i][j] = INF;
            }
        }

        for (int k = n-1; k >= c-1; k--)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        set<int> ans;
        ans.insert(dist[dest][c-1]);
        //cout << dist[dest][c-1] << '\n';

        for (int i = 0; i <= c-1; i++)
        {
            ans.insert(custo[i] + dist[dest][i]);
        }
        
        int res = INF;

        for (auto vi : ans)
        {
            //DBG(vi);
            res = min(res, vi);
        }
        

        cout << res << '\n';
        

    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome