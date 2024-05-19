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

const int MAX = int(4123);
const int INF = int(1e9);

map<string, int> id;

vector<pi> adj[MAX];
int dist[MAX];
int processed[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string s1, s2;
    cin >> n >> m;
    int e1, p1, sa1;
    int j = 1;
    for (int i = 0; i < m; i++)
    {
        cin >> s1 >> s2;

        if (id.find(s1) == id.end())
        {
            id[s1] = j;
            j++;
        }

        if (id.find(s2) == id.end())
        {
            id[s2] = j;
            j++;
        }

        if (s1 == "Entrada")
        {
            e1 = id[s1];
        }

        if (s1 == "Saida")
        {
            sa1 = id[s1];
        }

        if (s1 == "*")
        {
            p1 = id[s1];
        }

        if (s2 == "Entrada")
        {
            e1 = id[s2];
        }

        if (s2 == "Saida")
        {
            sa1 = id[s2];
        }

        if (s2 == "*")
        {
            p1 = id[s2];
        }

        adj[id[s1]].pb({id[s2],1});
        adj[id[s2]].pb({id[s1],1});
    }

    int x = p1;

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

    cout << dist[e1] + dist[sa1] << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome