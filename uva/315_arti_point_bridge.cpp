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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = int(112);

int Time;
int n;

vi adj[MAX];
array<int, MAX> ap;
array<int, MAX> parent;
array<int, MAX> disc;
array<int, MAX> low;

int dfsAP(int u, int p)
{
    int children = 0;
    low[u] = disc[u] = ++Time;
    for (int &v : adj[u])
    {
        if (v == p)
            continue; // we don't want to go back through the same path.
                      // if we go back is because we found another way back
        if (!disc[v])
        { // if V has not been discovered before
            children++;
            dfsAP(v, u); // recursive DFS call
            if (disc[u] <= low[v])
            { // condition #1
                ap[u] = 1;
            }
            low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
        }
        else
        {
            // if v was already discovered means that we found an ancestor
            low[u] = min(low[u], disc[v]); // finds the ancestor with the least discovery time
        }
    }
    return children;
}

void AP()
{
    ap.fill(0);
    low.fill(MAX);
    disc.fill(0);
    Time = 0;
    for (int u = 1; u <= n; u++)
        if (!disc[u] && adj[u].size() >= 1)
        {
            ap[u] = dfsAP(u, u) > 1; // condition #2
            return;
        }
}

vector<pair<int, int>> br;

int dfsBR(int u, int p)
{
    low[u] = disc[u] = ++Time;
    for (int &v : adj[u])
    {
        if (v == p)
            continue; // we don't want to go back through the same path.
                      // if we go back is because we found another way back
        if (!disc[v])
        {                         // if V has not been discovered before
            dfsBR(v, u);          // recursive DFS call
            if (disc[u] < low[v]) // condition to find a bridge
                br.push_back({u, v});
            low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
        }
        else                               // if v was already discovered means that we found an ancestor
            low[u] = min(low[u], disc[v]); // finds the ancestor with the least discovery time
    }
    return 0;
}

void BR()
{
    br.clear();
    low.fill(0);
    disc.fill(0);
    Time = 0;
    for (int u = 1; u <= n; u++)
        if (!disc[u] && adj[u].size() >= 1)
            dfsBR(u, u);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n && n != 0)
    {
        string bf;
        getline(cin, bf);
        while (true)
        {
            getline(cin, bf);
            istringstream is(bf);
            vi v((istream_iterator<int>(is)), istream_iterator<int>());

            if (v.size() == 1 && v.front() == 0)
            {
                break;
            }

            // creating adjacency list
            int par = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (i == 0)
                {
                    par = v[i];
                }
                else
                {
                    adj[par].pb(v[i]);
                }
            }
        }

        AP();
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ap[i] >= 1) {
                ans++;
            }
        }

        cout << ans << '\n';

        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome