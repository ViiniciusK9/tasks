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

const int MAX = int(2e5+10);

vi adj[MAX];
ll qnt[MAX];
bool visited[MAX];


ll bfs(int source) {
    queue<int> q;
    
    qnt[source] = 1;
    //visited[source] = true;
    
    
    q.push(source);
    
    

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        //DBG(cur);

        if (!visited[cur]) {
            visited[cur] = true;
            for (auto vi : adj[cur])
            {
                if (qnt[vi] != 0) {
                    qnt[source] += qnt[cur];
                } else {
                    qnt[source]++;
                    q.push(vi);
                }

            }
        } else if (source != cur) {
            qnt[source] += qnt[cur];
        }
    }
    //DBG(qnt[source]);
    return qnt[source];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    int aux;
    for (int i = 1; i <= n; i++)
    {
        cin >> aux;
        adj[i].pb(aux);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (qnt[i] > 0) {
            ans += qnt[i];
        } else {
            ans += bfs(i);
            memset(visited, false, sizeof(visited));
        }
    }

    cout << ans << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome