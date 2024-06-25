#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = int(1e4 + 10);

vector<pii> vp;
int n, m, k;
vector<int> adj[MAX];
bool visited[MAX];

bool vizinho(pii a, pii b)
{

    ll d1 = abs(a.first - b.first);
    ll d2 = abs(a.second.first - b.second.first);
    double dist = sqrt((d1 * d1) + (d2 * d2));
    double dis = a.second.second + b.second.second;

    return dis >= dist;
}

bool bfs(int s)
{

    bool l1, l2, l3, l4;
    l1 = l2 = l3 = l4 = false;

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int x = vp[cur].first;
        int y = vp[cur].second.first;
        int s = vp[cur].second.second;

        if (y - s <= 0)
        {
            l1 = true;
        }

        if (y + s >= n)
        {
            l3 = true;
        }

        if (x + s >= m)
        {
            l2 = true;
        }

        if (x - s <= 0)
        {
            l4 = true;
        }

        if (l1 && (l3 || l4))
        {
            return true;
        }

        if (l2 && (l3 || l4))
        {
            return true;
        }

        for (auto ng : adj[cur])
        {
            if (!visited[ng])
            {
                visited[ng] = true;
                q.push(ng);
            }
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    int x, y, s;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y >> s;
        vp.pb({x, {y, s}});
    }

    for (int i = 0; i < k; i++)
    {
        pii at = vp[i];
        for (int j = 0; j < k; j++)
        {
            if (i == j)
                continue;
            pii cur = vp[j];

            if (vizinho(at, cur))
            {
                adj[i].pb(j);
            }
        }
    }
    bool ans;
    for (int i = 0; i < k; i++)
    {
        //memset(visited, false, sizeof(visited));
        if (visited[i] == false) {
            ans = bfs(i);
        }
        
        if (ans)
        {
            break;
        }
    }

    if (ans)
    {
        cout << "N\n";
    }
    else
    {
        cout << "S\n";
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome