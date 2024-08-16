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

const int MAXN = 1123;
const int MAXK = 11234;

int n, m, k, a, b;
vector<ii> adj[MAXN];
bool dp[MAXN][MAXK];
int parent[MAXN][MAXK];
int edge_len[MAXN][MAXK];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    cin >> a >> b;

    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w}); 
    }

    //memset(dp, false, sizeof(dp));
    dp[a][0] = true;

    for(int len = 0; len <= k; ++len) {
        for(int node = 1; node <= n; ++node) {
            if(dp[node][len]) {
                for(auto edge : adj[node]) {
                    int next = edge.f;
                    int l = edge.s;
                    if(len + l <= k) {
                        //DBG(len+l);
                        //DBG(next);

                        dp[next][len + l] = true;
                        parent[next][len + l] = node;
                        edge_len[next][len + l] = l;
                    }
                }
            }
        }
    }

    if(dp[b][k]) {
        vi path;
        int cur = b;
        int len = k;
        while(len > 0) {
            path.pb(cur);
            int prev = parent[cur][len];
            len -= edge_len[cur][len];
            cur = prev;
        }
        path.pb(a);
        reverse(path.begin(), path.end());

        bool fir = false;
        for(int node : path) {
            cout << (fir ? "" : " ") <<node;
            fir = false;
        }
        cout << '\n';
    } else {
        cout << "Impossible\n";
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome
