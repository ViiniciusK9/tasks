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

vector<int> adj[MAX];
array<int, MAX> visited;
array<int, MAX> dist;


int dfs(int source, int m)
{
    visited[source] = m;
    dist[source] = 1;
    stack<int> st;

    int ans = 1;
    for (auto nei : adj[source])
    {
        st.push(nei);
        dist[nei] = dist[source] + 1;
        ans = max(ans, dist[nei]);
    }

    while (!st.empty())
    {
        int cur = st.top();
        st.pop();
        
        if (visited[cur] == 0)
        {
            visited[cur] = m;

            for (auto nei : adj[cur])
            {
                st.push(nei);
                dist[nei] = dist[cur] + 1;
                ans = max(ans, dist[nei]);
            }
        } else if (visited[cur] == m)
        {
            return -1;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, aux;

    while (cin >> n)
    {
        for (int i = 0; i < MAX; i++)
        {
            adj[i].clear();
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> m;

            for (int j = 0; j < m; j++)
            {
                cin >> aux;
                adj[i].pb(aux);
            }
        }
        visited.fill(0);
        int ans = 0;
        int ma = 0;
        for (int i = 1; i <= n; i++)
        {
            visited.fill(0);
            dist.fill(0);
            ans = dfs(i, i);
            if (ans == -1) {
                cout << "-1\n";
                break;
            } else {
                ma = max(ma, ans);
            }
        }

        if (ans != -1) {
            cout << ma << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome