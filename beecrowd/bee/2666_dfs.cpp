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

const int MAX = int(11234);

array<int, MAX> gold;
array<bool, MAX> visited;
vector<pi> adj[MAX];
int c;

ll dfs(int source)
{
    ll ans = 0;
    visited[source] = true;

    for (auto vi : adj[source])
    {
        if (!visited[vi.f])
        {
            ans += dfs(vi.first);

            gold[source] += gold[vi.f];
            int qnt = gold[vi.f] / c;
            if (gold[vi.f] % c != 0)
            {
                qnt++;
            }
            //DBG(vi.f);
            //DBG((qnt * vi.s * 2));
            ans += (qnt * vi.s * 2);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, u, v, w;

    cin >> n >> c;

    for (int i = 1; i <= n; i++)
    {
        cin >> gold[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    cout << dfs(1) << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome