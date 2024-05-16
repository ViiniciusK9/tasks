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

const int MAX = int(1123);

array<bool, MAX> visited;
int n, _p[MAX], _rank[MAX];
vector<int> ng[MAX];

vector<pii> eg;

// MUF - Make Union Find

int _find(int u) {
    // base case
    if (_p[u] == u)
    {
        return u;
    }
    
    // rec case
    return (_p[u] = _find(_p[u]));
}

void _union(int u, int v) {
    u = _find(u);
    v = _find(v);
    if (_rank[u] < _rank[v]) {
        _p[u] = v;
    } else {
        _p[v] = u;
        if (_rank[u] == _rank[v]) {
            _rank[u]++;
        }
    }
}

long long kruskal() {
    long long ans = 0, u, v, wei;
    pi e;
    for (u = 1; u <= n; u++) _p[u] = u;
    sort(eg.begin(), eg.end());
    for (auto &it : eg) {
        e = it.second;
        wei = it.first;
        u = e.first; v = e.second;
        if (_find(u) != _find(v))
        {
            _union(u, v);
            ans += wei;
        }
    }
    return ans;
}

void dfs(int s)
{
    visited[s] = true;
    queue<int> q;
    for (auto vi : ng[s])
    {
        q.push(vi);
    }

    while (!q.empty())
    {
        int cur = q.front();
        //DBG(cur);
        q.pop();
        if (!visited[cur]) {
            visited[cur] = true;
            for (auto vi : ng[cur]) {
                q.push(vi);
            }   
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    int u, v, w;

    while (cin >> n >> m)
    {
        eg.clear();
        visited.fill(false);
        for (int i = 0; i < MAX; i++)
        {
            ng[i].clear();
        }
        
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            eg.pb({w, {u, v}});
            ng[u].pb(v);
            ng[v].pb(u);
        }
        dfs(1);
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            //DBG(visited[i]);
            if (visited[i] == false) {
                flag = 1;
                break;
            }
        }


        if (flag == 0) {
            cout << kruskal() << '\n';
        } else {
            cout << "impossivel\n";
        }

        
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome