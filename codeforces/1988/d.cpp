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

const int MAX = int(3e5+10);
int n;
vector<ll> dmg;

vi adj[MAX];

array<int, MAX> color;
array<bool, MAX> visited;

void bfs(int so) {

    queue<int> q;
    q.push(so);
    visited[so] = true;
    color[so] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto ng : adj[cur])
        {
            if (!visited[ng]) {
                color[ng] = 1 - color[cur];
                visited[ng]=true;
                q.push(ng);
            }
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
        cin >> n;
        dmg.clear();
        visited.fill(false);
        color.fill(-1);

        for (int i = 0; i < MAX-2; i++)
        {
            adj[i].clear();
        }
        
        

        for (int i = 0; i < n; i++)
        {
            ll aux;
            cin >> aux;
            dmg.pb(aux);

        }


        for (int i = 0; i < n-1; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        bfs(1);

        ll sum1 = 0;
        ll sum2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 1) {
                sum1 += dmg[i-1];
            } else if (color[i] == 0) {
                //DBG(i);
                sum2 += dmg[i-1];
            }
        }

        

        //DBG(sum1);
        //DBG(sum2);

        ll ans = (sum1+sum2) + (min(sum1, sum2));
        
        cout << ans << '\n';
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome