#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)

typedef pair<int, int> pii;

const int maxn = 100;
const int inf = 1e9 + 10;

int n, m;

// distância Atual de cada vértice
int dist[maxn][maxn][maxn];

// vetor que irá marcar os vértices visitados
bool mark[maxn][maxn][maxn];

// lista de adjacência que guarda um par (vértice, peso)
vector<pii> grafo[maxn];

void dijkstra(int S, int k, int d)
{
    // primeira etapa do algoritmo
    for (int i = 1; i <= n; i++)
        dist[i][k][S] = inf;

    dist[S][k][S] = 0;

    // fila de prioridade para guardar a distância atual de cada vértice em ordem crescente
    priority_queue<pii, vector<pii>, greater<pii>> fila;

    // inicialmente, inserimos apenas a origem
    fila.push({0, S});

    // quando todos os vértices forem marcados, a fila ficará vazia, e nesse momento o algoritmo para
    while (!fila.empty())
    {
        // segunda etapa do algoritmo
        int u = fila.top().second;
        fila.pop();

        // se U já foi marcado, apenas o ignoramos
        if (mark[u])
            continue;

        // marcamos U
        mark[u][k][S] = 1;

        for (auto V : grafo[u])
        {
            int v = V.first, w = V.second;

            if (v > k && v != d)
                continue;

            // terceira etapa do algoritmo
            if (dist[v] > dist[u] + w)
            {
                // atualizamos a distância atual de V e a inserimos na fila
                dist[v][k][S] = dist[u][k][S] + w;
                fila.push({dist[v][k][S], v});
            }
        }
    }

    // No fim do algoritmo, o vetor 'dist' possuirá o menor caminho para
    // todos os vértices do grafo
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m)
    {


        int u, v, w, q, k;

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            grafo[u - 1].push_back({v - 1, w});
        }

        cin >> q;

        while (q--)
        {
            fill(mark, mark + maxn, false);
            fill(dist, dist + maxn, 0);
            cin >> u >> v >> k;
            if (mark[v - 1][k-1][u-1])
            {
                cout << dist[v - 1] << '\n';
            }
            else
            {
                dijkstra(u - 1, k - 1, v - 1);
                if (mark[v - 1][k-1][u-1])
                {
                    cout << dist[v - 1] << '\n';
                } else {

                    cout << "-1\n";
                }
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome