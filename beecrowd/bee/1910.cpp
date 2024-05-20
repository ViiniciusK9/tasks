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

const int MAX = int(1e5 + 10);
const int INF = int(1e9);

array<bool, MAX> visited;
array<int, MAX> dist;
set<int> proibido;

int bfs(int source, int dest)
{
    int ans = INF;
    queue<int> q;

    q.push(source);
    dist[source] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == dest)
        {
            ans = min(dist[cur], ans);
        }

        if (!visited[cur])
        {
            visited[cur] = true;

            if (cur * 3 <= 100000)
            {
                if (dist[cur * 3] == 0)
                {
                    q.push(cur * 3);
                    dist[cur * 3] = dist[cur] + 1;
                }
            }
            if (cur % 2 == 0 && (cur / 2) > 0)
            {
                if (dist[cur / 2] == 0)
                {
                    q.push(cur / 2);
                    dist[cur / 2] = dist[cur] + 1;
                }
            }

            if (cur * 2 <= 100000)
            {
                if (dist[cur * 2] == 0)
                {
                    q.push(cur * 2);
                    dist[cur * 2] = dist[cur] + 1;
                }
            }

            if (cur + 1 <= 100000)
            {
                if (dist[cur + 1] == 0)
                {
                    q.push(cur + 1);
                    dist[cur + 1] = dist[cur] + 1;
                }
            }
            if (cur - 1 > 0)
            {
                if (dist[cur - 1] == 0)
                {
                    q.push(cur - 1);
                    dist[cur - 1] = dist[cur] + 1;
                }
            }
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int o, d, k, aux;

    while (cin >> o >> d >> k)
    {
        visited.fill(false);
        dist.fill(0);
        proibido.clear();

        if (o == 0)
        {
            break;
        }

        for (int i = 0; i < k; i++)
        {
            cin >> aux;
            // proibido.insert(aux);
            visited[aux] = true;
        }

        int ans = bfs(o, d);

        cout << (ans == INF ? -1 : ans) << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome