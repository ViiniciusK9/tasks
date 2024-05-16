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

const int MAX = int(51234);

array<int, MAX> visited;

vector<int> ng[MAX];

void dfs(int s, int f)
{
    visited[s] = f;
    queue<int> q;
    for (auto vi : ng[s])
    {
        q.push(vi);
    }
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (!visited[cur]) {
            visited[cur] = f;
            for (auto vi : ng[cur])
            {
                q.push(vi);
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    while (cin >> n >> m)
    {
        int u, v;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            ng[u].pb(v);
            ng[v].pb(u);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0) {
                ans++;
                dfs(i, ans);
            }
        }
        cout << ans << '\n';
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome