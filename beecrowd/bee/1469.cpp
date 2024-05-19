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

const int MAX = int(512);

map<int, int> idade;
map<int, int> ident;
array<bool, MAX> visited;

vi adj[MAX];

int bfs(int source)
{
    //DBG(source);
    int ans = 10000;
    source = ident[source];
    queue<int> q;

    for (auto vi : adj[source])
    {
        q.push(vi);
    }

    while (!q.empty())
    {

        int cur = q.front();
        q.pop();
        int aux;

        //DBG(cur);

        if (!visited[cur])
        {
            for (auto vi : ident)
            {
                if (vi.second == cur) {
                    aux = vi.first;
                    break;
                }
            }
            
            ans = min(ans, idade[aux]);
            visited[cur] = true;
            for (auto vi : adj[cur])
            {
                q.push(vi);
            }
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, id;

    while (cin >> n >> m >> i)
    {
        for (int i = 0; i < MAX; i++)
        {
            adj[i].clear();
        }
        

        for (int i = 1; i <= n; i++)
        {
            cin >> id;
            idade[i] = id;
            ident[i] = i;
        }
        int u, v;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            adj[v].pb(u);
        }

        char op;
        int a, b;

        while (i--)
        {
            cin >> op;

            if (op == 'T') 
            {
                cin >> a >> b;
                swap(ident[a], ident[b]);
            } 
            else 
            {
                cin >> a;
                visited.fill(false);
                int ans = bfs(a);
                if (ans == 10000) {
                    cout << "*\n";
                } else {
                    cout << ans << '\n';
                }
            }
        }
        
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome