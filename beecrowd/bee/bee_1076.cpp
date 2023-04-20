#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 60

vector<int> eg[MAX];

int vis[MAX], v, ans;

int dfs(int s) {
    ans ++;
    if (vis[s])
    {
        return 1;
    }
    vis[s] = 1;
    for (auto &j : eg[s]) {
        //ans++;
        dfs(j);
    }
    
    return 1;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, a, n, u, x;
    cin >> t;
    while (t--)
    {

        cin >> n;
        cin >> v >> a;
        for (int i = 0; i < a; i++)
        {
            cin >> u >> x;
            eg[u].push_back(x);
            eg[x].push_back(u);
        }
        ans = 1;
        cout << dfs(n) << '\n';
        cout << ans << '\n';
        for (int i = 0; i < MAX; i++) { eg[i].clear(); vis[i] = 0;} 
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome