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

vector<int> adj[MAX];
map<string, int> m1;
map<int, string> m2;

array<bool, MAX> visited;
array<int, MAX> dist;

void bfs(int source)
{
    dist[source] = 0;
    queue<int> q;

    q.push(source);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (!visited[cur]) 
        {
            visited[cur] = true;

            for (auto vi : adj[cur])
            {
                q.push(vi);
                dist[vi] = dist[cur] + 1;
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, g;

    cin >> n >> g;
    string s1, s2;
    int qnt = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;

        if (m1.find(s1) == m1.end()) {
            m1[s1] = qnt;
            m2[qnt] = s1;
            qnt++;
        }

        if (m1.find(s2) == m1.end()) {
            m1[s2] = qnt;
            m2[qnt] = s2;
            qnt++;
        }

        adj[m1[s1]].pb(m1[s2]);
        adj[m1[s2]].pb(m1[s1]);
    }

    bfs(m1["Rerisson"]);
    int ans = 0;
    set<string> se;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] <= g && dist[i] != 0) {
            ans++;
            se.insert(m2[i]);
        }
    }

    cout << ans << '\n';

    for (auto vi : se)
    {
        cout << vi << '\n';
    }
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome