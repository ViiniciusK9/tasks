#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef queue<int> qi;
typedef stack<int> si;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

map<int, int> idade;
map<int, int> ident;

vi ng[505];
bool visited[505];

int dfs(int source)
{

    int ans = 1000;
    qi q;
    visited[source] = true;
    for (auto nei : ng[source])
    {
        visited[nei] = true;
        ans = min(ans, idade[nei]);
        q.push(nei);
    }

    while (!q.empty())
    {
        int at = q.front();
        q.pop();

        for (auto nei : ng[at])
        {
            if (!visited[nei])
            {
                ans = min(ans, idade[at]);
                q.push(nei);
            }
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, u, v, a, b, consulta;
    char t;

    cin >> n >> m >> consulta;

    for (int i = 1; i <= n; i++)
    {
        cin >> idade[i];
        ident[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        ng[v].pb(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";

        for (int j = 0; j < ng[i].size(); j++)
        {
            cout << ng[ident[i]][j] << " ";
        }
        cout << '\n';
    }

    while (consulta--)
    {
        cin >> t;
        if (t == 'T')
        {
            cin >> a >> b;
            // swap(idade[a], idade[b]);
            swap(ident[a], ident[b]);
            for (int i = 1; i <= n; i++)
            {
                cout << i << ": ";
                cout << "ident: " << ident[i] << ": ";
                for (int j = 0; j < ng[i].size(); j++)
                {
                    cout << ng[i][j] << " ";
                }
                cout << '\n';
            }
        }
        else
        {
            cin >> a;
            // memset(visited, 0, sizeof(visited));

            // cout << dfs(a) << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome