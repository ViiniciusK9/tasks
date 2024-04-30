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

    qi q;
    visited[source] = true;
    //DBG(source);
    //DBG(idade[source]);
    for (auto nei : ng[source])
    {
        //DBG(idade[nei]);
        //DBG(nei);
        q.push(nei);
    }

    int ans = 1000;

    while (!q.empty())
    {
        int at = q.front();
        q.pop();

        if (!visited[at])
        {
            ans = min(ans, idade[ident[at]]);
            visited[at] = true;
            for (auto nei : ng[at]){
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

    int n, m, i, u, v, a, b;
    char t;

    cin >> n >> m >> i;

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

    while (i--)
    {
        cin >> t;
        if (t == 'T')
        {
            cin >> a >> b;
            //swap(idade[a], idade[b]);
            swap(ident[a], ident[b]);
        }
        else
        {
            cin >> a;
            memset(visited, 0, sizeof(visited));

            cout << dfs(ident[a]) << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome