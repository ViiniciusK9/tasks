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

const int MAX = int(10123);

vector<int> adj[MAX];
array<bool, MAX> visited;
array<int, MAX> dist;

int bfs(int source)
{
    int ans = 0;
    queue<int> q;
    q.push(source);
    dist[source] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (!visited[cur])
        {
            ans = max(ans, dist[cur]);

            visited[cur] = true;

            for (auto vi : adj[cur])
            {
                q.push(vi);
                if (dist[vi] == 0)
                {
                    dist[vi] = dist[cur] + 1;
                }
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, d;

    cin >> n >> m >> d;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        visited.fill(false);
        dist.fill(0);
        ans = max(bfs(i), ans);
    }
    
    int aux = (2*d + 1);

    if (aux <= ans) {
        cout << "0 0\n";
    } else {
        cout << aux - ans << " " << aux - ans << '\n';
    }


    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome