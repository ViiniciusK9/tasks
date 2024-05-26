#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = int(212345);

vector<pi> adj[MAX];
array<bool, MAX> visited;

int bfs(int source, int k)
{
    int ans = 0;
    int wa= 0;
    priority_queue<pi> q;

    q.push({0, source});

    while (!q.empty())
    {
        pi cur = q.top();
        q.pop();
        int w, v;
        w = cur.f;
        v = cur.s;

        if (!visited[v]) 
        {
            ans++;
            wa = max(wa, abs(w));
            if (ans == k) {
                return wa;
            }
            //DBG(abs(cur.f));
            //DBG(cur.s);
            visited[v] = true;

            for (auto vi : adj[v])
            {
                q.push({-vi.f, vi.s});
            }
        }
    }
    

    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;

    cin >> n >> m >> k;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;

        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }
    
    cout << bfs(1, k) << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome