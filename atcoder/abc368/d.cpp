#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define fi first 
#define se second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 2e5+10;

int n, k;
vi adj[MAX];
vi ks(MAX);
array<bool, MAX> nes;
array<bool, MAX> vis;

ll ans;

bool dfs(int s) {

    vis[s] = true;
    int ngs = 0;
    bool t1 = false;
    for (auto ng : adj[s])
    {
        if (!vis[ng]) {
            bool res = dfs(ng);
            if (res) {
                ans++;
            }
            t1 = res | t1;
            ngs++;
        }
    }
    

    if (nes[s]) {
        return true;
    }
    return t1;

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 0; i < k; i++)
    {
        cin >> ks[i];
        nes[ks[i]] = true;
    }
    
    ans = 0;

    dfs(ks[0]);

    cout << ans + 1 << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome