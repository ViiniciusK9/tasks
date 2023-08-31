#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 1123
#define INF 112345678

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;


int n, lg[MAX][MAX], ag[MAX][MAX], d[MAX], pr[MAX], s, t, c;
int dist[MAX][MAX];

int dijkstra(void)
{
    int u, i, l, v, _d;
    priority_queue< iii, vector<iii>, greater<iii> > q;

    for (u = 0; u < n; u++)
    {
        for (l = 0; l < c; l++)
        {
            dist[u][l] = INF;
        }
    }
    dist[s][0] = 0;
    q.push( iii(dist[s][0], ii(s, 0)) );

    while (!q.empty())
    {
        u = q.top().second.first;
        l = q.top().second.second;
        _d = q.top().first;
        q.pop();
        
        // para evitar calcular uma aresta que já foi processada com prioridade maior antes
        if (_d > dist[u][l]) continue;
        
        // achou o destino e já retorna a resposta com o custo minimo
        if (u == t)
        {
            return dist[u][l];
        }
        
        // daqui pra baixo só Deus sabe o que está acontecendo
        if (l < c && dist[u][l + 1] > dist[u][l] + pr[u])
        {
            dist[u][l + 1] = dist[u][l] + pr[u];
            q.push( iii( dist[u][l + 1], ii(u, l + 1) ) );
        }

        for ( i = 0; i < d[u]; i++)
        {
            v = lg[u][i];
            if (l >= ag[u][v] && dist[v][l - ag[u][v]] > dist[u][l])
            {
                q.push( iii(dist[v][l - ag[u][v]], ii(v, l - ag[u][v])) );
            }
            
        }
        
    }
    
    return INF;
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, u, v, wei, q, ans;

    while (cin >> n >> m)
    {
        // preenchendo vetor com preço
        for (int u = 0; u < n; u++)
        {
            cin >> pr[u];
        }

        // preenchendo as distancias com infinito para garantir que vai sempre pegar o caminho mais curto já que o problema não garante caminho
        // unico
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ag[i][j] = INF;
            }
        }

        memset(d, 0, sizeof(d));

        while (m--)
        {
            cin >> u >> v >> wei;
            if (ag[u][v] == INF)
            {
                lg[u][d[u]++] = v;
                lg[v][d[v]++] = u; 
            }
            
            ag[u][v] = ag[v][u] = min(ag[u][v], wei);
        }
        
        cin >> q;
        while (q--)
        {
            cin >> c >> s >> t;

            ans = dijkstra();
            if (ans == INF)
            {
                cout << "impossible\n";
            }
            else
            {
                cout << ans << '\n';
            }
            

        }
        

        
    }
    




    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome