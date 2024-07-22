#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

const int MAX = int(1e5 + 10);
const ll INF = 1e14 + 10;

vector<ii> adj[MAX];
ll dist[MAX];
bool processed[MAX];
int parent[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    int x = 1;

    priority_queue<ii, vector<ii>> q;

    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[x] = 0;
    parent[x] = -1;
    q.push({0, x});
    while (!q.empty())
    {
        ll a = q.top().second;
        q.pop();
        if (processed[a])
            continue;
        processed[a] = true;
        for (auto u : adj[a])
        {
            ll b = u.first, w = u.second;
            if (dist[a] + w < dist[b])
            {
                parent[b] = a;
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }

    if (dist[n] != INF)
    {
        vi path;
        int pa = n;
        while (pa != -1)
        {
            path.pb(pa);
            pa = parent[pa];
        }

        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++)
        {
            cout << (i == 0 ? "" : " ") << path[i];
        }

        cout << '\n';
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome