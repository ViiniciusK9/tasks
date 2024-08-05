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

const int MAX = int(2e5+10);
const ll INF = INT64_MAX;

ll dist[MAX];

int processed[MAX];

vector<ii> adj[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u-1].pb({v-1, w+a[v-1]});
        adj[v-1].pb({u-1, w+a[u-1]});

    }
    

    int x = 0;

    priority_queue<ii, vector<ii>> q;

    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[x] = a[0];
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

    for (int i = 1; i < n; i++)
    {
        cout << (i == 1 ? "" : " ") << dist[i];
    }

    cout << '\n';
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome