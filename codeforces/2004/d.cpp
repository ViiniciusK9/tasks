#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

const int MAX = 2e5 + 10;
const int INF = 1e9 + 7;
vector<ii> adj[MAX];
array<string, MAX> a;
map<char, vector<int>> ma;
array<ll, MAX> dist;
array<bool, MAX> vis;

ll bfs(int s, int t)
{
    vis[s] = true;
    priority_queue<ii> q;
    for (auto el : ma[a[s][0]])
    {
        if (el != s)
        {
            q.push({-abs(s - el), el});
        }
    }

    for (auto el : ma[a[s][1]])
    {
        if (el != s)
        {
            q.push({-abs(s - el), el});
        }
    }

    while (!q.empty())
    {
        ii cur = q.top();
        q.pop();

        vis[cur.second] = true;

        for (auto el : ma[a[cur.second][0]])
        {
            if (el == t)
            {
                return abs(cur.first) + abs(el - cur.second);
            }
            if (el != cur.second && !vis[el])
            {
                q.push({-(abs(cur.first) + abs(el - cur.second)), el});
            }
        }

        for (auto el : ma[a[cur.second][1]])
        {
            if (el == t)
            {
                return abs(cur.first) + abs(el - cur.second);
            }
            if (el != cur.second && !vis[el])
            {
                q.push({-(abs(cur.first) + abs(el - cur.second)), el});
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ma.clear();
        int n, q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            ma[a[i][0]].pb(i);
            ma[a[i][1]].pb(i);
        }

        while (q--)
        {
            int x, y;
            cin >> x >> y;

            if (a[x][0] == a[y][0] || a[x][1] == a[y][0] || a[x][0] == a[y][1] || a[x][1] == a[y][1])
            {
                cout << abs(x - y) << '\n';
            }
            else
            {
                vis.fill(false);
                ll ans = bfs(x, y);
                cout << ans << '\n';
            }

            
        }

    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome