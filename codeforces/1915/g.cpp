#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

const ll INF = INT64_MAX;
const int MAX = int(1123);
int n, m;

vector<ii> adj[MAX];
// array<bool, MAX> visited;
bool visited[MAX][MAX];
ll dist[MAX][MAX];
// array<ll, MAX> dist;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vi s(n + 1);
        // visited.fill(false);
        memset(visited, false, sizeof(visited));
        // memset(dist, INF, sizeof(dist));
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
        }

        int x = 1;

        priority_queue<iii> q;

        for (int i = 0; i <= 1001; i++)
            for (int j = 0; j <= 1001; j++)
                dist[i][j] = INF;

        dist[x][s[1]] = 0;
        
        q.push({0, {x, s[x]}});
        while (!q.empty())
        {
            ll a = q.top().second.first, bs = q.top().second.second;
            q.pop();
            if (visited[a][bs] || dist[a][bs] == INF)
                continue;
            visited[a][bs] = true;
            for (auto u : adj[a])
            {
                ll b = u.first, w = u.second;
                ll fs = min(bs, s[b]);
                w = w * bs;

                if (dist[a][bs] + w < dist[b][fs])
                {
                    dist[b][fs] = dist[a][bs] + w;
                    q.push({-dist[b][fs], {b, fs}});
                }
            }
        }

        ll ans = INF;

        for (int i = 1; i <= 1000; i++)
        {
            ans = min(ans, dist[n][i]);
        }

        cout << ans << '\n';

        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome