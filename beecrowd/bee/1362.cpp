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

const int INF = int(1e9 + 90);

const int MAX = 100;

int n;
array<array<int, MAX>, MAX> capacity;
array<vector<int>, MAX> adj;

int bfs(int s, int t, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur])
        {
            if (parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t)
{
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent))
    {
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    n = 100;
    cin >> t;
    int m, num;
    string s1, s2;

    map<string, int> ma;
    ma["XXL"] = 1;
    ma["XL"] = 2;
    ma["L"] = 3;
    ma["M"] = 4;
    ma["S"] = 5;
    ma["XS"] = 6;

    for (int i = 1; i <= 6; i++)
    {
        adj[0].pb(i);
    }

    while (t--)
    {
        for (int i = 1; i < m+8; i++)
        {
            adj[i].clear();
        }
        
        cin >> num >> m;
        int cap = num / 6;
        for (int i = 1; i <= 6; i++)
        {
            capacity[0][i] = cap;
        }

        for (int i = 7; i <= m+6; i++)
        {
            cin >> s1 >> s2;
            adj[ma[s1]].pb(i);
            adj[i].pb(ma[s1]);
            capacity[ma[s1]][i] = 1;
            capacity[i][ma[s1]] = 1;
            adj[ma[s2]].pb(i);
            adj[i].pb(ma[s2]);
            capacity[ma[s2]][i] = 1;
            capacity[i][ma[s2]] = 1;
            adj[i].pb(m+8);
            adj[m+8].pb(i);
            capacity[i][m+8] = 1;
        }

        /*
        for (int i = 0; i <= m+8; i++)
        {
            cout << i << " : ";
            for (auto vi : adj[i])
            {
                cout << "(" << i << ", " << vi <<") "; 
            }
            cout << "\n";
            
        }
        */
        
        
        
        int ans = maxflow(0, m+8);
        if (ans == m) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome