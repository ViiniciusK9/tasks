#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = int(1e3 + 10);
int n;
vector<int> ng[MAX];
set<int> keys[MAX];
set<int> my_keys;
array<bool, MAX> visited;
array<bool, MAX> vis;

void bfs(int source)
{
    queue<int> q;
    queue<int> qa;

    for (auto k : keys[source])
    {
        my_keys.insert(k);
    }

    visited[source] = true;

    for (auto vi : ng[source])
    {
        q.push(vi);
    }
    int ini = 0, at;
    while (true)
    {
        ini = my_keys.size();
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (!visited[cur])
            {
                if (my_keys.find(cur) != my_keys.end()) {
                    visited[cur] = true;

                    for (auto k : keys[cur])
                    {
                        my_keys.insert(k);
                    }

                    for (auto vi : ng[cur])
                    {
                        q.push(vi);
                    }
                } else {
                    qa.push(cur);
                }
            }
        }
        at = my_keys.size();

        if (ini == at) {
            break;
        }
        while (!qa.empty())
        {
            q.push(qa.front());
            qa.pop();
        }
        
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, a, b, sala;

    while (cin >> n >> m)
    {
        my_keys.clear();
        visited.fill(false);
        for (int i = 0; i < MAX; i++)
        {
            ng[i].clear();
            keys[i].clear();
        }

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            ng[a].pb(b);
            ng[b].pb(a);
        }

        for (int i = 2; i <= n; i++)
        {
            cin >> sala;
            keys[sala].insert(i);
        }

        bfs(1);
        int ans = 1;
        for (int i = 1; i <= n; i++)
        {
            if(visited[i] == false) {
                ans = 0;
                break;
            }
        }
        
        if (ans == 1) {
            cout << "sim\n";
        } else {
            cout << "nao\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome