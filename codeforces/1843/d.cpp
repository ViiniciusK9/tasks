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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = int(2e5+10);

vi adj[MAX];

array<ll, MAX> dp;

array<bool, MAX> visited;


void dfs(int so) {

    visited[so] = true;
    int qnt = 0;
    int sum = 0;
    for (auto ng : adj[so])
    {

        if (!visited[ng]) {
            dfs(ng);
            sum += dp[ng];
            qnt++;
        }
    }

    if (qnt == 0) {
        dp[so] = 1;
    } else {
        dp[so] = sum;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        dp.fill(0);
        visited.fill(false);

        for (int i = 0; i < n-1; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int q;
        cin >> q;
        dfs(1);
        while (q--)
        {
            int x, y;

            cin >> x >> y;

            cout << dp[x] * dp[y] << '\n';

        }
        










        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome