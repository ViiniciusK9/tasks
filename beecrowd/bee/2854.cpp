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

const int MAX = int(350);

vector<int> adj[MAX];
array<bool, MAX> visited;

void bfs(int source)
{
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (!visited[cur]) {
            visited[cur] = true;

            for (auto vi : adj[cur])
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

    int m, n;

    cin >> m >> n;

    string s1, s2, s3;
    map<string, int> ma;

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2 >> s3;

        if (ma.find(s1) == ma.end()) {
            ma[s1] = j;
            j++;
        }

        if (ma.find(s3) == ma.end()) {
            ma[s3] = j;
            j++;
        }
        int u, v;
        u = ma[s1];
        v = ma[s3];
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    int ans = 0;
    for (int i = 0; i < j; i++)
    {
        if (visited[i] == false) {
            bfs(i);
            ans++;
        }
    }

    cout << ans << '\n';
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome