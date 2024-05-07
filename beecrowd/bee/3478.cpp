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

const int MAX = int(112345);

int n, a, cont;

int visited[MAX];
vi ng[MAX];

void bfs(int source)
{
    queue<int> q;

    q.push(source);

    while (!q.empty())
    {
        int at = q.front();
        q.pop();

        if (!visited[at]) {
            visited[at] = true;
            for (auto n : ng[at])
            {
                q.push(n);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int u, v;
    cin >> n >> a;

    for (int i = 0; i < a; i++)
    {
        cin >> u >> v;
        ng[u].pb(v);
        ng[v].pb(u);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0) {
            bfs(i);
            ans++;
        }
    }
    
    cout << ans << '\n';
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome