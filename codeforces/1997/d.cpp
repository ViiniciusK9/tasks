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

const int MAX = 2e5+10;

vector<ii> adj[MAX];

int dfs(ii s) {

    int qnt = 0;
    int ans = INT_MAX;
    for (auto ng : adj[s.first])
    {
        ans = min(ans, dfs(ng));
        qnt++;
    }

    if (qnt == 0) {
        return s.second;
    } else {
        if (s.second < ans) {
            return (s.second + ans) / 2;
        } else {
            return ans;
        }
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
        vi v;
        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            v.pb(aux);
        }

        for (int i = 0; i < n-1; i++)
        {
            int pi;
            cin >> pi;
            adj[pi].pb({i+2, v[i+1]});
        }

        vi child;
        int mi = INT_MAX;
        for (auto el : adj[1])
        {
            child.pb(el.first);
            mi = min(mi, dfs(el));
        }

        cout << v[0] + mi << '\n';
        
        for (int i = 1; i < n+1; i++)
        {
            adj[i].clear();
            
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome