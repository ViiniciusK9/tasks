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

const int MAX = int(1e5 + 10);
const int LM = log2(100010) + 1;

int n, l;
vector<ii> adj[MAX];

int timer;
// vector<int> tin, tout;
ll tin[MAX];
ll tout[MAX];
// vector<vector<int>> up;
ll up[MAX][LM];

bool visited[MAX];
ll dist[MAX];

void bfs(int s)
{

    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        // DBG(cur);

        for (auto ng : adj[cur])
        {
            if (!visited[ng.first])
            {
                visited[ng.first] = true;
                dist[ng.first] = ng.second + dist[cur];
                q.push(ng.first);
            }
        }
    }
}

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (auto u : adj[v])
    {
        if (u.first != p)
            dfs(u.first, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i)
    {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root)
{
    // tin.resize(n);
    // tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    // up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n)
    {

        if (n == 0)
            break;
        int u, w;
        for (int i = 1; i < n; i++)
        {
            cin >> u >> w;
            adj[u].pb({i, w});
        }
        bfs(0);
        preprocess(0);

        int m;

        cin >> m;
        bool fir = true;
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            int me = lca(a, b);
            cout << (fir ? "" : " ") << dist[a] + dist[b] - (2 * dist[me]);
            fir= false;
        }
        cout << '\n';

        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
        }

        timer = 0;

        //memset(tin, 0, sizeof(tin));
        //memset(tout, 0, sizeof(tout));
        //memset(up, 0, sizeof(up));
        memset(visited, false, sizeof(visited));
        //memset(dist, 0, sizeof(dist));

    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome