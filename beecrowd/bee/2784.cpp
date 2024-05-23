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

const int MAX = int(1123);
const int INF = int(1e9);

array<int, MAX> dist;
array<int, MAX> processed;

vector<pi> adj[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int u, v, w;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    int x;
    cin >> x;

    priority_queue<pi> q;

    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[x] = 0;
    q.push({0, x});
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if (processed[a])
            continue;
        processed[a] = true;
        for (auto u : adj[a])
        {
            int b = u.first, w = u.second;
            if (dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }

    int ma, mi;
    if (x == 1)
    {
        ma = mi = dist[2];
    }
    else
    {
        ma = mi = dist[1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != 0)
        {
            ma = max(ma, dist[i]);
            mi = min(mi, dist[i]);
        }
    }

    cout << ma - mi << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome