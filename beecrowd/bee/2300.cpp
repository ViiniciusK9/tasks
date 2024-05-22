#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = int(110);

vector<int> adj[MAX];
array<bool, MAX> visited;


int bfs(int source)
{
    int ans = 0;
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();


        if (!visited[cur]) {
            ans++;
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

    int n, m, u, v;
    int caso = 1;
    while (cin >> n >> m)
    {
        if (n == m && n == 0) {
            break;
        }

        visited.fill(false);

        for (int i = 0; i < MAX; i++)
        {
            adj[i].clear();
        }
        

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        cout << "Teste " << caso << "\n";
        caso++;
        if (bfs(1) >= n) {
            cout << "normal\n";
        } else {
            cout << "falha\n";
        }
        cout << '\n';
        


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome