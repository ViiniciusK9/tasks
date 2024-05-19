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

const int MAX = int(1e4 + 10);

set<int> adj[MAX];
array<bool, MAX> visited;

bool bfs(int source)
{
    queue<int> q;

    visited[source] = true;
    for (auto vi : adj[source])
    {
        q.push(vi);
    }
    

    while (!q.empty())
    {
        int cur = q.front();
        if (cur == source) {
            return false;
        }
        q.pop();
        if (!visited[cur])
        {
            visited[cur] = true;
            for (auto vi : adj[cur])
            {
                q.push(vi);
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, a, b;

    cin >> t;

    while (t--)
    {
        for (int i = 0; i < MAX; i++)
        {
            adj[i].clear();
        }
        visited.fill(false);

        cin >> n >> m;

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].insert(b);
        }

        bool ans = true;
        for (int i = 1; i <= n; i++)
        {
            if (adj[i].size() > 0)
            {
                visited.fill(false);
                ans = bfs(i);
                if (ans == false)
                {
                    break;
                }
            }
        }

        if (ans == true)
        {
            cout << "NAO\n";
        }
        else
        {
            cout << "SIM\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome