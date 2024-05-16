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

const int MAX = int(412);
const int INF = int(1e9);

int n, m, p;

int ng[MAX][MAX];
int dist[MAX][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int u, v;

    cin >> n >> m >> p;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        ng[u][v] = 1;
        ng[v][u] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else if (ng[i][j])
                dist[i][j] = ng[i][j];
            else
                dist[i][j] = INF;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < p; i++)
    {
        cin >> u >> v;

        if (dist[u][v] < INF) {
            cout << "Lets que lets\n";
        } else {
            cout << "Deu ruim\n";
        }

    }
    

    return 0;
}
