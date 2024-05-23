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

const int MAX = int(1e4+10);

bool visited[MAX];

vector<int> adj[MAX];

bool bfs(int source)
{
    queue<int> q;
    //q.push(source);
    visited[source] = true;

    for (auto vi : adj[source])
    {
        q.push(vi);
    }
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == source) {
            return true;
        }

        if (!visited[cur])
        {
            visited[cur] = true;

            for (auto vi : adj[cur])
            {
                q.push(vi);
            }
            
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, u, v;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
    }
    
    int ans = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && ans == 1) {
            ans = -1;
            break;
        }

        if (!visited[i]) {
            flag = bfs(i);
            ans++;
        }
    }

    if (flag == false) {
        cout << "N\n";
    } else if (ans != -1) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome