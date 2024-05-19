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

int adj[25][25];
int visited[25];
int dist[25];
int parent[25];

int v;

void dfs(int source)
{
    stack<pii> st;
    st.push({source, {-1, 0}});
    parent[source] = -1;
    dist[source] = 0;

    while (!st.empty())
    {
        pii cur = st.top();
        st.pop();

        if (!visited[cur.f])
        {

            visited[cur.f] = true;
            for (int i = v - 1; i >= 0; i--)
            {
                if (adj[cur.f][i] == 1)
                {
                    st.push({i, {cur.f, cur.s.s + 1}});
                    dist[i] = dist[cur.f] + 1;
                    parent[i] = cur.f;
                }
            }

            if (cur.s.f != -1)
            {
                int d = cur.s.s;
                while (d--)
                {
                    cout << "  ";
                }

                if (st.empty())
                {
                    cout << cur.s.f << "-" << cur.f << " pathR(G," << cur.f << ")" << '\n';
                }
                else
                {
                    cout << cur.s.f << "-" << cur.f << " pathR(G," << cur.f << ")\n";
                }
            }
        }
        else
        {
            // print visitado
            if (cur.s.f != -1)
            {
                int d = cur.s.s;
                while (d--)
                {
                    cout << "  ";
                }
                if (st.empty())
                {
                    cout << cur.s.f << "-" << cur.f << '\n';
                }
                else
                {
                    cout << cur.s.f << "-" << cur.f << '\n';
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, e, caso, x, j;

    cin >> t;
    caso = 1;

    while (t--)
    {
        cout << "Caso " << caso << ":\n";
        caso++;
        cin >> v >> e;
        memset(visited, 0, sizeof(visited));
        memset(parent, 0, sizeof(parent));
        memset(dist, 0, sizeof(dist));
        memset(adj, 0, sizeof(adj));

        for (int i = 0; i < e; i++)
        {
            cin >> x >> j;
            adj[x][j] = 1;
        }

        for (int i = 0; i < v; i++)
        {
            if (visited[i] == 0)
            {
                bool has = false;
                for (int j = v - 1; j >= 0; j--)
                {
                    if (adj[i][j] == 1)
                    {
                        has = true;
                        break;
                    }
                }
                if (has == true)
                {
                    dfs(i);
                    cout << '\n';
                }
            }
        }

        // cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome