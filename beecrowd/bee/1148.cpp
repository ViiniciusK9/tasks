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

const int MAX = 510;

const int INF = int(1e9);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, querys, e, u, v, w;

    int adj[MAX][MAX];
    int distance[MAX][MAX];
    bool fir = true;
    while (true)
    {
        cin >> n;
        cin >> e;
        if (n == e && e == 0)
        {
            break;
        }
        if (fir == false) {
            memset(adj, 0, sizeof(adj));
            memset(distance, 0, sizeof(distance));
        }

        //DBG(n);
        //DBG(e);

        for (int i = 0; i < e; i++)
        {
            cin >> u >> v >> w;
            //DBG(u);
            //DBG(v);
            //DBG(w);
            
            adj[u][v] = w;
            //distance[u][v] = w;
        }
        cin >> querys;
        fir = false;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    distance[i][j] = 0;
                else if (adj[i][j] && adj[j][i])
                    distance[i][j] = 0;
                else if (adj[i][j])
                    distance[i][j] = adj[i][j];
                else
                    distance[i][j] = INF;
            }
        }

        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
        
        for (int i = 0; i < querys; i++)
        {
            cin >> u >> v;

            if (adj[u][v] != 0 && adj[v][u] != 0) {
                cout << "0\n";
            } else if (distance[u][v] != INF) {
                cout << distance[u][v] << '\n';
            } else {
                cout << "Nao e possivel entregar a carta\n";
            }
        }
        
        cout << "\n";
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome