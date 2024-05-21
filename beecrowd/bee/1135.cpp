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

const int MAX = int(1e5 + 10);

map<int, map<int, ll>> ma;

vector<pi> adj[MAX];
array<bool, MAX> visited;

void bfs(int source, int dest)
{
    //DBG(source);
    //DBG(dest);
    queue<pi> q;
    q.push({source, 0});

    while (!q.empty())
    {
        pi cur = q.front();
        q.pop();

        int at, w;
        at = cur.first;
        w = cur.second;

        
        
        if (!visited[at])
        {
            visited[at] = true;

            if (at == dest) {
                ma[source][dest] = w;
                return;
            }

            int adest, aat;
            if (dest > at) {
                adest = at;
                aat = dest;
            } else {
                adest = dest;
                aat = at;
            }
            if (ma[aat][adest] != 0)
            {
                ma[source][dest] = ma[aat][adest] + w;
                return;
            }

            if (ma[adest][aat] != 0)
            {
                ma[source][dest] = ma[adest][aat] + w;
                return;
            }


            for (auto vi : adj[at])
            {
                q.push({vi.first, vi.second + w});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, v, w, u;

    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }

        ma.clear();

        for (int i = 0; i < MAX; i++)
        {
            adj[i].clear();
        }
        


        for (int i = 1; i <= n - 1; i++)
        {
            cin >> v >> w;
            adj[i].pb({v, w});
            adj[v].pb({u, w});
            if (i < v) {
                ma[v][i] = w;
            } else {
                ma[i][v] = w;
            }
        }
        int q, a, b;
        cin >> q;

        while (q--)
        {
            cin >> a >> b;
            DBG(a);
            DBG(b);
            if (b == a)
            {
                cout << "0 ";
            }
            else if (b > a)
            {
                swap(a, b);

                if (ma[a][b] != 0)
                {
                    cout << ma[a][b] << '\n';
                }
                else
                {
                    visited.fill(false);
                    bfs(a, b);
                    cout << ma[a][b] << " ";
                }
            }
            else
            {
                if (ma[a][b] != 0)
                {
                    cout << ma[a][b] << '\n';
                }
                else
                {
                    visited.fill(false);
                    bfs(a, b);
                    cout << ma[a][b] << " ";
                }
            }
            
        }
        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome